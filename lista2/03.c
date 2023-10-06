#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct country {
    char nome[31];
    int ouro;
    int prata;
    int bronze;
    struct country *next;
    struct country *prev;
} Country;

void selectionSort(Country **head) {
    Country *i, *j, *menor;

    for (i=*head;i->next; i=i->next) {
        menor = i;
        for (j=i->next; j; j=j->next) {
            int cmp = 0;
            if(j->ouro > menor->ouro){
                cmp=1;
            }else if (j->ouro == menor->ouro){
                if (j->prata > menor->prata){
                    cmp=1;
                } else if (j->prata == menor->prata){
                    if (j->bronze > menor->bronze) {
                        cmp=1;
                    } else if(j->bronze == menor->bronze){
                        cmp = strcmp(j->nome, menor->nome);
                        if (cmp<0) {
                            cmp=1;
                        }else{
                            cmp=0;
                        }
                    }
                }
            }
            if (cmp) {
                menor = j;
            }
        }

        if (menor!=i) {
            char temp_name[31];
            int temp_ouro, temp_prata, temp_bronze;

            strcpy(temp_name, i->nome);
            temp_ouro = i->ouro;
            temp_prata = i->prata;
            temp_bronze = i->bronze;

            strcpy(i->nome, menor->nome);
            i->ouro = menor->ouro;
            i->prata = menor->prata;
            i->bronze = menor->bronze;

            strcpy(menor->nome, temp_name);
            menor->ouro = temp_ouro;
            menor->prata = temp_prata;
            menor->bronze = temp_bronze;
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    Country *head = NULL;
    Country *aux = NULL;

    if (N==0){
        return 0;
    }
    if (N==1){
        Country *new = malloc(sizeof(Country));
        scanf("%s %d %d %d", new->nome, &new->ouro, &new->prata, &new->bronze);
        printf("%s %d %d %d", new->nome, new->ouro, new->prata, new->bronze);
        free(new);
        return 0;
    }

    for (int i=0;i<N;i++) {
        Country *new = malloc(sizeof(Country));
        scanf("%s %d %d %d", new->nome, &new->ouro, &new->prata, &new->bronze);
        if (head==NULL) {
            new->next = NULL;
            new->prev = NULL;
            head = new;
        }else{
            aux = head;
            aux->prev = new;
            head = new;
            head->next = aux;
            head->prev = NULL;
        }
    }

    selectionSort(&head);

    Country *temp = head;
    while (temp != NULL) {
        printf("%s %d %d %d\n", temp->nome, temp->ouro, temp->prata, temp->bronze);
        temp = temp->next;
    }
    return 0;
}

/* tentei fazer ordenando um a um, mas nao deu certo, 
mas mantive essa versão de bubblesortv2 aqui só pra referencia
ela muda os structs de lugar, em vez de copiar os valores

void bubbleSortV2(Country **head){
    int troca;
    Country *aux1;
    Country *aux2 = NULL;
    do {
        troca = 0;
        aux1 = *head;
        while (aux1->next != aux2) {
            if (strcmp(aux1->nome, aux1->next->nome) > 0) {
                Country *temp = aux1->next;
                aux1->next = temp->next;
                if (temp->next != NULL) {
                    temp->next->prev = aux1;
                }
                temp->prev = aux1->prev;
                aux1->prev = temp;
                temp->next = aux1;
                if (temp->prev != NULL) {
                    temp->prev->next = temp;
                }else{
                    *head = temp;
                }
                troca = 1;
            }else{
                aux1 = aux1->next;
            }
        }
        aux2 = aux1;
    }while (troca);
} */