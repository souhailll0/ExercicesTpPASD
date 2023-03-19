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

void ajouterCroissant(noeud**phead, int v){
    if(recherche(*phead, v)){
        return;
    }
    noeud * n = malloc(sizeof(noeud));
    n->valeur = v;
    n->suivant = NULL;
    if(*phead == NULL){
        *phead = n;
    }else{
        if((*phead)->valeur > v){
            n->suivant = *phead;
            *phead = n;
        }else if ((*phead)->suivant == NULL){
            (*phead)->suivant = n;
        }else{
            noeud * aide = *phead;
            while(aide->suivant->suivant != NULL && aide->valeur < v){
                aide = aide ->suivant;
            }
            if(aide->suivant->valeur > v){
                n->suivant = aide->suivant;
                aide->suivant = n;
            }else{
                aide->suivant->suivant = n;
            }
        }
    }
}

void supprimer(noeud**phead, int v){
    if(recherche(*phead, v) == 0){
        return;
    }else{
        noeud *aide = *phead;
        if((*phead)->valeur == v){
            *phead = aide->suivant;
            free(aide);
        }else{
            while(aide->suivant != NULL){
                if(aide->suivant->valeur == v){
                    noeud* n = aide->suivant;
                    aide->suivant = n->suivant;
                    free(n);
                    break;
                }
                aide = aide->suivant;
            }
            
        }
    }
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
    int n;
    // teste d'ajout de 5 noeuds
    for( i = 0; i < 5; i++){
        printf("Entrer la valeur %d a ajouter: ", i+1);
        scanf("%d", &n);
        ajouterCroissant(&tete, n);
        afficher(tete);
    }

    printf("Entrer la valeur a supprimer: ");
    scanf("%d", &n);
    supprimer(&tete, n);
    afficher(tete);
    
    return 0;
}