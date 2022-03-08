#include "sousProg.h"

// Sous programme privé
bool estVide(const UnJeton _grille[NB_LIGNES][NB_COLONNES], string _coup);
/* BUT : retourne true si la colonne à l'indice _coup est vide, false sinon */

// Sous programmes du .h
void afficherGrille(const UnJeton _grille[NB_LIGNES][NB_COLONNES])
{
    unsigned int i;
    unsigned int j;

    cout << endl << "        P U I S S A N C E   4    " << endl << endl;

    for (i = 0; i < NB_LIGNES; i++)
    {
        cout << "    +";
        for (j = 0; j < NB_COLONNES; j++)
        {
            cout << "---+";
        }

        cout << endl << "    |";

        for (j = 0; j < NB_COLONNES; j++)
        {
            cout << " ";
            switch (_grille[i][j])
            {
            case empty:
                cout << " ";
                break;
            case red:
                afficherTexteEnCouleur("O", rouge);
                break;
            case yellow:
                afficherTexteEnCouleur("O", jaune);
                break;
            }
            cout << " |";
        }

        cout << endl;
    }

    cout << "    +";
    for (j = 0; j < NB_COLONNES; j++)
    {
        cout << "---+";
    }

    cout << endl << "    ";
    for (j = 0; j < NB_COLONNES; j++)
    {
        cout << "  " << j + 1 << " ";
    }

    cout << endl << endl;
}

void remplirGrille(UnJeton _grille[NB_LIGNES][NB_COLONNES])
{
    unsigned int i;
    unsigned int j;

    for (i = 0; i < NB_LIGNES; i++)
    {
        for (j = 0; j < NB_COLONNES; j++)
        {
            _grille[i][j] = empty;
        }
    }
}

void saisieVerif(const UnJeton _grille[NB_LIGNES][NB_COLONNES], string& _coup, bool &_abandon)
{
    char coupJoue;

    while (true)
    {
        cout << "Numero de colonne [1.." << NB_COLONNES << "] (0 pour abandonner) : ";
        cin >> _coup;

        coupJoue = _coup[0];

        if (int(coupJoue) - 48 == 0)
        {
            _abandon = true;
            break;
        }
        else if (int(coupJoue) - 48 > NB_COLONNES || int(coupJoue) - 48 < 0)
        {
            cout << "ERREUR ! Le numero de colonne doit etre compris entre 1 et " << NB_COLONNES << ". Reessayez." << endl << endl;
        }
        else
        {
            if (estPleine(_grille, _coup))
            {
                cout << "Numero de colonne incorrect : la colonne est pleine." << endl << "Choisissez une autre colonne." << endl << endl;
            }
            else
            {
                break;
            }
        }
    }
}

bool estVide(const UnJeton _grille[NB_LIGNES][NB_COLONNES], string _coup)
{
    unsigned int colonneJouee = int(_coup[0]) - 49;

    if (_grille[NB_LIGNES - 1][colonneJouee] == empty)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool estPleine(const UnJeton _grille[NB_LIGNES][NB_COLONNES], string _coup)
{
    unsigned int colonneJouee = int(_coup[0]) - 49;

    if (_grille[0][colonneJouee] == empty)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void marquerGrille(UnJeton _grille[NB_LIGNES][NB_COLONNES], string _coup, unsigned short int _joueur, unsigned int &_ligne)
{
    unsigned int colonneJouee = int(_coup[0]) - 49;

    unsigned int i;

    if (estVide(_grille, _coup))
    {
        if (_joueur == 1)
        {
            _grille[NB_LIGNES - 1][colonneJouee] = red;
        }
        else
        {
            _grille[NB_LIGNES - 1][colonneJouee] = yellow;
        }
        _ligne = NB_LIGNES - 1;
    }
    else
    {
        for (i = 0; i < NB_LIGNES - 1; i++)
        {
            if (_grille[i][colonneJouee] == empty && _grille[i + 1][colonneJouee] != empty)
            {
                if (_joueur == 1)
                {
                    _grille[i][colonneJouee] = red;
                }
                else
                {
                    _grille[i][colonneJouee] = yellow;
                }
                _ligne = i;
            }
        }
    }
}

SensVictoire etatJetons(const UnJeton _grille[NB_LIGNES][NB_COLONNES], const char &_coup, const unsigned int &_ligne)
{
    unsigned int colonneJouee = int(_coup) - 49;
    unsigned int i;
    int idColonne;
    int idLigne;
    unsigned int compteur4ALaSuite = 0;
    SensVictoire etat = aucun;

    // Recherche horizontale
    for (i = 0; i < NB_COLONNES; i++)
    {
        if (_grille[_ligne][i] == _grille[_ligne][colonneJouee])
        {
            compteur4ALaSuite++;
        }
        else
        {
            compteur4ALaSuite = 0;
        }

        if (compteur4ALaSuite >= 4)
        {
            etat = horizontal;
            break;
        }
    }
    // Recherche verticale
    compteur4ALaSuite = 0;

    if (etat == aucun)
    {
        for (i = 0; i < NB_LIGNES; i++)
        {
            if (_grille[i][colonneJouee] == _grille[_ligne][colonneJouee])
            {
                compteur4ALaSuite++;
            }
            else
            {
                compteur4ALaSuite = 0;
            }

            if (compteur4ALaSuite >= 4)
            {
                etat = vertical;
                break;
            }
        }
    }

    // Recherche diagonale
    // Diago de haut gauche a bas droite

    compteur4ALaSuite = 0;
    if (etat == aucun)
    {
        idLigne = _ligne;
        idColonne = colonneJouee;

        // Mise en place des indices du début de la recherche
        idLigne = idLigne - NB_LIGNES - 1;
        idColonne = idColonne - NB_COLONNES;

        while (idColonne < 0 || idLigne < 0)
        {
            idLigne++;
            idColonne++;
        }

        // Début de la recherche
        for (i = 0; i < NB_COLONNES; i++)
        {
            if (idLigne > NB_LIGNES - 1 || idColonne > NB_COLONNES - 1)
            {
                break;
            }

            if (_grille[idLigne][idColonne] == _grille[_ligne][colonneJouee])
            {

                compteur4ALaSuite++;
            }
            else
            {
                compteur4ALaSuite = 0;
            }

            if (compteur4ALaSuite >= 4)
            {
                etat = diagonal;
                break;
            }

            idColonne++;
            idLigne++;
        }
    }

    // Diago de bas gauche a haut droite
    compteur4ALaSuite = 0;
    if (etat == aucun)
    {
        idLigne = _ligne;
        idColonne = colonneJouee;
    }

    // Mise en place des indices du début de la recherche
    idLigne = idLigne + NB_LIGNES + 1;
    idColonne = idColonne - NB_COLONNES;

    while (idColonne < 0 || idLigne > NB_LIGNES - 1)
    {
        idLigne--;
        idColonne++;
    }

    // Début de la recherche
    for (i = 0; i < NB_COLONNES; i++)
    {
        if (idLigne < 0 || idColonne > NB_COLONNES - 1)
        {
            break;
        }

        if (_grille[idLigne][idColonne] == _grille[_ligne][colonneJouee])
        {

            compteur4ALaSuite++;
        }
        else
        {
            compteur4ALaSuite = 0;
        }

        if (compteur4ALaSuite >= 4)
        {
            etat = diagonal;
            break;
        }

        idColonne++;
        idLigne--;
    }

    return etat;
}