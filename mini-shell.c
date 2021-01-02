/*
TP: Création d'un Mini Shell pour Linux
Etudiants: Sylvain MAAMERI, Mathieu LOURENCO, Swan GONCALVES
Année: 2020-2021 - 2A2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_LENGTH 50

int main(int argc,char ** argv) {

    int miniShell;
    char input[INPUT_LENGTH];

    miniShell = 1; 

    /*Message de bienvnue dans le Mini Shell*/
    printf("\nBienvenue dans ce Mini Shell Linux !");

    /*
    Boucle principale
    s'execute tant que l'utilisateur ne saisie pas la commande exit
    */
    while(miniShell != 0){
        printf("\nTOS-Shell >");
        fgets(input,INPUT_LENGTH,stdin);

        /*Vérification si la commande exit est saisie*/
        miniShell = strcmp(input,"exit\n\0");
    }

    return EXIT_SUCCESS;
}