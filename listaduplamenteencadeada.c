#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* O struct contém um número inteiro que é o dado em si do referido nó - no caso um exemplo, mas pode ser outros dados também.
Dentro do struct há ponteiros para mais dois novos structs do mesmo tipo - o próximo e o anterior -. 
Formando uma lista em que cada nó sabe o endereço do próximo e do anterior.*/


typedef struct Node{
    int valor;
    struct Node *prox;
    struct Node *ant;
} Node; 


int antesDepois(Node **head, int valor) {
    Node *temp;
    temp = *head;
    int contadorA = 0;
    int contadorB = 0;
    while(temp->valor!=valor){   
        contadorA++;
        temp = temp->prox;
    }

    while(head!=) {
        head = head->prox;
        contador++;
6.  }
7.  return 
8.}



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