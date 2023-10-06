#include <stdio.h>
#define LEN 7

int main(void) {
    int inicio, final, n, v[LEN];
    
    printf("Digite os 5 PRIMEIROS numeros de sua matricula:");
    scanf("%d", &inicio);
    printf("Digite os 3 ULTIMOS numeros de sua matricula:");
    scanf("%d", &final);
    
    n = inicio * final;

    for(int i=0 ; i < LEN ; i++) {
        v[i] = 1 + ( rand() % n/100);
    }
    
    printf("\nSeu array:\n[ ");
    for(int i=0 ; i < LEN ; i++) {
        printf(" %d ",v[i]);
    }
    printf(" ]");
 
  return 0;
}