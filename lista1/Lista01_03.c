#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno{
    int nota;
    int ordem;
    int ordem_final;
    struct Aluno* next;
    struct Aluno* prev;
}Aluno;

void addAluno(Aluno** head, int nota, int ordem) {
    Aluno* novo = (Aluno*)malloc(sizeof(Aluno));
    novo->nota = nota;
    novo->ordem = ordem;
    novo->next = NULL;
    novo->prev = NULL;

    if (*head==NULL){
        *head = novo;
    } else if (nota >= (*head)->nota) {
        novo->next = *head;
        (*head)->prev = novo;
        *head = novo;
    } else {
        Aluno* temp = *head;
        while(temp->next != NULL && temp->next->nota > nota){
            temp = temp->next;
        }
        novo->next = temp->next;
        novo->prev = temp;
        if(temp->next!=NULL){
            temp->next->prev = novo;
        }
        temp->next = novo;
    }
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i=0; i<N; i++) {
        int M;
        scanf("%d", &M);
        Aluno* head = NULL;
        for (int j=1; j<=M; j++) {
            int nota;
            scanf("%d", &nota);
            addAluno(&head, nota, j);
        }
        int ordem_final=1;
        Aluno* temp = head;
        while (temp!=NULL) {
            temp->ordem_final = ordem_final;
            ordem_final++;
            temp = temp->next;
        }

        int count = 0;
        temp = head;
        while (temp!=NULL) {
            if (temp->ordem==temp->ordem_final){
                count++;
            }
            temp = temp->next;
        }
        printf("%d\n", count);
    }

    return 0;
}
