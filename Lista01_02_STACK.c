#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *next;
} Node;

void push(Node **top);
void pop(Node **top);

void push(Node **top) {
    Node *novo = (Node *)malloc(sizeof(Node));
    if (novo!=NULL){
        novo->next = *top;
        *top = novo;
    }
}

void pop(Node **top) {
    Node *temp;
    if (*top!=NULL){
        temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    while (N!=0){
        N--;
        int count = 0;
        char input[1001];
        scanf("%s", input);
        
        Node *top = NULL;
        for (int i=0; input[i]!='\0'; i++) {
            if(input[i]=='<'){
                push(&top);
            }else if(input[i]=='>' && top!=NULL){
                pop(&top);
                count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}