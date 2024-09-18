/* 
 * File:   main.cpp
 * Author: Bilal Draa
 *
 * Created on 22 mars 2024, 15 h 09
 */
#include"Borne.h"
#include<iostream>
#include<string>
#include<cctype>
#include"validationFormat.h"
#include <limits>
#include"ContratException.h"
#include"RegistreBorne.h"
#include "BorneFontaine.h"
#include"BorneStationnement.h"


using namespace util;
using namespace std;
using namespace bornesQuebec;


int main ()
{
    // Déclaration des variables pour les données de la borne fontaine
    int idFontaine;
    std::string idVoiePubliqueFontaine;
    std::string nomTopographiqueFontaine;
    float latitudeFontaine;
    float longitudeFontaine;
    std::string ville;
    std::string arrondissement;

    // Déclaration des variables pour les données de la borne de stationnement
    int idStationnement;
    std::string idVoiePubliqueStationnement;
    std::string nomTopographiqueStationnement;
    float latitudeStationnement;
    float longitudeStationnement;
    int numBorne;
    std::string cote;

    // Saisie des données pour la borne fontaine
    std::cout << "Enregistrement d’une borne fontaine :" << std::endl;
    std::cout << "Entrez l'identifiant de la borne valide : ";
    std::cin >> idFontaine;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorer le reste de la ligne après la lecture d'un entier
    while (idFontaine <= 0)
    {
        std::cout << "Entrez l'identifiant de la borne valide : ";
        std::cin >> idFontaine;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorer le reste de la ligne après la lecture d'un entier
    }

    bool estNombre;
    do
    {
        std::cout << "Entrez l'identifiant de la voie publique : ";
        std::getline(std::cin, idVoiePubliqueFontaine);

        estNombre = true; // On présume que l'entrée est un nombre

        // Vérifier si chaque caractère est un chiffre
        for (char c : idVoiePubliqueFontaine)
        {
            if (!isdigit(c))
            {
                estNombre = false;
                break; // Si un caractère non numérique est trouvé
            }
        }

        // La boucle continue tant que l'entrée n'est pas un nombre
    } while (!estNombre);

    std::cout << "Entrez le nom topographique valide : ";
    std::getline(std::cin, nomTopographiqueFontaine);
    while (nomTopographiqueFontaine.empty())
    {
        std::cout << "Entrez le nom topographique valide : ";
        std::getline(std::cin, nomTopographiqueFontaine);
    }

    std::cout << "Entrez la longitude : ";
    std::cin >> longitudeFontaine;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorer le reste de la ligne après la lecture d'un float

    std::cout << "Entrez la latitude : ";
    std::cin >> latitudeFontaine;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorer le reste de la ligne après la lecture d'un float

    std::cout << "Entrez le nom de la ville : ";
    std::getline(std::cin, ville);

    std::cout << "Entrez le nom de l'arrondissement : ";
    std::getline(std::cin, arrondissement);
    while (ville == "Québec" && arrondissement.empty())
    {
        std::cout << "Entrez le nom de l'arrondissement : ";
        std::getline(std::cin, arrondissement);
    }

    // Saisie des données pour la borne de stationnement
    std::cout << "Enregistrement d’une borne de stationnement :" << std::endl;
    std::cout << "Entrez l'identifiant de la borne valide : ";
    std::cin >> idStationnement;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (idStationnement <= 0)
    {
        std::cout << "Entrez l'identifiant de la borne valide : ";
        std::cin >> idStationnement;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Saisie de l'identifiant de la voie publique pour la borne de stationnement
    bool estNombre2;
    do
    {
        std::cout << "Entrez l'identifiant de la Voie Publique : ";
        std::getline(std::cin, idVoiePubliqueStationnement);

        estNombre2 = true; // Présumer que l'entrée est un nombre 

        // Vérifier si chaque caractère est un chiffre
        for (char a : idVoiePubliqueStationnement)
        {
            if (!isdigit(a))
            {
                estNombre = false;
                break; // Sortie de la boucle si il y a une lettre
            }
        }
    } while (!estNombre2);

    std::cout << "Entrez un nom topographique valide : ";
    std::getline(std::cin, nomTopographiqueStationnement);
    while (nomTopographiqueStationnement.empty())
    {
        std::cout << "Entrez un nom topographique valide : ";
        std::getline(std::cin, nomTopographiqueStationnement);
    }

    std::cout << "Entrez la longitude : ";
    std::cin >> longitudeStationnement;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorer le reste après la lecture d'un float

    std::cout << "Entrez la latitude : ";
    std::cin >> latitudeStationnement;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorer le reste après la lecture d'un float

    // Saisie du numéro de la borne de stationnement
    std::cout << "Entrez le numéro de la borne de stationnement : ";
    std::cin >> numBorne;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (numBorne < 1 || numBorne > 9999)
    {
        std::cout << "Entrez le numéro de la borne de stationnement : ";
        std::cin >> numBorne;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Saisie du côté de la rue pour la borne de stationnement
    std::cout << "Entrez le cote de la rue (N, S, E, O) : ";
    std::cin >> cote;
    while (util::validePointCardinal(cote) == false)
    {
        std::cout << "Entrez le cote de la rue (N, S, E, O) : ";
        std::cin >> cote;
    }

    // Création des objets pour les bornes fontaine et de stationnement
    bornesQuebec::BorneFontaine uneBorne(idFontaine, idVoiePubliqueFontaine, nomTopographiqueFontaine, latitudeFontaine, longitudeFontaine, ville, arrondissement);
    bornesQuebec::BorneStationnement uneBorne2(idStationnement, idVoiePubliqueStationnement, nomTopographiqueStationnement, latitudeStationnement, longitudeStationnement, numBorne, cote);

    // Création d'un registre et ajout des bornes
    std::string registre;
    std::cout << "Entrez le nom de registre des bornes : ";
    std::cin >> registre;
    bornesQuebec::RegistreBorne r(registre);
    r.ajouteBorne(uneBorne);
    r.ajouteBorne(uneBorne2);

    // Affichage du contenu du registre
    std::cout << "Contenu du registre : " << std::endl;
    std::cout << r.reqRegistreBorneFormate() << std::endl;

    return 0;
}
