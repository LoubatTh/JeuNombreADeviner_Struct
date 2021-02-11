/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: JeuNombreADeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de création : 25/01/2021
// Rôle du fichier: Contient le code des fonctions du jeu
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
// Rôle : Crée un joueur. Initialise toutes les informations du joueur.
//        Le nombre de tentatives, de parties gagnées et de parties jouées seront à 0.
// Paramètres d'entrée : joueurAcreer, un_nom
// Paramètres de sortie :
// Paramètres d'entrée/sortie :

void InitJoueur(TJoueur& joueurAcreer, string un_nom)
{
    joueurAcreer.nom = un_nom;
    joueurAcreer.nbPartiesJouees = 0;
    joueurAcreer.nbPartiesGagnees = 0;
    joueurAcreer.nbTentatives = 0;
}


// Nom :TirerNombreMystere
// Rôle : Tire aléatoirement un nombre à deviner entre 0 et 10
// Valeur de retour : nombre à deviner

int TirerNombreMystere()
{
    srand(time(0));
    int random = rand() %10+1;
    return random;
}


// Nom :JouerPartie
// Rôle : Fait jouer une partie au joueur passé en paramètre
//        A la fin, met à jour les informations du joueur
// Paramètres d'entrée:
// Paramètres de sortie:
// Paramètres d'entrée/sortie :

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
// Rôle : met à jour les informations du joueur passé en paramètre
// Paramètres d'entrée:
// Paramètres de sortie:
// Paramètres d'entrée/sortie : TJoueur joueur

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
// Rôle : indique les résultats du joueur passé en paramètre
//        le nombre de parties gagnées, le nombre de parties perdues, le nombre d'essais total
//        La fonction N'affiche PAS les informations à l'écran
// Paramètres d'entrée:
// Paramètres de sortie:
// Paramètres d'entrée/sortie :

void ResultatsJoueur(TJoueur joueur, int& nbsucces, int& nbechec, int& nbessais)
{
    nbessais = joueur.nbTentatives;
    nbsucces = joueur.nbPartiesGagnees;
    nbechec = joueur.nbPartiesJouees - joueur.nbPartiesGagnees;
}

// Nom :Nom
// Rôle : retourne le nom du joueur
// Paramètres d'entrée: le joueur dont on veut le nom
// Valeur de retour : nom du joueur

string Nom(TJoueur joueur){

    return joueur.nom;
}

