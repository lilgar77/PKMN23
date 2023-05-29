#ifndef WATER_H
#define WATER_H
#include "pokemon.h"
#include <iostream>

using namespace std;

/**
 * @class Water
 * Classe représentant un Pokémon de type Eau.
 * Hérite de la classe de base Pokemon.
 */
class Water : public Pokemon
{

public:
    /**
     * @brief Constructeur de la classe Water.
     * @param name Le nom du Pokémon.
     * @param height La hauteur du Pokémon.
     * @param weight Le poids du Pokémon.
     * @param lifepoint Les points de vie du Pokémon.
     * @param combatpower Le pouvoir de combat du Pokémon.
     * @param speed La vitesse du Pokémon dans l'eau.
     * @param nblegs Le nombre de jambes du Pokémon.
     * @param type Le type du Pokémon.
     */
    Water(string name, float height, float weight, int lifepoint, int combatpower, double speed, int nblegs, typePokemon type);

    /**
     * @brief Affiche les informations du Pokémon.
     */
    void display();

    /**
     * @brief Attaque un autre Pokémon.
     * @param targetPokemon Le Pokémon cible de l'attaque.
     */
    void attack(Pokemon& targetPokemon);
};


#endif // WATER_H
