#include "feu.h"

#include <iostream>

using namespace std;



Feu::Feu(string name, float height, float weight, int lifepoint, int combatpower, int nblegs, typePokemon type)
    : Pokemon(name, height, weight, lifepoint, combatpower, nblegs, type)
{
    itsName = name;
    itsHeight = height;
    itsWeight = weight;
    itsLifePoint = lifepoint;
    itsCombatPower= combatpower;
    itsSpeed = itsNbLegs * itsWeight * 0.03;
    itsNbLegs = nblegs;
    itstype = PokemonFEU;

}

void Feu::display()
{
    cout << "Je suis le Pokemon " << itsName << " (type FEU). Mon poids est de " << itsWeight << " kg, ma vitesse est de " << itsSpeed << " km/h. J'ai " << itsNbLegs << " pattes, ma taille est de " << itsHeight << "m." << endl;
}

void Feu::attack(Pokemon& targetPokemon)
{
    double effectiveness = 1.0;
    if (itstype == PokemonFEU && targetPokemon.getItstype() == PokemonPLANT) {
        effectiveness = 2.0;
    } else if (itstype == PokemonFEU && (targetPokemon.getItstype() == PokemonELECTRIK || targetPokemon.getItstype() == PokemonEAU)) {
        effectiveness = 0.5;
}else {
    effectiveness = 1.0;
    }

    int damage = static_cast<int>(effectiveness * itsCombatPower);

    targetPokemon.takeDamage(damage);
    cout << itsName << " a infligé " << damage << " points de dégâts à " << targetPokemon.getItsName() << "!" << endl;
}




