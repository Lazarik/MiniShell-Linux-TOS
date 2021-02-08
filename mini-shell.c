/*
TP: Création d'un Mini Shell pour Linux
Etudiants: Sylvain MAAMERI, Mathieu LOURENCO, Swan GONCALVES
Année: 2020-2021 - 2A2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define INPUT_LENGTH 50
#define CMD_LENGTH 50

int main(int argc,char ** argv) {

    int miniShell,childFork;
    char input[INPUT_LENGTH];

    miniShell = 1; 

    /*Message de bienvnue dans le Mini Shell*/
    printf("\nBienvenue dans ce Mini Shell Linux !");

    /*
    Boucle principale
    s'execute tant que l'utilisateur ne saisie pas la commande exit
    */
    while(miniShell != 0){

        char *cmd[CMD_LENGTH] = {NULL};
        char *pointeur = input;

        /*Pour debug*/
        //printf("\nPID Parent: %i",getpid());
        /*Couleur Rouge*/
        printf("\033[31m");
        printf("\nTOS-Shell >");
        /*Couleur BLeu*/
        printf("\033[34m");
        fgets(input,INPUT_LENGTH,stdin);

        /*Converti la chaine saisi en tableau CMD*/
        for (int i = 0; i < sizeof(cmd) && *pointeur; pointeur++) {
            if (*pointeur == ' ') continue;
            if (*pointeur == '\n') break;
            for (cmd[i++] = pointeur; *pointeur && *pointeur != ' ' && *pointeur != '\n'; pointeur++);
            *pointeur = '\0';
        }

        if (fork() == 0){
            execvp(cmd[0], cmd);
        }

        wait(&childFork);

        /*  WIP NE FONCTIONNE PLUS !!! Vérification si la commande exit est saisie*/
        //miniShell = strcmp(input,"exit\n\0");
    }

    return EXIT_SUCCESS;
}