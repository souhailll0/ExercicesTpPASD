
#include<stdio.h>
#include<stdlib.h>

struct noeud{
    int valeur;
    struct noeud* suivant;
};

struct noeud* inserer(struct noeud* tete, int v){
    struct noeud* n = malloc(sizeof(struct noeud));
    n->valeur = v;
    n->suivant = tete;

    return n;
}


void insererQueue(struct noeud* tete, int v){
    struct noeud* n = malloc(sizeof(struct noeud));
    n->valeur = v;
    n->suivant = NULL;
    if(tete == NULL){
        tete = n;
    }else{
        while(tete->suivant!= NULL){
            tete = tete->suivant;
        }
        tete->suivant = n;
    }
}
void afficher(struct noeud* t){
    while(t!=NULL){
        printf("%d\n", t->valeur);
        t = t->suivant;
    }
}
void afficherRecursive(struct noeud* tete){
    if(tete != NULL){
        printf("%d\n", tete->valeur);
        afficherRecursive(tete->suivant);
    }
}
int count(struct noeud*tete){
    int c = 0;
    while(tete!=NULL){
        c++;
        tete = tete->suivant;
    }
    return c;
}
void main(){
    struct noeud* tete = NULL;
    tete = inserer(tete, 5);
    tete = inserer(tete, 6);
    insererQueue(tete, 7);
    insererQueue(tete, 8);
    afficherRecursive(tete);
    printf("Il y a %d de noeuds.\n", count(tete));
}