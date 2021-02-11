/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: MainJeuNombreAdeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud / LOUBAT Thomas
// Date de création : 25/01/2021
// Rôle du fichier: Contient le code jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              iostream
// Historique du fichier: programmation du main
/*************************************************/
#include <iostream>
using namespace std;

#include "../include/JeuNombreADeviner.h"

int main()
{
    string nom;
    TJoueur joueur1;
    int gagnee;
    int echec;
    int tentatives;
    bool rejouer;


    cout << "Vous allez jouer pour deviner un nombre secret, veuillez saisir votre nom." << endl;
    cin >> nom;
    InitJoueur(joueur1,nom);
    do
    {
        JouerPartie(joueur1,TirerNombreMystere());
        ResultatsJoueur(joueur1,gagnee,echec,tentatives);
        cout << "souhaitez vous rejouer ? true(1)/false(0)" << endl;
        cin >> rejouer;
    }
    while (rejouer == true);
    cout << "Voici vos statistiques" << endl;
    cout << "Nom:" << nom << endl;
    cout << "Parties jouees:" << gagnee + echec << endl;
    cout << "Parties gagnees:" << gagnee << endl;
    cout << "Nombre de tentatives:" << tentatives << endl;
    return 0;
}

