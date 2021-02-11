/*************************************************/
// Nom du projet: Jeu du nombre � deviner
// Nom du fichier: JeuNombreADeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de cr�ation : 25/01/2021
// R�le du fichier: Contient le code des fonctions du jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              iostream
//                              ctime
// Historique du fichier:
/*************************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
#include "../include/JeuNombreAdeviner.h"

// Nom :InitJoueur
// R�le : Cr�e un joueur. Initialise toutes les informations du joueur.
//        Le nombre de tentatives, de parties gagn�es et de parties jou�es seront � 0.
// Param�tres d'entr�e : joueurAcreer, un_nom
// Param�tres de sortie :
// Param�tres d'entr�e/sortie :

void InitJoueur(TJoueur& joueurAcreer, string un_nom)
{
    joueurAcreer.nom = un_nom;
    joueurAcreer.nbPartiesJouees = 0;
    joueurAcreer.nbPartiesGagnees = 0;
    joueurAcreer.nbTentatives = 0;
}


// Nom :TirerNombreMystere
// R�le : Tire al�atoirement un nombre � deviner entre 0 et 10
// Valeur de retour : nombre � deviner

int TirerNombreMystere()
{
    srand(time(0));
    int random = rand() %10+1;
    return random;
}


// Nom :JouerPartie
// R�le : Fait jouer une partie au joueur pass� en param�tre
//        A la fin, met � jour les informations du joueur
// Param�tres d'entr�e:
// Param�tres de sortie:
// Param�tres d'entr�e/sortie :

void JouerPartie(TJoueur& un_joueur, int nombreADeviner)
{
    int rep=0;
    int i=0;
    cout << "Veuillez saisir un nombre entre 1 et 10" << endl;
    cin >> rep;
    while(rep != nombreADeviner,i++, i<=3)
    {
        if (rep > nombreADeviner)
        {
            cout << "Veuillez saisir un nombre plus petit que " << rep << endl;
            cin >> rep;
        }
        else if (rep < nombreADeviner)
        {
            cout << "Veuillez saisir un nombre plus grand que " << rep << endl;
            cin >> rep;
        }
    }
        if (rep == nombreADeviner)

        {
            cout << "Bravo, la reponse etait " << nombreADeviner << " ! " << endl;
            MajResultatsJoueur(un_joueur,i,true);
        }
        else
        {
            cout << "Perdu, la reponse etait " << nombreADeviner << " ! " << endl;
            MajResultatsJoueur(un_joueur,i,false);
        }
}


// Nom : MajResultatsJoueur
// R�le : met � jour les informations du joueur pass� en param�tre
// Param�tres d'entr�e:
// Param�tres de sortie:
// Param�tres d'entr�e/sortie : TJoueur joueur

void MajResultatsJoueur(TJoueur& joueur, int nbEssais, bool gagne)
{
    joueur.nbPartiesJouees++;
    joueur.nbTentatives = joueur.nbTentatives + nbEssais;
    if(gagne == true)
    {
        joueur.nbPartiesGagnees++;
    }
}

// Nom : ResultatsJoueur
// R�le : indique les r�sultats du joueur pass� en param�tre
//        le nombre de parties gagn�es, le nombre de parties perdues, le nombre d'essais total
//        La fonction N'affiche PAS les informations � l'�cran
// Param�tres d'entr�e:
// Param�tres de sortie:
// Param�tres d'entr�e/sortie :

void ResultatsJoueur(TJoueur joueur, int& nbsucces, int& nbechec, int& nbessais)
{
    nbessais = joueur.nbTentatives;
    nbsucces = joueur.nbPartiesGagnees;
    nbechec = joueur.nbPartiesJouees - joueur.nbPartiesGagnees;
}

// Nom :Nom
// R�le : retourne le nom du joueur
// Param�tres d'entr�e: le joueur dont on veut le nom
// Valeur de retour : nom du joueur

string Nom(TJoueur joueur){

    return joueur.nom;
}

