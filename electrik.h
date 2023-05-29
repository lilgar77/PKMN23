#ifndef ELECTRIK_H
#define ELECTRIK_H
#include "pokemon.h"
#include "typeDef.h"

/**
 * @class Electrik
 * Classe représentant un Pokémon de type Électrik.
 * Hérite de la classe de base Pokemon.
 */
class Electrik : public Pokemon
{
private:
    int itsIntensity; /**< L'intensité de l'électricité du Pokémon */
    int itsWings; /**< Le nombre d'ailes du Pokémon */

public:
    /**
     * @brief Constructeur de la classe Electrik.
     * @param name Le nom du Pokémon.
     * @param height La hauteur du Pokémon.
     * @param weight Le poids du Pokémon.
     * @param lifepoint Les points de vie du Pokémon.
     * @param combatpower Le pouvoir de combat du Pokémon.
     * @param nblegs Le nombre de jambes du Pokémon.
     * @param wings Le nombre d'ailes du Pokémon.
     * @param intensity L'intensité de l'électricité du Pokémon.
     * @param type Le type du Pokémon.
     */
    Electrik(string name, float height, float weight, int lifepoint, int combatpower, int nblegs, int wings, int intensity, typePokemon type);

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


#endif // ELECTRIK_H
