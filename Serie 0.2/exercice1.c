#include<stdio.h>
#include<stdlib.h>

typedef struct noeud{
    int valeur;
    struct noeud *suivant;
}noeud;

int recherche(noeud* tete, int v){
    noeud *p= tete;
    while(p!= NULL){
        if(p->valeur == v) return 1;
        p = p->suivant;
    }
    return 0;
}

noeud* ajouter_debut(noeud* tete){
    noeud* p = malloc(sizeof(noeud));
    printf("Donner la valeur: ");
    scanf("%d", &p->valeur);
    p->suivant = tete;
    return p;
}

void ajouter_fin(noeud* tete){
    noeud* n = malloc(sizeof(noeud));
    printf("Donner la valeur: ");
    scanf("%d", &n->valeur);
    noeud* p = tete;
    while(p->suivant != NULL){
        p = p->suivant;
    }
    p->suivant = n;
}
noeud* supprimer_debut(noeud* tete){
    noeud* aide = tete->suivant;
    free(tete);
    return aide;
}

void afficher(noeud * tete){
    noeud *aide = tete;
    while(aide!= NULL){
        printf("%d\n", aide->valeur);
        aide = aide->suivant;
    }
}

int main(){
    noeud* tete = NULL;
    int i;
    // teste d'ajout de 5 noeuds 
    for( i = 0; i < 5; i++){
        tete = ajouter_debut(tete);
        afficher(tete);
    }

    tete = supprimer_debut(tete);
    afficher(tete);
    
    return 0;
}