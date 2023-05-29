#ifndef DRESSEUR_H
#define DRESSEUR_H
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include "Pokemon.h"
#include <iostream>
using namespace std;

/**
 * @class Dresseur
 * Classe représentant un dresseur de Pokémon.
 */
class Dresseur {
private:
    string itsName; /**< Le nom du dresseur */
    int itslevel; /**< Le niveau du dresseur */
    int itsnbpoints; /**< Le nombre de points du dresseur */
    float itsmedspeed; /**< La vitesse moyenne du dresseur */
    vector<Pokemon*> PokemonTeam; /**< L'équipe de Pokémon du dresseur */

public:
    /**
     * @brief Constructeur de la classe Dresseur.
     * @param itsName Le nom du dresseur.
     * @param itslevel Le niveau du dresseur.
     */
    Dresseur(string itsName, int itslevel);

    /**
     * @brief Affiche les informations du dresseur.
     */
    void display();

    /**
     * @brief Ajoute un Pokémon à l'équipe du dresseur.
     * @param p Un pointeur vers le Pokémon à ajouter.
     */
    void addPokemon(Pokemon *p);

    /**
     * @brief Supprime un Pokémon de l'équipe du dresseur.
     * @param choosePokemon L'indice du Pokémon à supprimer.
     */
    void removePokemon(unsigned int choosePokemon);

    /**
     * @brief Attaque un autre dresseur.
     * @param Dresseurennemy Le dresseur ennemi à attaquer.
     */
    void attackDresseur(Dresseur* Dresseurennemy);

    /**
     * @brief Augmente le nombre de points du dresseur.
     */
    void increasePoints();

    /**
     * @brief Augmente le niveau du dresseur.
     */
    void levelUp();

    /**
     * @brief Surcharge de l'opérateur de comparaison supérieur (>).
     * @param Dresseur Le dresseur à comparer.
     * @return True si le dresseur actuel est de niveau supérieur, False sinon.
     */
    bool operator>(Dresseur& Dresseur);

    /**
     * @brief Accesseur pour le nom du dresseur.
     * @return Le nom du dresseur.
     */
    const string &getItsName() const;

    /**
     * @brief Accesseur pour le niveau du dresseur.
     * @return Le niveau du dresseur.
     */
    int getLevel() const;

    /**
     * @brief Accesseur pour le nombre de points du dresseur.
     * @return Le nombre de points du dresseur.
     */
    int getNbpoints() const;

    /**
     * @brief Accesseur pour la vitesse moyenne du dresseur.
     * @return La vitesse moyenne du dresseur.
     */
    float getMedspeed() const;

    /**
     * @brief Accesseur pour l'équipe de Pokémon du dresseur.
     * @return L'équipe de Pokémon du dresseur.
     */
    const vector<Pokemon*> &getPokemonTeam() const;
};




#endif // DRESSEUR_H
