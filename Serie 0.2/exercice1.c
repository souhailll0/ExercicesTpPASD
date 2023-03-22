#include<stdio.h>
#include<stdlib.h>

typedef struct noeud{
    int valeur;
    struct noeud *suivant;
}noeud;

noeud* ajouter_debut(noeud* tete){
    noeud* New = NULL;
    New = malloc(sizeof(noeud));
    printf("Donner la valeur: ");
    scanf("%d", &New->valeur);
    New->suivant = tete;
    return New;
}
noeud* supprimer(noeud*tete){
    if(tete == NULL){
        return NULL;
    }else{
        noeud* A = tete->suivant;
        free(tete);
        return A;
    }
}

noeud* ajouter_fin(noeud* tete){
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

int main(){
    noeud* tete = NULL;
    
    return 0;
}