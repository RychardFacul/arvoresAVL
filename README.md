# **Árvore AVL**

Este trabalho consiste em um programa cujo ó intuito é apresentar as funções de criação e manipulação de uma arvore AVL.

Participantes: 

#### Rychard Antony Pereira de Arruda [![logo do github](./imagensREADME/github.svg)](https://github.com/RychardProficional)

<!--
Quem for alterar for alterar o repossitorio coloque o nome nesta parte!
-->

Existem várias formas de se trabalhar com esta Arvores AVL, como tabelas HASH por exemplo. No entanto, algumas funções se encontram em praticamente todas estas formas. Como por exemplo a função de criação de um nó, que não pode faltar quando se fala de qualquer estrutura de programação do tipo Arvore. Este programa terá como foco justamente aquelas funções que caracterizam uma Estrutura como Árvore AVL.

## **Caracteristicas**

## **Funções** 

- #### Criar nó

    Como dito anteriormente, esta é a função que gera um nó, que fara parte de uma arvore AVL, ou dará origem a uma nova. Mas antes de atribuirmos um valor a ele, primeiros precisamos reservar um local na memória do tamanho do nó. Na linguagem C a função que possui esta finalidade se chama `malloc` da biblioteca `<stdlib.h>`.

    #### como utilizamos:

    ```c
    No* no = malloc(sizeof(no));
    ```
    O valor passado como parâmetro da função é o espaço que cera ocupado na memória. Como o que está sendo passado é o retorno de `sizeof(no)`, que é igual ao tamanho da estrutura, o espaço reservado terá exatamente o tamanho necessário para armazenar o novo nó que está sendo criado.

    Após isto, basta inicializar os valores das variáveis que compõem o nó e retorná-lo

    ```c
    No* novoNo(int valor)
    {
        No* no = malloc(sizeof(no));

        no->altura = 0;
        no->fb = 0;
        no->valor = valor;
        no->esquerda = NULL;
        no->direita = NULL;

        return no;
    }
    ```

    Como último detalhe, observe que o `no->valor` diferentemente dos demais, está sendo iniciado com o `valor` que está sendo passado por parâmetro para função. Este é o valor que desejamos armazenar!

- #### Inserir nó:

    Devido a utilização de ponteiros, boa parte das manipulações feitas em arvores AVL ocorrem com a utilização de funções recursivas. A inserção de um novo nó não foge desse padrão. A função de Inserção já no começo tem o caso base:

    ```c
    if (raiz) 
    {
        return novoNo(valor); //caso base
    }
    ```
    <small>*O caso base é o que indica quando uma função recursiva terminou.*</small>

    Após isto, é verificado qual dos lados será inserido o novo nó


    ```c
    if (valor > raiz->valor) {
        raiz->direita = inserirNo(raiz->direita, valor);
    }
    else {
        raiz->esquerda = inserirNo(raiz->esquerda, valor);
    }
    ```

    Uma coisa importante a se levar em consideração, é que se o valor já existe dentro da arvore, na maioria dos casos, não há necessidade de criar um nó para um valor repetido.
    A solução para este problema é bem simples, basta verificar no `else`, se o `valor` é maior que o que existe dentro da raiz.

    ```c
    if (valor > raiz->valor) {
        raiz->direita = inserirNo(raiz->direita, valor);
    }
    else {
        raiz->esquerda = inserirNo(raiz->esquerda, valor);
    }
    else { //Opcional
        printf("O valor já existe nesta Arvore");
    }
    ```

    Desta forma, somente novos valores são incrementados na arvore.