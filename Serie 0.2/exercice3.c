
#include<stdio.h>
#include<stdlib.h>

typedef struct noeud{
    int valeur;
    struct noeud* suivant;
}noeud;

noeud* link(noeud* li1, noeud* li2){
    if (li1 == NULL){
        return li2;
    }else{
        noeud* aide = li1;
        while(aide->suivant != NULL){
            aide = aide->suivant;
        }
        aide->suivant = li2;
    }
    return li1;
}
void main(){

}