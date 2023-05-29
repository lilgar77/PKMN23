#ifndef FEU_H
#define FEU_H
#include "pokemon.h"
#include <iostream>

using namespace std;



/**
 * @class Feu
 * Classe représentant un Pokémon de type Feu.
 * Hérite de la classe de base Pokemon.
 */
class Feu : public Pokemon
{
public:
    /**
     * @brief Constructeur de la classe Feu.
     * @param name Le nom du Pokémon.
     * @param height La hauteur du Pokémon.
     * @param weight Le poids du Pokémon.
     * @param lifepoint Les points de vie du Pokémon.
     * @param combatpower Le pouvoir de combat du Pokémon.
     * @param nblegs Le nombre de jambes du Pokémon.
     * @param type Le type du Pokémon.
     */
    Feu(string name, float height, float weight, int lifepoint, int combatpower, int nblegs, typePokemon type);

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


#endif // FEU_H
