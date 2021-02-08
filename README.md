# Projet TOS - MiniShell

Création d'un minishell en langage C.

## Utilisation

1. Compilation du programme ``gcc mini-shell.c -o mini-shell``.
2. Droits d'exécution du programme ``chmod +x mini-shell``.
3. Lancement du programme ``./mini-shell``.
4. Let's GO ``TOS-Shell >`` il ne reste plus qu'à exécuter des commandes.

## Fonctionnalités

1. Supporte les commandes avec une multitude d'arguments.
2. Prompt coloré.

## Paramétrages / Limites

1. En haut du programme ``#define INPUT_LENGTH 50`` et ``#define CMD_LENGTH 50`` définissent le nombre de caractères pouvant être saisi et le nombre d'arguments de la commande. Libre à vous de modifier ces valeurs.

## BUG / WIP

1. La gestion de la commande EXIT n'est plus fonctionnel.
2. Les pipes ``|`` ne fonctionne pas et sont considérés comme un argument de la commande.