#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct arv {
    int chave;
    int valor;
    struct arv *esq;
    struct arv *dir;
} Arv;

Arv *inserir(Arv *raiz, int chave, int valor);
int somaArv(Arv *raiz, int chave);
int somaSubArvore(Arv *raiz);
void print_arvore(Arv *raiz);

Arv *inserir(Arv *raiz, int chave, int valor) {
    if (raiz == NULL) {
        raiz = malloc(sizeof(Arv));
        raiz->chave = chave;
        raiz->valor = valor;
        raiz->esq = NULL;
        raiz->dir = NULL;
    } else if (chave < raiz->chave) {
        raiz->esq = inserir(raiz->esq, chave, valor);
    } else if (chave > raiz->chave) {
        raiz->dir = inserir(raiz->dir, chave, valor);
    }
    return raiz;
}

void print_arvore(Arv *raiz) {
    if (raiz != NULL) {
        printf("Chave: %d, Valor: %d\n", raiz->chave, raiz->valor);
        printf("<<\n");
        print_arvore(raiz->esq);
        printf(">>\n");
        print_arvore(raiz->dir);
    }
}

int somaSubArvore(Arv *raiz) {
    if (raiz == NULL) {
        return 0;
    }
    return raiz->valor + somaSubArvore(raiz->esq) + somaSubArvore(raiz->dir);
}

int somaArv(Arv *raiz, int chave) {
    if (raiz == NULL) {
        return 0;
    }
    if (raiz->chave == chave) {
        return somaSubArvore(raiz);
    } else if (chave < raiz->chave) {
        return somaArv(raiz->esq, chave);
    } else {
        return somaArv(raiz->dir, chave);
    }
}

bool print_pais(Arv *raiz, int chave) {
    if (raiz == NULL) {
        return false;
    }
    if (raiz->chave == chave) {
        return true;
    }
    if (print_pais(raiz->esq, chave) || print_pais(raiz->dir, chave)) {
        printf("PAI DE FOLHA: %d - %d\n", raiz->chave, raiz->valor);
        return true;
    }
    return false;
}

int main() {
    Arv *raiz = NULL;
    int chave, valor;

    while (1) {
        printf("Digite a chave (0 para terminar): ");
        scanf("%d", &chave);
        if (chave == 0) {
            break;
        }

        printf("Digite o valor: ");
        scanf("%d", &valor);
        raiz = inserir(raiz, chave, valor);
    }
    printf("------------\n");
    print_arvore(raiz);
    printf("------------\n");

    int chave_soma;
    printf("\nDigite a chave para somar subarvore: ");
    scanf("%d", &chave_soma);
    int soma = somaArv(raiz, chave_soma);
    printf("SOMA = %d\n", soma);
    printf("------------\n");

    int chave_pais;
    printf("\nDigite a chave para imprimir os pais: ");
    scanf("%d", &chave_pais);

    print_pais(raiz, chave_pais);

    return 0;
}
