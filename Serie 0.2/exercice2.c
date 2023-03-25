#include<stdio.h>
#include<stdlib.h>

typedef struct noeud{
    int valeur;
    struct noeud *suivant;
}noeud;

noeud* inserer(noeud* tete){
    noeud* New = NULL;
    New = malloc(sizeof(noeud));
    printf("Donner la valeur: ");
    scanf("%d", &New->valeur);
    New->suivant = tete;
    return New;
}

noeud* insererQueue(noeud* tete){
    noeud* n = malloc(sizeof(noeud));
    printf("Donner la valeur: ");
    scanf("%d", &n->valeur);
    n->suivant = NULL;
    if(tete == NULL){
        tete = n;
    }else{
        noeud* aide = tete;
        while(aide->suivant != NULL){
            aide = aide->suivant;
        }
        aide->suivant = n;
    }
    return tete;
}
void afficher(noeud* tete){
    if(tete){
        printf("%d\n", tete->valeur);
        afficher(tete->suivant);
    }
}
int compter(noeud* tete){
    int c = 0;
    while(tete != NULL){
        c++;
        tete = tete->suivant;
    }
    return c;
}

int count(noeud* tete){

}

void main(){
    noeud* tete = NULL;
    tete = insererQueue(tete);
    afficher(tete);
}