#include "plant.h"
#include "color.h"

Plant::Plant(string name, float height, float weight, int lifepoint, int combatpower,double speed, int nblegs, typePokemon type)
    :Pokemon(name, height, weight, lifepoint, combatpower, nblegs, type)
{
    itsName = name;
    itsHeight = height;
    itsWeight = weight;
    itsLifePoint = lifepoint;
    itsCombatPower= combatpower;
    itsSpeed = 10 / (itsWeight * itsHeight);
    itsNbLegs = nblegs;
    itstype = PokemonPLANT;

}

void Plant::display()
{
    cout << "Je suis le Pokemon " << itsName << " (type PLANTE)." <<"Mon poids est de " << itsWeight << " kg, ma taille est de " << itsHeight << "m."<< "Ma vitesse est de " << itsSpeed << " km/h." << endl;
}

void Plant::attack(Pokemon& targetPokemon)
{
    double effectiveness = 1.0;
    if (itstype == PokemonPLANT && targetPokemon.getItstype() == PokemonELECTRIK) {
        effectiveness = 2.0;
    } else if (itstype == PokemonPLANT && (targetPokemon.getItstype() == PokemonPLANT || targetPokemon.getItstype() == PokemonFEU)) {
        effectiveness = 0.5;
    }else {
        effectiveness = 1.0;
        }

    int damage = static_cast<int>(effectiveness * itsCombatPower);

    targetPokemon.takeDamage(damage);
    cout << itsName << " a infligé " << damage << " points de dégâts à " << targetPokemon.getItsName() << " !" << endl;




}
