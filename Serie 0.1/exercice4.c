#include<stdio.h>

int factoriel(int n){
    if (n == 1 || n == 0) return 1;
    return n * factoriel(n-1);
}
int main(){
    int n;
    do{
        printf("Donner un nombre entier positif: ");
        scanf("%d", &n);
    }while(n < 0);
    printf("\n %d! = %d", n, factoriel(n));
    printf("\n");
    return 0;
}