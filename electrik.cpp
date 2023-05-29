#include "electrik.h"

Electrik::Electrik(string name, float height, float weight, int lifepoint, int combatpower, int nblegs, int wings, int intensity, typePokemon type)
    :Pokemon(name, height,  weight, lifepoint, combatpower, nblegs, type)
{
    itsName = name;
    itsHeight = height;
    itsWeight = weight;
    itsLifePoint = lifepoint;
    itsCombatPower= combatpower;
    itsSpeed = (itsNbLegs + itsWings) * itsIntensity * 0.05;
    itsNbLegs = nblegs;
    itsIntensity = intensity;
    itstype = PokemonELECTRIK;
    itsWings = wings;

}

void Electrik::display()
{
    cout << "Je suis le Pokemon " << itsName << " (type ELECTRIK ). Mon poids est de " << itsWeight << " kg, ma vitesse est de " << itsSpeed << " km/h. J'ai " << itsNbLegs << " pattes, ma taille est de " << itsHeight << "m et mon intensité est de " << itsIntensity << " mA." << endl;
}



void Electrik::attack(Pokemon& targetPokemon)
{
    double effectiveness = 1.0;
    if (itstype == PokemonELECTRIK && targetPokemon.getItstype() == PokemonEAU) {
        effectiveness = 2.0;
    } else if (itstype == PokemonELECTRIK && (targetPokemon.getItstype() == PokemonELECTRIK || targetPokemon.getItstype() == PokemonPLANT)) {
        effectiveness = 0.5;
}else {
        effectiveness = 1.0;
        }

    int damage = static_cast<int>(effectiveness * itsCombatPower);

    targetPokemon.takeDamage(damage);
    cout << itsName << " a infligé " << damage << " points de dégâts à " << targetPokemon.getItsName() << " !" << endl;

}
