#include<stdio.h>
#include<stdlib.h>

typedef struct noeud{
    int valeur;
    struct noeud *suivant;
}noeud;

void afficher(noeud * tete){
    noeud *aide = tete;
    while(aide!= NULL){
        printf("%d\n", aide->valeur);
        aide = aide->suivant;
    }
}
int recherche(noeud* tete, int v){
    noeud *p= tete;
    while(p!= NULL){
        if(p->valeur == v) return 1;
        p = p->suivant;
    }
    return 0;
}
void ajouterCroissant(noeud**phead, int v){
    /* Seance 2*/
    if(recherche(*phead, v)){
        return;
    }
    noeud * n = malloc(sizeof(noeud));
    n->valeur = v;
    n->suivant = NULL;
    if(*phead == NULL){
        *phead = n;
    }else{
        //Ajout au debut:
        //n->suivant = *phead;
        //*phead = n;
        
        if((*phead)->suivant == NULL){
            if((*phead)->valeur > v){
                n->suivant = *phead;
                *phead = n;
                //(*phead)->suivant = NULL;
            }else{
                (*phead)->suivant = n;
            }
            //(*phead)->suivant = n;
        }else{
            
        }
        

    }
    /* Seance 1
    if(recherche(*t, v))
        return;
    
    noeud*n = malloc(sizeof(noeud));
    n->valeur = v;
    n->suivant = NULL;

    
    if(*t == NULL){
        *t = n;
    }else{
        noeud* p = *t;
        while(p->suivant!=NULL){
            if(n->valeur < p->valeur)
            {
                n->suivant = p;
                p = n;
            }
            p = p->suivant;
        }
        if(p->suivant==NULL){
            p->suivant = n;
        }
    }
    */
}
int main(){
    noeud* tete = NULL;
    int i;
    int n;
    for( i = 0; i < 5; i++){
        printf("Entrer la valeur %d a ajouter: ", i+1);
        scanf("%d", &n);
        ajouterCroissant(&tete, n);
        afficher(tete);
    }
    
    return 0;
}