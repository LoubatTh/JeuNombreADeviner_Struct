/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: MainJeuNombreAdeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de création : 25/01/2021
// Rôle du fichier: Contient le code jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              iostream
// Historique du fichier:
/*************************************************/
#include <iostream>
using namespace std;

#include "../include/JeuNombreADeviner.h"

int main()
{
    string nom;
    TJoueur joueur1;

    cout << "Vous allez jouer pour deviner un nombre secret, veuillez saisir votre nom." << endl;
    cin >> nom;
    InitJoueur(joueur1,nom);

        JouerPartie(joueur1,TirerNombreMystere());
    cout << "Voici vos statistiques" << endl;
    cout << "Nom:" << joueur1.nom << endl;
    cout << "Parties jouees:" << joueur1.nbPartiesJouees << endl;
    cout << "Parties gagnees:" << joueur1.nbPartiesGagnees << endl;
    cout << "Nombre de tentatives:" << joueur1.nbTentatives << endl;
    return 0;
}

