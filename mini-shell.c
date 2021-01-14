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

int main(int argc,char ** argv) {

    int miniShell,childFork;
    char input[INPUT_LENGTH];
    char *cmd[15];

    miniShell = 1; 

    /*Message de bienvnue dans le Mini Shell*/
    printf("\nBienvenue dans ce Mini Shell Linux !");

    /*
    Boucle principale
    s'execute tant que l'utilisateur ne saisie pas la commande exit
    */
    while(miniShell != 0){
        /*Pour debug*/
        printf("\nPID Parent: %i",getpid());

        printf("\nTOS-Shell >");
        fgets(input,INPUT_LENGTH,stdin);

        cmd[0] = "ls";
        cmd[1] = NULL;

        if (fork() == 0){
            execvp(cmd[0], cmd);
        }

        wait(&childFork);

        /*Vérification si la commande exit est saisie*/
        miniShell = strcmp(input,"exit\n\0");
    }

    return EXIT_SUCCESS;
}