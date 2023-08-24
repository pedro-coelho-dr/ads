#include <stdio.h>
typedef struct Node{
      int valor;
      struct Node *prox;
} Node;

void inserir(Node **head, int valor);
void imprimir(Node *head);
int tamanho(Node *head);
int remover(Node **head);

int main(void) {   
  
  //Criação do nó
  Node *head = NULL;
  //impressão da lista
  imprimir(head);
   
  //tamanho da lista
  printf("\nTamanho: %d\n", tamanho(head));

  //inserção de nós
  inserir(&head, 16);
  imprimir(head);
  
  inserir(&head, 45);
  inserir(&head, 32);
  inserirFinal(&head, 96);

  printf("\nFIND-> %d\n", find(&head, 96));

  //impressão da lista
  imprimir(head);
  
  //tamanho da lista
  printf("\nTamanho: %d\n", tamanho(head));
  imprimir(head);

  //remocao de um elemento
  int removido = 0;
  removido = remover(&head);
  printf("\nValor removido: %d", removido);

  //remoco de mais um elemento
  removido = remover(&head);
  printf("\nValor removido: %d\n", removido);
  
  imprimir(head);
   
  return 0;
}

//insere um novo nó na lista
void inserir(Node **head, int n) {
  Node *novo = (Node *) malloc(sizeof(Node));
  if (novo != NULL){
    novo->valor = n;
    novo->prox = *head;
    *head = novo;
  }
}

//imprime toda a lista
void imprimir(Node *head) {
    while(head != NULL) {
      printf("%d -> ",head->valor);
      head = head->prox;
    }
    printf("NULL\n");
}

//retorna o tamanho da lista
int tamanho(Node *head) {
   int contador = 0;
   while( head != NULL) {
      head = head->prox;
      contador++;
   }
   return(contador);
}

//Remove o elemento na primeira posição
int remover(Node **head) {
  Node *temp;
  int valor;
  valor = (*head)->valor;
  if(head != NULL){
    temp = *head;  
    *head = (*head)->prox;
    free(temp);
  }
  return valor;
}


//find

int find(Node **head, int valor){
  Node *temp;
  temp = *head;
  while(temp!= NULL){
    if(temp->valor==valor){
      return 1;
    }
    temp = temp->prox;
  }
  return 0;
}

//inserirFinal

void inserirFinal(Node **head, int valor){
  Node *novo = (Node *) malloc(sizeof(Node));
  Node *temp;
  if(novo!=NULL){
    novo->valor=valor;
    novo->prox =NULL;
    if(*head==NULL){
      *head = novo;
    }else{
      temp = *head;
      while(temp->prox != NULL){
        temp = temp->prox;
      }
      temp->prox = novo;
    }
  }
}


//removerFinal
int removerFinal(Node **head){
  Node *temp;
  int valor;
  if(*head!=NULL){
    if((*head)->prox == NULL){
      valor = (*head)->valor;
      free(*head);
      *head = NULL;
    }else{
      temp= *head;
      while(temp->prox->prox != NULL){
        temp = temp->prox;
      }
      valor = temp->prox->valor;
      free(temp->prox);
      temp->prox = NULL;
    }
  }
  return valor;
}