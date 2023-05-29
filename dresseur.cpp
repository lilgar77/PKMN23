#include "dresseur.h"
#include "Pokemon.h"
#include "color.h"
#include <iostream>
using namespace std;

const string &Dresseur::getItsName() const
{
    return itsName;
}

int Dresseur::getLevel() const
{
    return itslevel;
}

int Dresseur::getNbpoints() const
{
    return itsnbpoints;
}

float Dresseur::getMedspeed() const
{
    return itsmedspeed;
}

const vector<Pokemon *> &Dresseur::getPokemonTeam() const
{
    return PokemonTeam;
}

Dresseur::Dresseur(string Name, int level)
{
  itsName = Name;
  itslevel = level;

}
bool Dresseur::operator>(Dresseur& other) {
    // On compare le niveau des deux dresseurs
    if (itslevel > other.itslevel) {
        return true;
    }
    else if (itslevel < other.itslevel) {
        return false;
    }
    else {
        cout << "les Dresseur sont egaux"<< endl;
        return true;
    }
}

void Dresseur::display()
{
    cout << "Nom: " <<RED<< itsName << endl;
    cout <<WHITE<< "Niveau: " <<RED<< itslevel << endl;
    cout <<WHITE<< "Points: " <<RED<< itsnbpoints << endl;
    cout <<WHITE<< "Equipe: " << endl;
    cout <<GREEN;
            for (unsigned int i = 0; i < PokemonTeam.size(); i++) {
                cout << "  " << i+1 << ". " << PokemonTeam[i]->getItsName() << endl;
            }
}
void Dresseur::addPokemon(Pokemon *p)
{
    if (PokemonTeam.size() < 7) { // Si l'équipe de Pokemon n'est pas encore complète
        PokemonTeam.push_back(p); // On ajoute le Pokemon à l'équipe
        //itsnbpoints++; // On ajoute 1 point au dresseur
        if (itsnbpoints >= 10) { // Si le dresseur a atteint 10 points
            levelUp(); // On fait évoluer le dresseur
        }
    }
    else {
        cout << "Impossible d'ajouter un nouveau Pokemon, l'equipe est deja complete." << endl;
    }
}

void Dresseur::removePokemon(unsigned int choosePokemon)
{
    // Vérifie si l'indice est valide
    if (choosePokemon < 1 || choosePokemon > PokemonTeam.size()) {
        cout << "Indice invalide." << endl;
        return;
    }

    // Récupère le nom du Pokémon qui va être retiré
    string removedPokemonName = PokemonTeam[choosePokemon-1]->getItsName();

    // Retire le Pokémon de l'équipe
    PokemonTeam.erase(PokemonTeam.begin() + choosePokemon - 1);

    // Affiche un message de confirmation
    cout << "Le Pokémon " << removedPokemonName << " a été retiré de l'équipe." << endl;
}

void Dresseur::attackDresseur(Dresseur* Dresseurennemy)
{
    // Vérifie que le dresseur a au moins un Pokémon dans son équipe
    if (PokemonTeam.empty()) {
        cout << "Vous n'avez pas de Pokémon dans votre équipe." << endl;
            return;
    }

    // Vérifie que l'adversaire a au moins un Pokémon dans son équipe
    if (Dresseurennemy->PokemonTeam.empty()) {
        cout << "L'adversaire n'a pas de Pokémon dans son équipe." << endl;
            return;
    }

    // Trie les Pokémon de chaque équipe par ordre de vitesse décroissante
    sort(PokemonTeam.begin(), PokemonTeam.end(), [](const Pokemon* p1, const Pokemon* p2) {
        return p1->getItsSpeed() > p2->getItsSpeed();
    });

    sort(Dresseurennemy->PokemonTeam.begin(), Dresseurennemy->PokemonTeam.end(), [](const Pokemon* p1, const Pokemon* p2) {
        return p1->getItsSpeed() > p2->getItsSpeed();
    });

    // Détermine le Pokémon le plus rapide de chaque équipe
    Pokemon* firstAttacker = nullptr;
    Pokemon* secondAttacker = nullptr;

    if (PokemonTeam[0]->getItsSpeed() > Dresseurennemy->PokemonTeam[0]->getItsSpeed()) {
        firstAttacker = PokemonTeam[0];
        secondAttacker = Dresseurennemy->PokemonTeam[0];
    } else {
        firstAttacker = Dresseurennemy->PokemonTeam[0];
        secondAttacker = PokemonTeam[0];
    }

    // Récupère les dégâts infligés par le premier attaquant
    firstAttacker->attack(*secondAttacker);

    // Vérifie si le Pokémon de l'adversaire est KO
    if (secondAttacker->getItsLifePoint() <= 0) {
        // Retire le Pokémon KO de l'équipe de l'adversaire
        Dresseurennemy->removePokemon(1);
    }
}




void Dresseur::increasePoints()
{
    itsnbpoints += 10;
    cout << "Les points ont été augmentés de 10." << endl;
}

void Dresseur::levelUp()
{
    if (itsnbpoints >= 10) {
        itslevel++;
        cout << "Le dresseur " << itsName << " est passé au niveau " << itslevel << " !" << endl;
    }
    else {
        cout << "Le dresseur " << itsName << " n'a pas suffisamment de points pour passer au niveau supérieur." << endl;
    }
}
