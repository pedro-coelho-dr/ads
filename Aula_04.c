#include <stdio.h>
#include <stdlib.h>
/* O struct contém um número inteiro que é o dado em si do referido nó - no caso um int, mas pode ser outros dados e datatypes também.
Dentro do struct há ponteiros para mais dois novos structs do mesmo tipo - o próximo e o anterior -. 
Formando uma lista em que cada nó sabe o endereço do próximo e do anterior.*/

typedef struct Node{
  int valor;
  struct Node *prox;
  struct Node *ant;
} Node; 

void inserirFinal(Node **head, int valor);
void removerFinal(Node **head);

/* 
1- criar um novo node com alocação de memória 
2A- Adiciona o valor dado no parametro da função
2B- Setta o proximo node para NULL (já que ele será o ultimo node da lista - o contrário de inserir no começo)
3-Verifica se a lista está vazia:
3A- Se sim, setta o node anterior para NULL e aponta o endereço de *head para o node.(ele será o unico da lista).
3B1- Se não, cria-se um endereço temporário para a head para andar na lista sem perder a referencia do head.
3B2- Ao chegar no ultimo elemento,  setta o proximo node dele para novo.
3B3- E setta o anterior do Novo Node para o node temporario/ultimo.
*/
void inserirFinal(Node **head, int valor) {
    Node *novo= (Node*)malloc(sizeof(Node));
    if (novo!=NULL) {
        novo->valor=valor;
        novo->prox=NULL;

        if (*head==NULL) {
            novo->ant=NULL;
            *head=novo;
        }else{
            Node *temp = *head;
            while (temp->prox != NULL) {
                temp =temp->prox;
            }
            temp->prox = novo;
            novo->ant = temp;
        }
    }
}

/*
1 - Setta um node temporario para o head, para andar na lista sem perder a referencia da head.
2 - Checa se esse node não é o único da lista, se for remove ele da lista, settando o head para null.
3 - Se não, anda na lista até o ultimo node e setta o proximo do penultimo node (o anterior) para NULL
3- e libera a memoria de temp
*/

void removerFinal(Node **head) {
    Node *temp = *head;
    if (temp!=NULL){
        if (temp->prox==NULL) {
            *head = NULL;
        }else{
            while (temp->prox!=NULL) {
                temp = temp->prox;
            }
            temp->ant->prox = NULL;
        }
        free(temp);
    }
}

//SEARCH E DIVIDE
void searchAndDestroy(Node *head, int elemento) {
    Node *temp=head;
    int countA = 0;
    int countB = 0;
    while (temp!=NULL){
        if (temp->valor==elemento) {
            break;
        }
        countA++;
        temp = temp->prox;
    }
    if (temp==NULL) {
        printf("\n[NULL]\n\n");
        return;
    }
    temp = temp->prox;
    while(temp!=NULL){
        countB++;
        temp=temp->prox;
    }
    printf("%d <-> %d\n", countA, countB);
}



int main() {
    Node *head = NULL;
    for (int i=1; i<=10; i++) {
        inserirFinal(&head, i);
    }
    Node *temp = head;
    while (temp!=NULL) {
        printf("%d -> ", temp->valor);
        temp = temp->prox;
    }
    printf("\n");

    searchAndDestroy(head, 11);

}