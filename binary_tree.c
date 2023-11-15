#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node *left;
    struct Node *right;
} Node;


int altura(Node *raiz) {
    if (raiz==NULL) {
        return -1;
    }
    else {
        int ae = altura(raiz->left);
        int ad = altura(raiz->right);
        return (ae>ad) ? ae+1 : ad+1;
    }
}

int profundidade(Node *raiz, int valor, int nivel) {
    if (raiz == NULL) {
        return -1;
    }
    if (raiz->valor == valor) {
        return nivel;
    }

    int profundidadeLeft = profundidade(raiz->left, valor, nivel+1);
    if (profundidadeLeft != -1) {
        return profundidadeLeft;
    }

    int profundidadeRight = profundidade(raiz->right, valor, nivel + 1);
    return profundidadeRight;
}


Node* create(int valor) {
    Node* novo = (Node*) malloc(sizeof(Node));
    novo->valor = valor;
    novo->left = NULL;
    novo->right = NULL;
    return novo;
}

int main() {

    Node *raiz = create(1);
    raiz->left = create(2);
    raiz->right = create(3);
    raiz->left->left = create(4);
    raiz->left->right = create(5);
    raiz->right->right = create(6);

    printf("Altura: %d\n", altura(raiz->left->right));

    printf("profundidade 1: %d\n", profundidade(raiz, 1, 0));
    printf("profundidade 4: %d\n", profundidade(raiz, 4, 0));
    printf("profundidade 6: %d\n", profundidade(raiz, 6, 0));

    return 0;
}