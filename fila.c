#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
      int id;
      char nome[30];
      struct Node *prox;
} Node;

void enqueue(Node **head, Node **tail, char nome, int id);
int dequeue(Node **head, Node **tail);
void printFila(Node *head);
int tamanho(Node *head);

int main() {

  Node *head = NULL;
  Node *tail = NULL;
  int valor;

  enqueue(&head, &tail, "Pedro", 44);
  enqueue(&head, &tail, "Francisco", 87);
  enqueue(&head, &tail, "Joana", 23);

  printFila(head);

  printf("\nTamanho da fila: %d\n", tamanho(head));

  int n = dequeue(&head, &tail);
  printf("\nO valor retirado foi %d\n\n", n);

  printFila(head);

  return 0;
}

// enfileira nó
void enqueue(Node **head, Node **tail, char nome, int id) {
  Node *novo = (Node *)malloc(sizeof(Node));

  if (novo != NULL) {
    novo->id = id;
    strncpy(novo->nome, nome);
    novo->prox = NULL;
    
    if (*head == NULL) {
      *head = novo;
      *tail = novo;
    } else {
      (*tail)->prox = novo;
      *tail = novo;
    }
  } 
}

// retira elemento da fila
int dequeue(Node **head, Node **tail) {
  Node *aux;
  int n;
  if ((*head) != NULL) {
    n = (*head)->id;
    
    aux = *head;
    *head = (*head)->prox;
    free(aux);

    if ((*head) == NULL) 
      *tail = NULL;
  }
  return n;
}

// imprime a fila
void printFila(Node *head) {
  while (head != NULL) {
    printf("%d-> ", head->id);
    printf("%s", head->nome);
    head = head->prox;
  }
  printf("NULL \n");
}

// retorna o tamanho da fila
int tamanho(Node *head) {
  int cont = 0;
  while (head != NULL) {
    cont++;
    head = head->prox;
  }
  return cont;
}