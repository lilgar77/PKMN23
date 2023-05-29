#ifndef GAME_H
#define GAME_H


#include <iostream>
#include <vector>
#include "dresseur.h"
#include "Pokemon.h"

using namespace std;

/**
 * @class Game
 * Classe représentant un jeu.
 */
class Game {
private:
    vector<Dresseur*> dresseurs; /**< Un vecteur de pointeurs de type Dresseur */
    vector<Pokemon*> pokemons; /**< Un vecteur de pointeurs de type Pokemon */

public:
    /**
     * @brief Constructeur par défaut de la classe Game.
     */
    Game();

    /**
     * @brief Destructeur de la classe Game.
     */
    ~Game();

    /**
     * @brief Méthode pour exécuter le jeu.
     */
    void run();

    /**
     * @brief Affiche le logo du jeu.
     */
    void displaylogo();

    /**
     * @brief Affiche une barre de chargement.
     * @param progress La progression actuelle.
     * @param total La valeur totale de la progression.
     * @param width La largeur de la barre de chargement.
     */
    void afficherBarreDeChargement(int progress, int total, int width);

    /**
     * @brief Ajoute le gagnant au système de base de données.
     * @param winner Le dresseur gagnant à ajouter.
     */
    void addWinnerToDatabase(Dresseur* winner);
};

#endif // GAME_H
