#include <stdio.h>
#include <stdlib.h>
#include <string.h> // ADD STRING

typedef struct Node{
      int id;
      char nome[30]; // ADD STRING
      struct Node *prox;
} Node;

void enqueue(Node **head, Node **tail, int id, char *nome); // UPDATE ID && ADD NOME
int dequeue(Node **head, Node **tail);
void printFila(Node *head);
int tamanho(Node *head);

int main() {

  Node *head = NULL;
  Node *tail = NULL;
  int valor;

  enqueue(&head, &tail, 44, "Pedro"); // ADD NOME
  enqueue(&head, &tail, 87, "Coelho");
  enqueue(&head, &tail, 23, "Corisco");

  printFila(head);

  printf("\nTamanho da fila: %d\n", tamanho(head));

  int n = dequeue(&head, &tail);
  printf("\nO valor retirado foi %d\n\n", n);

  printFila(head);

  return 0;
}

// enfileira nó
void enqueue(Node **head, Node **tail, int id, char *nome) {
  Node *novo = (Node *)malloc(sizeof(Node));

  if (novo != NULL) {
    novo->id = id;
    strncpy(novo->nome, nome, sizeof(novo->nome)); // COPY NAME
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
    printf("ID: %d / Nome: %s ---> ", head->id, head->nome); // PRINT NOME
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