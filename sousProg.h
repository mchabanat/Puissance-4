#ifndef SOUSPROGRAMMES_H
#define SOUSPROGRAMMES_H

#include <iostream>
#include "game-tools.h"
using namespace std;



/******** DECLARATION DE VARIABLES GLOBALES ********/
const unsigned short int NB_LIGNES = 6; // Représente le nombre de lignes du plateau de jeu pour la bataille navale
const unsigned short int NB_COLONNES = 7; // Représente le nombre de colonnes du plateau de jeu pour la bataille navale


/******** ENREGISTREMENTS ********/
enum SensVictoire {aucun,diagonal,vertical,horizontal}; // Type qui détermine le sens d'alignement des jetons qui a permis au joueur de gagner

enum UnJeton {red,yellow,empty}; // Type qui montre les 3 possibilités qu'une case de la grille peut avoir


/******** SOUS-PROGRAMMES ********/
void afficherGrille(const UnJeton _grille[NB_LIGNES][NB_COLONNES]);
/* BUT : afficher la grille du jeu contenant les jetons joués par les joueurs */

void remplirGrille(UnJeton _grille[NB_LIGNES][NB_COLONNES]);
/* BUT : remplir la grille du Puissance 4 contenant NB_COLONNES colonnes et NB_LIGNES lignes afin de préparer le jeu */

void saisieVerif(const UnJeton _grille[NB_LIGNES][NB_COLONNES], char& _coup,bool& _abandon);
/* BUT : Verifier si la colonne saisie est correcte ou non (gère le cas de l'abandon si 0 est saisi) */

bool estPleine(const UnJeton _grille[NB_LIGNES][NB_COLONNES], const char& _coup);
/* BUT : retourne true si la colonne saisie est pleine, false sinon */

void marquerGrille(UnJeton _grille[NB_LIGNES][NB_COLONNES], const char& _coup, unsigned short int _joueur, unsigned int& _ligne);
/* BUT : Marquer la grille à l'endroit du coup saisi par l'utilisateur (vérifié au préalable) et renvoie l'indice de la ligne où est posé le jeton*/


SensVictoire etatJetons(const UnJeton _grille[NB_LIGNES][NB_COLONNES],const char& _coup, const unsigned int& _ligne);
/* BUT : Etudie les jetons autour du dernier jeton joué et renvoie le sens des jetons s'il y a une victoire ou aucun s'il n'y a pas de victoire */

#endif