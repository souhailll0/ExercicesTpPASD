#include<stdio.h>
#include<stdlib.h>

typedef struct noeud{
    int valeur;
    struct noeud *suivant;
}noeud;

struct noeud* inserer(struct noeud* tete, int v){
    noeud* n = (noeud*) malloc(sizeof(noeud));
    n->valeur = v;
    n->suivant = tete;

    return n;
}

struct noeud* insererQueue(struct noeud* tete, int v){
    struct noeud* n = (noeud*) malloc(sizeof(struct noeud));
    n->valeur = v;
    n->suivant = NULL;
    if(tete == NULL){
        tete = n;
    }else{
        struct noeud* temp = tete;
        while(temp->suivant!= NULL){
            temp = temp->suivant;
        }
        temp->suivant = n;
    }
    return tete;
}
void afficher(noeud* tete){
    if(tete){
        printf("%d\n", tete->valeur);
        afficher(tete->suivant);
    }
}
int compter(struct noeud*tete){
    int c = 0;
    while(tete!=NULL){
        c++;
        tete = tete->suivant;
    }
    return c;
}

void main(){
    
}