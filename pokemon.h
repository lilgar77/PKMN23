#ifndef POKEMON_H
#define POKEMON_H
#include "typeDef.h"
#include <iostream>
using namespace std;

/**
 * @class Pokemon
 * Classe de base représentant un Pokémon.
 */
class Pokemon
{
protected:
    string itsName; /**< Le nom du Pokémon */
    float itsHeight; /**< La hauteur du Pokémon */
    float itsWeight; /**< Le poids du Pokémon */
    int itsLifePoint; /**< Les points de vie du Pokémon */
    int itsCombatPower; /**< Le pouvoir de combat du Pokémon */
    int itsSpeed; /**< La vitesse du Pokémon */
    int itsNbLegs; /**< Le nombre de jambes du Pokémon */
    int itsdemageCalcul; /**< La valeur de calcul des dégâts du Pokémon */
    typePokemon itstype; /**< Le type du Pokémon */

public:
    /**
     * @brief Constructeur de la classe Pokemon.
     * @param name Le nom du Pokémon.
     * @param height La hauteur du Pokémon.
     * @param weight Le poids du Pokémon.
     * @param lifepoint Les points de vie du Pokémon.
     * @param combatpower Le pouvoir de combat du Pokémon.
     * @param nblegs Le nombre de jambes du Pokémon.
     * @param type Le type du Pokémon.
     */
    Pokemon(string name, float height, float weight, int lifepoint, int combatpower, int nblegs, typePokemon type);

    /**
     * @brief Destructeur virtuel de la classe Pokemon.
     */
    virtual ~Pokemon();

    /**
     * @brief Affiche les informations du Pokémon.
     * Méthode virtuelle pure, doit être implémentée dans les classes dérivées.
     */
    virtual void display() = 0;

    /**
     * @brief Attaque un autre Pokémon.
     * Méthode virtuelle pure, doit être implémentée dans les classes dérivées.
     * @param targetPokemon Le Pokémon cible de l'attaque.
     */
    virtual void attack(Pokemon& targetPokemon) = 0;

    /**
     * @brief Récupère les points de vie du Pokémon.
     * @return Les points de vie du Pokémon.
     */
    int getItsLifePoint() const;

    /**
     * @brief Récupère le pouvoir de combat du Pokémon.
     * @return Le pouvoir de combat du Pokémon.
     */
    int getItsCombatPower() const;

    /**
     * @brief Récupère la vitesse du Pokémon.
     * @return La vitesse du Pokémon.
     */
    int getItsSpeed() const;

    /**
     * @brief Récupère le nom du Pokémon.
     * @return Le nom du Pokémon.
     */
    string getItsName() const;

    /**
     * @brief Récupère la hauteur du Pokémon.
     * @return La hauteur du Pokémon.
     */
    float getItsHeight() const;

    /**
     * @brief Récupère le poids du Pokémon.
     * @return Le poids du Pokémon.
     */
    float getItsWeight() const;

    /**
     * @brief Récupère le type du Pokémon.
     * @return Le type du Pokémon.
     */
    typePokemon getItstype() const;

    /**
     * @brief Inflige des dégâts au Pokémon.
     * @param damage Les dégâts infligés.
     */
    void takeDamage(int damage);
};


#endif // POKEMON_H
