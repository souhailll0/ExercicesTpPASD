#include<stdio.h>
#include<stdlib.h>

typedef struct noeud{
    int valeur;
    struct noeud *suivant;
}noeud;

noeud* ajouter_debut(noeud* tete){
    noeud* n = malloc(sizeof(noeud));
    printf("Donner la valeur: ");
    scanf("%d", &n->valeur);
    n->suivant = tete;
    return n;
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
void afficher(noeud*tete){
    while(tete!= NULL){
        printf("%d\n", tete->valeur);
        tete = tete->suivant;
    }
}
int main(){
    noeud* tete = NULL;
    tete = ajouter_debut(tete);
    tete = ajouter_debut(tete);
    afficher(tete);
    return 0;
}