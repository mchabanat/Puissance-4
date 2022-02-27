#include "sousProg.h"

// Sous programme cachés 
bool estVide(const UnJeton _grille[NB_LIGNES][NB_COLONNES], const char& _coup);
/* BUT : retourne true si la colonne à l'indice _coup est vide, false sinon */


// Sous programmes du .h
void afficherGrille(const UnJeton _grille[NB_LIGNES][NB_COLONNES]){
    unsigned int i;
    unsigned int j;
    
    cout << "    P U I S S A N C E  4    " << endl << endl;

    for(j = 0; j < NB_COLONNES ; j++)
    {
        cout << "  " << j+1 << " ";
    }

    cout << endl;

    for(i = 0; i < NB_LIGNES ; i++)
    {
        cout << "+";
        for(j = 0; j < NB_COLONNES ; j++)
        {
            cout << "---+";
        }

        cout << endl << "|";

        for(j = 0; j < NB_COLONNES ; j++)
        {
            cout << " " ;
            switch (_grille[i][j])
            {
            case empty: cout << " " ; break;
            case red: afficherTexteEnCouleur("o",rouge); break;
            case yellow: afficherTexteEnCouleur("o",jaune); break;
            }
            cout << " |" ;
        }

        cout << endl;
    }

    cout << "+";
    for(j = 0; j < NB_COLONNES ; j++)
    {
        cout << "---+";
    }

    cout << endl << endl;;
}


void remplirGrille(UnJeton _grille[NB_LIGNES][NB_COLONNES]){
    unsigned int i;
    unsigned int j;

    for(i = 0;i < NB_LIGNES;i++)
    {
        for(j = 0;j < NB_COLONNES;j++)
        {
            _grille[i][j] = empty;
        }
    }
}


void saisieVerif(const UnJeton _grille[NB_LIGNES][NB_COLONNES], char& _coup,bool& _abandon){
    while(true) {
        cout << "Numero de colonne [1.." << NB_COLONNES << "] (0 pour abandonner) : ";
        cin >> _coup;

        if (int(_coup)-48 == 0) {
            _abandon = true;
            break;
        }
        else if (int(_coup)-48 > NB_COLONNES || int(_coup)-48 < 0) {
            cout << "ERREUR ! Le numero de colonne doit etre compris entre 1 et " << NB_COLONNES << ". Reessayez." << endl << endl;
        }
        else {
            if (estPleine(_grille,_coup)){
                cout << "Numero de colonne incorrect : la colonne est pleine." << endl << "Choisissez une autre colonne." << endl << endl;
            }
            else{
                break;
            }
        }
    }
}


bool estVide(const UnJeton _grille[NB_LIGNES][NB_COLONNES], const char& _coup){
    unsigned int colonneJouee = int(_coup)-49;

    if (_grille[NB_LIGNES-1][colonneJouee] == empty){
        return true;
    }
    else{
        return false;
    }
}


bool estPleine(const UnJeton _grille[NB_LIGNES][NB_COLONNES], const char& _coup){
    unsigned int colonneJouee = int(_coup)-49;
    
    if (_grille[0][colonneJouee] == empty){
        return false;
    }
    else{
        return true;
    }
}


void marquerGrille(UnJeton _grille[NB_LIGNES][NB_COLONNES], const char& _coup, unsigned short int _joueur){
    unsigned int colonneJouee = int(_coup)-49;

    unsigned int i;

    if (estVide(_grille,_coup))
    {
        if (_joueur==1){
            _grille[NB_LIGNES-1][colonneJouee] = red;
        }
        else{
            _grille[NB_LIGNES-1][colonneJouee] = yellow;
        }
    }
    else
    {
        for (i = 0; i < NB_LIGNES-1; i++)
        {
            if (_grille[i][colonneJouee] == empty && _grille[i+1][colonneJouee] != empty)
            {
                if (_joueur==1){
                    _grille[i][colonneJouee] = red;
                }
                else{
                    _grille[i][colonneJouee] = yellow;
                }
            }
        }
    }
}


