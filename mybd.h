#ifndef MYBD_H
#define MYBD_H
#include <iostream>

using namespace std;
#include <QtSql/QSqlDatabase>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>

#include "dresseur.h"
/**
 * @class Mybd
 * Classe représentant une base de données pour les dresseurs et les Pokémon.
 */
class Mybd
{
private:
    vector<Dresseur*> dresseurs; /**< Un vecteur de pointeurs de type Dresseur */
    vector<Pokemon*> pokemons; /**< Un vecteur de pointeurs de type Pokemon */
    QSqlDatabase db; /**< Objet représentant la base de données */

public:
    /**
     * @brief Constructeur de la classe Mybd.
     * Initialise une nouvelle instance de la base de données.
     */
    Mybd();

    /**
     * @brief Destructeur de la classe Mybd.
     * Détruit l'instance de la base de données.
     */
    ~Mybd();

    /**
     * @brief Génère un Pokémon aléatoire.
     * Cette méthode génère un Pokémon aléatoire et l'ajoute à la base de données.
     */
    void randompokemon();

    /**
     * @brief Ajoute un dresseur à la base de données.
     * @param dresseur Le dresseur à ajouter.
     * Cette méthode permet d'ajouter un dresseur à la base de données.
     */
    void addDresseur(Dresseur* dresseur);
};


#endif // MYBD_H
