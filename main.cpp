/*
    Jeu : Puissance 4
    But : Réaliser une partie du jeu Puissance 4 entre 2 joueurs.
    Auteurs : Matis Chabanat 
    Date de dernière modification : 
    Remarques : 
*/


#include <iostream>
#include "game-tools.h"
#include "sousProg.h"

using namespace std;

int main(void){
    UnJeton grilleJeu[NB_COLONNES][NB_LIGNES] = {
        red,yellow,red,yellow,red,yellow,red,
        empty,empty,empty,empty,empty,empty,empty,
        empty,empty,empty,empty,empty,empty,empty,
        empty,empty,empty,empty,empty,empty,empty,
        empty,empty,empty,empty,empty,empty,empty,
        empty,empty,empty,empty,empty,empty,empty,
    };


    afficherGrille(grilleJeu);
}


int main2(void)
{
    /**************** VARIABLES ****************/
    char grilleAffichage[NB_COLONNES][NB_LIGNES]; // Grille permettant de gérer l'affichage 
    UnJeton grilleJeu[NB_COLONNES][NB_LIGNES]; // Grille contenant les coups joués des joueurs.
    unsigned short int premierJoueur; // 1 = joueur rouge, 2 = joueur jaune
    unsigned short int joueurEnCours; // 1 = joueur rouge, 2 = joueur jaune

    char coupJoue; // Entre 0 et le nombre de colonnes max
    unsigned int nbCoupJoues = 0;

    bool abandon = false;
    bool victoire = false; // Si a la fin de la partie victoire est à false et que abandon est a false, c'est que la grille est pleine et qu'il y a match nul.

    
    /**************** TRAITEMENTS ****************/
    // PREPARATION DE LA PARTIE
    remplirGrille(grilleAffichage);
    remplirGrille(grilleJeu);
    afficherGrille(grilleAffichage);

    // Choix du premier joueur à jouer
    cout << "Tirage au sort : le joueur ";
    premierJoueur = static_cast<unsigned short int>(random(1,2));

    if (premierJoueur==1)
    {
        afficherTexteEnCouleur("rouge ",rouge,false);
    }
    else
    {
        afficherTexteEnCouleur("jaune ",jaune,false);
    }

    cout << "commence.";

    joueurEnCours = premierJoueur;

    pause(3);
    effacer();

    // PARTIE EN COURS
    while (nbCoupJoues < (NB_LIGNES * NB_COLONNES)){
        afficherGrille(grilleAffichage);

        cout << "Le joueur ";
        if (joueurEnCours == 1)
        {
            afficherTexteEnCouleur("rouge ",rouge,false);
        }
        else
        {
            afficherTexteEnCouleur("jaune ",jaune,false);
        }
        cout << "a la main." << endl << endl;

        do{
            // Saisie Verif 
            saisieVerif(coupJoue,abandon);

            // Verification si la colonne est pleine
        } while(estPleine(grilleJeu,coupJoue,abandon));
        
        // Cas où le joueur abandonne
        if(abandon) {
            break;
        }
        
        // Marquage de la grille 
        marquerGrille(grilleJeu,coupJoue,joueurEnCours);
        

        // On regarde si 4 jetons sont alignés


        // Changement de joueur 
        if (joueurEnCours == 1) {
            joueurEnCours = 2;
        }
        else {
            joueurEnCours = 1;
        }

        effacer();
    }

    // FIN DE LA PARTIE
    // Cas de l'abandon d'un joueur
    effacer();
    afficherGrille(grilleAffichage);

    if(abandon) {
        if (joueurEnCours == 1) {
            cout << "Victoire du joueur ";
            afficherTexteEnCouleur("jaune ",jaune,false);
            cout << "par abandon !";
        }
        else {
            cout << "Victoire du joueur ";
            afficherTexteEnCouleur("rouge ",rouge,false);
            cout << "par abandon !";
        }
    }
    // Cas de la grille pleine (match nul)
    else if (nbCoupJoues >= (NB_LIGNES * NB_COLONNES) && !victoire) {
        cout << "Match nul : la grille est pleine ...";
    }
    // Cas de la victoire d'un des 2
    

    
    return 0;
}


