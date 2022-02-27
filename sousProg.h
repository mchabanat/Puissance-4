#ifndef SOUSPROGRAMMES_H
#define SOUSPROGRAMMES_H

#include <iostream>
#include "game-tools.h"
using namespace std;



/******** DECLARATION DE VARIABLES GLOBALES ********/
const unsigned short int NB_LIGNES = 6; // Représente le nombre de lignes du plateau de jeu pour la bataille navale
const unsigned short int NB_COLONNES = 7; // Représente le nombre de colonnes du plateau de jeu pour la bataille navale


/******** ENREGISTREMENTS ********/
enum SensVictoire {diagonal,vertical,horizontal}; // Type qui détermine le sens d'alignement des jetons qui a permis au joueur de gagner

enum UnJeton {red,yellow,empty}; // Type qui montre les 3 possibilités qu'une case de la grille peut avoir


/******** SOUS-PROGRAMMES ********/
void afficherGrille(const char _grille[NB_COLONNES][NB_LIGNES]);
/* BUT : afficher la grille du Puissance 4 contenant NB_COLONNES colonnes et NB_LIGNES lignes */

void afficherGrille(const UnJeton _grille[NB_COLONNES][NB_LIGNES]);

void remplirGrille(char _grille[NB_COLONNES][NB_LIGNES]);
/* BUT : remplir la grille du Puissance 4 contenant NB_COLONNES colonnes et NB_LIGNES lignes afin de préparer le jeu */

void remplirGrille(UnJeton _grille[NB_COLONNES][NB_LIGNES]);
/* BUT : remplir la grille du Puissance 4 contenant NB_COLONNES colonnes et NB_LIGNES lignes afin de préparer le jeu */

void saisieVerif(char& _coup,bool& _abandon);
/* BUT : Verifier si la colonne saisie est correcte ou non (gère le cas de l'abandon si 0 est saisi) */

bool estPleine(UnJeton _grille[NB_COLONNES][NB_LIGNES], const char& _coup,const bool& _abandon);
/* BUT : retourne true si la colonne saisie est pleine, false sinon */

void marquerGrille(UnJeton _grille[NB_COLONNES][NB_LIGNES], char _coup, unsigned short int _joueur);
/* BUT : Marquer la grille à l'endroit du coup saisi par l'utilisateur (vérifié au préalable) */

#endif