#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Amigo {
    char nome[50];
    int ordem;
    struct Amigo* next;
}Amigo;

void addAmigo(Amigo** head, char* nome, int ordem){
    Amigo* temp = *head;
    // Checa se o nome ja existe
    while(temp!=NULL){
        if (strcmp(temp->nome, nome)==0) {
            return;
        }
        temp = temp->next;
    }
    // Cria novo node
    Amigo* novo = (Amigo*)malloc(sizeof(Amigo));
    strcpy(novo->nome, nome);
    novo->ordem = ordem;
    novo->next = NULL;
    
    // Add em ordem alfabetica
    if (*head==NULL || strcmp(nome, (*head)->nome)<0){
        novo->next = *head;
        *head = novo;
    }else{
        temp = *head;
        while (temp->next!=NULL && strcmp(nome, temp->next->nome)>0){
            temp = temp->next;
        }
        novo->next = temp->next;
        temp->next =novo;
    }
}

void printAmigos(Amigo* head){
    Amigo* temp = head;
    while (temp!=NULL) {
        printf("%s\n", temp->nome);
        temp = temp->next;
    }
}

void printVencedor(Amigo* head){
    Amigo* temp = head;
    char vencedor[50] = "";
    int maiorNome = 0;
    int menorOrdem = -1;

    while (temp!=NULL){
        int tamanhoNome = strlen(temp->nome);
        if (tamanhoNome>maiorNome || (tamanhoNome==maiorNome && temp->ordem<menorOrdem)){
            strcpy(vencedor, temp->nome);
            maiorNome = tamanhoNome;
            menorOrdem = temp->ordem;
        }
        temp = temp->next;
    }

    printf("\nAmigo do Habay:\n%s\n", vencedor);
}

int main() {
    char nome[50];
    int ordem = 1;
    Amigo* YES = NULL;
    Amigo* NO = NULL;

    while(1){
        scanf("%s", nome);
        if (strcmp(nome, "FIM")==0){
            break;
        }
        
        char opcao[4];
        scanf("%s", opcao);

        if (strcmp(opcao, "YES")==0){
            addAmigo(&YES, nome, ordem);
        } else if(strcmp(opcao, "NO")==0){
            addAmigo(&NO, nome, ordem);
        }
        ordem++;
    }
    printAmigos(YES);
    printAmigos(NO);
    printVencedor(YES);
    return 0;
}
