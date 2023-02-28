#include<stdio.h>
#define MAX 10

int somme(int T[], int n){
    int s = 0;
    for (int i = 0; i < n; i++){
        s += T[i];
    }
    return s;
}
float moyenne(int T[], int n){
    return (float) somme(T, n) / n;
}
void triC(int T[], int n){
    int tmp;
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if(T[i] > T[j]){
                tmp = T[i];
                T[i] = T[j];
                T[j] = tmp;
            }
        }
    }
}

void triD(int T[], int n){
    int tmp;
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if(T[i] < T[j]){
                tmp = T[i];
                T[i] = T[j];
                T[j] = tmp;
            }
        }
    }
}

void afficher(int T[], int n){
    for (int i = 0; i < n; i++){
        printf("\nT[%d] =  %d", i, T[i]);
    }
}
int main(){
    // Question 1
    int T[MAX], n, i;
    do{
        printf("\nEntrer la taille du tableau: ");
        scanf("%d", &n);
    }while(n > 10 || n < 1);
    
    // Question 2
    for ( i = 0; i < n; i++){
        printf("\nSaisi la valeur de T[%d]: ", i);
        scanf("%d", &T[i]);
    }

    // Question 3
    printf("La somme est: %d\n", somme(T, n));

    // Question 4
    printf("La moyenne est: %.2f\n", moyenne(T, n));

    // Question 5
    printf("\nOrdre Croissant: ");
    triC(T, n);
    // Question 6
    afficher(T, n);

    // Question 5
    printf("\nOrdre Decroissant: ");
    triD(T, n);
    // Question 6
    afficher(T, n);


    printf("\n");
    return 0;
}