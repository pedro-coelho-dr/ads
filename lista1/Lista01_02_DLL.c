#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char data;
    struct Node *next;
}Node;

void enqueue(Node **head, Node **tail, char data);
void dequeue(Node **head, Node **tail); 

void enqueue(Node **head, Node **tail, char data){
    Node *novo = (Node *)malloc(sizeof(Node));
    if (novo!=NULL){
        novo->data=data;
        novo->next=NULL;

        if (*head==NULL){
            *head=novo;
            *tail=novo;
        }else{
            (*tail)->next=novo;
            *tail=novo;
        }
    }
}
void dequeue(Node **head, Node **tail){
    Node *temp;

    if (*head!=NULL){
        temp=*head;
        *head=(*head)->next;
        free(temp);
        if (*head==NULL){
            *tail=NULL;
        }
    }
}

int main(){
    int N;
    scanf("%d", &N);

    while(N!=0){
        N--;
        int count=0;
        char input[1001];
        scanf("%s", input);
        Node *head = NULL;
        Node *tail = NULL;

        for (int i=0;input[i]!='\0';i++){
            if(input[i] == '<'){
                enqueue(&head, &tail, input[i]);
            }else if(input[i]=='>' && head!=NULL){
                dequeue(&head, &tail);
                count++;
            }
        }
        printf("%d\n", count);
    }

    return 0;
}