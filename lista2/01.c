#include <stdio.h>
#include <stdlib.h>

typedef struct circleNode {
    int id;
    struct circleNode* next;
    struct circleNode* prev;
} circleNode;

typedef struct queueNode {
    int id;
    int politico;
    struct queueNode* next;
} queueNode;


void createCircle(circleNode **head, circleNode **tail, int id) {
  circleNode *novo = (circleNode*)malloc(sizeof(circleNode));  
  novo->id = id;
  
  if(*head==NULL){
    *head = novo;
    *tail = novo;
    novo->prev = *head;
    novo->next = *head;
  }else{
    novo->next = *head;
   
    novo->prev = *tail;
    (*tail)->next = novo;
    (*head)->prev = novo;
    *tail = novo;
  }
}

void findCandidatos(circleNode **head, circleNode **tail, int k, int m, int *candidato1, int *candidato2) {
    for (int i = 1; i < k; i++) {
        *head = (*head)->next;
    }
    for (int i = 1; i < m; i++) {
        *tail = (*tail)->prev;
    }

    *candidato1 = (*head)->id;
    *candidato2 = (*tail)->id;
    *head = (*head)->next;
    *tail = (*tail)->prev;
}

void addQueue(queueNode **queueHead, int id, int politico) {
    queueNode *novo = (queueNode*)malloc(sizeof(queueNode));
    novo->id = id;
    novo->next = NULL;
    novo->politico = politico;
  
    if (*queueHead==NULL) {
        *queueHead = novo;
    }else{
        queueNode *temp = *queueHead;
        while (temp->next!=NULL) {
            temp = temp->next;
        }
        temp->next = novo;
    }
}

void removeCircle(circleNode **head, circleNode **tail, int id) {
    circleNode *temp = *head;
    if (temp==NULL){
        return;
    }
    do{
        if (temp->id == id) {
            if (temp->next == temp){
                *head = NULL;
                *tail = NULL;
            } else {
                if (temp == *head) {
                    *head = temp->next;
                    (*tail)->next = *head;
                    (*head)->prev = *tail;
                }
                else if (temp == *tail) {
                    *tail = temp->prev;
                    (*tail)->next = *head;
                    (*head)->prev = *tail;
                } else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
            }
            free(temp);
            return;
        }
        temp=temp->next;
    }while (temp != *head);
}

void printQueue(queueNode *queueHead) {
    queueNode *temp = queueHead;
    while(temp!=NULL) {
        if (temp->politico) {
            printf("%3d", temp->id);
            temp = temp->next;
            if (temp){
                printf(",");
            }
        } else {
            printf("%3d", temp->id);
            temp = temp->next;
            if (temp){
                printf("%3d", temp->id);
                temp = temp->next;
            }
            if (temp){
                printf(",");
            }
        }
    }
    printf("\n");
}


int main() {
    int N, k, m;
    while (1) {
        fscanf(stdin, "%d %d %d", &N, &k, &m);
        if (N == 0 && k == 0 && m == 0) {
            break;
        }
        queueNode *queueHead = NULL;
        
        circleNode *head = NULL;
        circleNode *tail = NULL;
        //criação do circle
        for (int i = 1; i <= N; i++) {
            createCircle(&head, &tail, i);
        }
        while (head!=NULL){
            //identificação
            int candidato1, candidato2;
            findCandidatos(&head, &tail, k, m, &candidato1, &candidato2);
            //guardar em queue e remover do circle
            if (candidato1==candidato2){
                addQueue(&queueHead, candidato1, 1);
                removeCircle(&head, &tail, candidato1);
            }else{
                addQueue(&queueHead, candidato1, 0);
                addQueue(&queueHead, candidato2, 0);
                removeCircle(&head, &tail, candidato1);
                removeCircle(&head, &tail, candidato2);
            }
        }
        // printar queue
        printQueue(queueHead);
        
    }
    return 0;
}
