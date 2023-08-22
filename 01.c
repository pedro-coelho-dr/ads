#include <stdio.h>

void calcular_media(int *A, int *B){
    int media=(*A+*B)/2;
    int modulo=(*A+*B)%2;
    if (*A>*B){
        *B=media;
        *A=modulo;
    }else{
        *A=media;
        *B=modulo;
    };
}
int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    calcular_media(&a,&b);
    printf("%d %d", a, b);
}