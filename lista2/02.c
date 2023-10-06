#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char nome[31];
    int valor;
    struct node *next;
    struct node *prev;
} Node;

int main() {
    int N;

    while (1) {
        scanf("%d", &N);
        if (N==0) break;

        Node *head = NULL;
        Node *aux2 = NULL;

        for (int i=0; i<N; i++) {
            Node *new = malloc(sizeof(Node));
            scanf("%s %d", new->nome, &new->valor);
            new->next = NULL;
            new->prev = NULL;

            if (head==NULL){
                new->next = new;
                new->prev = new;
                head = new;
                aux2 = head;
            }else{
                new->next=aux2;
                aux2->prev=new;
                head->next=new;
                new->prev=head;
                aux2=new;
            }
        }

        Node *tail = head->prev;

        if (N==1) {
            printf("Vencedor(a): %s\n", head->nome);
            free(head);
            continue;
        }

        Node *aux = head;
        int value = head->valor;
        int count = (head->valor)-1;
        if (value%2==0) {
            aux = aux->next;
        }else{
            aux = aux->prev;
        }
        while (head!=tail) {
            if (value%2==0){
                while(count>0){
                    aux=aux->next;
                    count--;
                }
            }else{
                while (count>0) {
                    aux=aux->prev;
                    count--;
                }
            }
            Node *delete = aux;
            value = delete->valor;
            count = (delete->valor)-1;

            if (value%2==0) {
                aux = aux->next;
            }else{
                aux = aux->prev;
            }
            if (delete==head) {
                head = delete->next;
            }
            if (delete==tail) {
                tail = delete->prev;
            }

            delete->prev->next = delete->next;
            delete->next->prev = delete->prev;

            free(delete);
        }
        printf("Vencedor(a): %s\n", head->nome);
        free(head);
    }
    return 0;
}