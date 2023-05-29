#include "water.h"
#include "pokemon.h"
#include <random>

Water::Water(string name, float height, float weight, int lifepoint, int combatpower, double speed, int nblegs, typePokemon type)
    :Pokemon(name, height, weight, lifepoint, combatpower, nblegs, type)
{
    itsName = name;
    itsHeight = height;
    itsWeight = weight;
    itsLifePoint = lifepoint;
    itsCombatPower= combatpower;
    itsSpeed = itsWeight * itsNbLegs / 25;
    itsNbLegs = nblegs;
    itstype = PokemonEAU;
}

void Water::display()
{
    cout << "Je suis le Pokemon " << itsName << " (type EAU). Mon poids est de " << itsWeight << " kg, ma vitesse est de " << itsSpeed << " km/h. J'ai " << itsNbLegs << " nageoires, ma taille est de " << itsHeight << "m." << endl;
}


void Water::attack(Pokemon& targetPokemon)
{

    double effectiveness = 1.0;
    if (itstype == PokemonEAU && targetPokemon.getItstype() == PokemonFEU) {
        effectiveness = 2.0;
    } else if (itstype == PokemonEAU && (targetPokemon.getItstype() == PokemonPLANT || targetPokemon.getItstype() == PokemonEAU)) {
        effectiveness = 0.5;
}else {
        effectiveness = 1.0;
        }

    int damage = static_cast<int>(effectiveness * itsCombatPower);

    targetPokemon.takeDamage(damage);
    cout << itsName << " a infligé " << damage << " points de dégâts à " << targetPokemon.getItsName() << " !" << endl;


}
