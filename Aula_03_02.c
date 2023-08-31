#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode {
    int numero;
    struct QueueNode *prox;
} QueueNode;

typedef struct StackNode {
    int valor;
    struct StackNode *prox;
} StackNode;

void enqueue(QueueNode **head, QueueNode **tail, int n);
void push(StackNode **top, int a);
void printQueue(QueueNode *head);
void printStack(StackNode *top);

int main() {

    //A
    QueueNode *FL1_head = NULL;
    QueueNode *FL1_tail = NULL;
    QueueNode *FL2_head = NULL;
    QueueNode *FL2_tail = NULL;
    StackNode *PL1_top = NULL;

    //B e C
    for (int i=0; i<10; i++) {
        enqueue(&FL1_head, &FL1_tail, i+1);
        enqueue(&FL2_head, &FL2_tail, i+11); 
    }

    //D

    QueueNode *tempFL1 = FL1_head;
    QueueNode *tempFL2 = FL2_head;

    while (tempFL1!=NULL) {
        push(&PL1_top, tempFL1->numero);
        tempFL1 = tempFL1->prox;
    }

    while (tempFL2 != NULL) {
        push(&PL1_top, tempFL2->numero);
        tempFL2 = tempFL2->prox;
    }

    //E
    printf("FL1: ");
    printQueue(FL1_head);

    printf("\nFL2: ");
    printQueue(FL2_head);

    printf("\nPL1: ");
    printStack(PL1_top);
    printf("\n\nFIM\n");
}

void enqueue(QueueNode **head, QueueNode **tail, int n) {
    QueueNode *novo=(QueueNode *)malloc(sizeof(QueueNode));
    if (novo!=NULL){
        novo->numero=n;
        novo->prox=NULL;
        if(*head==NULL){
            *head=novo;
            *tail=novo;
        }else{
            (*tail)->prox=novo;
            *tail=novo;
        }
    }
}

void push(StackNode **top, int a) {
    StackNode *novo = (StackNode *)malloc(sizeof(StackNode));
    if (novo!=NULL) {
        novo->valor=a;
        novo->prox=*top;
        *top=novo;
    }
}

void printQueue(QueueNode *head) {
    while (head!=NULL) {
        printf("%d -> ", head->numero);
        head = head->prox;
    }
}

void printStack(StackNode *top) {
    while (top!=NULL) {
        printf("%d -> ", top->valor);
        top = top->prox;
    }
}