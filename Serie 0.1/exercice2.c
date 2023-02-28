#include<stdio.h>

int main(){
    int a, b;
    for(a = 1; a<= 12; a++){
        printf("\nTable de multiplication de %d:\n", a);
        for(b = 1; b<= 12; b++){
            printf("%3d x %3d = %3d\n", a, b, a * b);
        }
    }
    return 0;
}