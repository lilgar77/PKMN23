#include "pokemon.h"
#include "typeDef.h"



int Pokemon::getItsLifePoint() const
{
    return itsLifePoint;
}

int Pokemon::getItsCombatPower() const
{
    return itsCombatPower;
}

int Pokemon::getItsSpeed() const
{
    return itsSpeed;
}

string Pokemon::getItsName() const
{
    return itsName;
}

float Pokemon::getItsHeight() const
{
    return itsHeight;
}

float Pokemon::getItsWeight() const
{
    return itsWeight;
}

typePokemon Pokemon::getItstype() const
{
    return itstype;
}

void Pokemon::takeDamage(int damage)
{
    itsLifePoint -= damage;
    if (itsLifePoint < 0)
        {
        itsLifePoint = 0;
        }
    
}

Pokemon::Pokemon(string name, float height, float weight, int lifepoint, int combatpower, int nblegs, typePokemon type)
{
    itsName = name;
    itsHeight = height;
    itsWeight = weight;
    itsLifePoint = lifepoint;
    itsCombatPower= combatpower;
    itsNbLegs = nblegs;
    itstype = type;

}


Pokemon::~Pokemon()
{


}

