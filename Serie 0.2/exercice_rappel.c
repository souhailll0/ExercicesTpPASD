#include<stdio.h>

typedef struct note{
    float valeur;
    float coefficient;
    char module[20];
}note;

typedef struct etudiant{
    char nom[20];
    char matricule[20];
    note notes[3];
}etudiant;



float moyenne(etudiant e){
    float somme = 0;
    float moyenne = 0;
    int i;
    for(i = 0; i< 3; i++){
        moyenne = moyenne + e.notes[i].valeur * e.notes[i].coefficient;
        somme = somme + e.notes[i].coefficient;
    }
    moyenne = moyenne / somme;
    return moyenne;
}







int main(){
    etudiant etudiants[3];
    int i=0;
    for(i= 0; i < 3; i++){
        printf("Entrer le nom de l'etudiant: ");
        scanf("%s", &etudiants[i].nom);
        printf("Entrer le matricule de l'etudiant: ");
        scanf("%s", &etudiants[i].matricule);
        for(int j=0; j<3; j++){
            printf("Entrer le module %d de l'etudiant %s: ", j+1, etudiants[i].nom);
            scanf("%s", &etudiants[i].notes[j].module);
            printf("Entrer le coefficient %d de l'etudiant %s: ", j+1, etudiants[i].nom);
            scanf("%f", &etudiants[i].notes[j].coefficient);
            printf("Entrer la note %d de l'etudiant %s: ", j+1, etudiants[i].nom);
            scanf("%f", &etudiants[i].notes[j].valeur);
        }
    }

    for(i = 0; i<3; i++){
        printf("Le nom est %s\n",etudiants[i].nom);
        printf("La moyenne est: %.2f\n", moyenne(etudiants[i]));
    }
    printf("\n");
    return 0;
}