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


int maina(void){ // Tests
    UnJeton grilleJeu[NB_LIGNES][NB_COLONNES] 
    = {
        empty,red,empty,empty,empty,empty,empty,
        empty,red,empty,empty,empty,empty,empty,
        empty,red,empty,empty,empty,empty,empty,
        empty,yellow,empty,empty,empty,empty,empty,
        empty,yellow,empty,empty,empty,empty,empty,
        empty,red,red,empty,empty,empty,empty
    };

    
    // remplirGrille(grilleJeu);
    

    unsigned int ligne;

    marquerGrille(grilleJeu,'3',1,ligne);
    afficherGrille(grilleJeu);
    cout << ligne;
    
    return 0;
} 


int main(void)
{
    /**************** VARIABLES ****************/
    
    UnJeton grilleJeu[NB_LIGNES][NB_COLONNES]; // Grille contenant les coups joués des joueurs.
    unsigned short int joueurEnCours; // 1 = joueur rouge, 2 = joueur jaune
    SensVictoire etatPartie = aucun; // Représente s'il y a eu un vainqueur (le sens) ou non (aucun)

    char coupJoue; // Entre 0 et le nombre de colonnes max
    unsigned int indiceLigne = 0;
    unsigned int nbCoupJoues = 0;

    bool abandon = false;
    bool victoire = false; // Si a la fin de la partie victoire est à false et que abandon est a false, c'est que la grille est pleine et qu'il y a match nul.

    
    /**************** TRAITEMENTS ****************/
    // PREPARATION DE LA PARTIE
    remplirGrille(grilleJeu);
    afficherGrille(grilleJeu);

    // Choix aléatoire du premier joueur à jouer
    cout << "Tirage au sort : le joueur ";
    joueurEnCours = static_cast<unsigned short int>(random(1,2));

    if (joueurEnCours==1)
    {
        afficherTexteEnCouleur("rouge ",rouge,false);
    }
    else
    {
        afficherTexteEnCouleur("jaune ",jaune,false);
    }

    cout << "commence.";

    // pause(3);
    effacer();

    // PARTIE EN COURS
    while (nbCoupJoues < (NB_LIGNES * NB_COLONNES)){
        afficherGrille(grilleJeu);

        // On affiche le joueur qui a la main
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

        while(true) {
            // Saisie Verif 
            saisieVerif(grilleJeu,coupJoue,abandon);

            if(abandon) {
                break;
            }
            // Verification si la colonne est pleine
            if(!estPleine(grilleJeu,coupJoue)){
                break;
            }
        }
        
        // Cas où le joueur abandonne
        if(abandon) {
            break;
        }
        
        // Marquage de la grille 
        marquerGrille(grilleJeu,coupJoue,joueurEnCours,indiceLigne);
        
        // Incrémentation du nombre de coups joués 
        nbCoupJoues++;

        // On regarde si 4 jetons sont alignés
        etatPartie = etatJetons(grilleJeu,coupJoue,indiceLigne);

        if(etatPartie != aucun){
            victoire = true;
            break;
        }

        // Changement de joueur 
        if (joueurEnCours == 1) {
            joueurEnCours = 2;
        }
        else {
            joueurEnCours = 1;
        }

        // effacer();
    }

    // FIN DE LA PARTIE
    // effacer();
    afficherGrille(grilleJeu);

    // Cas de l'abandon d'un joueur
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


