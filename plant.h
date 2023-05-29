#ifndef PLANT_H
#define PLANT_H

#include "typeDef.h"
#include "pokemon.h"


/**
 * @class Plant
 * Classe représentant un Pokémon de type Plante.
 * Hérite de la classe de base Pokemon.
 */
class Plant : public Pokemon
{
public:
    /**
     * @brief Constructeur de la classe Plant.
     * @param name Le nom du Pokémon.
     * @param height La hauteur du Pokémon.
     * @param weight Le poids du Pokémon.
     * @param lifepoint Les points de vie du Pokémon.
     * @param combatpower Le pouvoir de combat du Pokémon.
     * @param speed La vitesse du Pokémon.
     * @param nblegs Le nombre de jambes du Pokémon.
     * @param type Le type du Pokémon.
     */
    Plant(string name, float height, float weight, int lifepoint, int combatpower, double speed, int nblegs, typePokemon type);

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


#endif // PLANT_H
