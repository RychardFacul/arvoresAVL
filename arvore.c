#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    int fb;
    int altura;
    struct No* esquerda;
    struct No* direita;
    
}No;

No* inserirNo(No* raiz, int valor);
void balancear(No* raiz);
int alturaNo(No* raiz);

No* novoNo(int valor);

int main()
{
    return 0;
}

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

void balancear(No* raiz)
{
    // TODO
}

int alturaNo(No* raiz)
{
    // TODO
}

No* inserirNo(No* raiz, int valor)
{
    if (raiz) {
        return novoNo(valor);
    }

    if (valor > raiz->valor) {
        raiz->direita = inserirNo(raiz->direita, valor);
    }
    else if (valor < raiz->valor) {
        raiz->esquerda = inserirNo(raiz->esquerda, valor);
    }
    else {
        printf("O valor já existe nesta Arvore");
    }

    int ae = alturaNo(raiz->esquerda);
    int ad = alturaNo(raiz->direita);

    raiz->altura = (ae > ad? ae: ad) + 1;
    balancear(raiz);

    return raiz;
}