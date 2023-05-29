#include "mybd.h"
#include "QtSql/qsqlquery.h"
#include "electrik.h"
#include "feu.h"
#include "plant.h"
#include "water.h"
#include "typeDef.h"
#include "dresseur.h"
#include <QtSql/QSqlError>
#include <cstdlib> // pour la fonction rand()
#include <ctime> // pour initialiser le générateur de nombres aléatoires

Mybd::Mybd()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("pokemon.db");

    if (!db.open()) {
        cout << "Connection with database failed: " << db.lastError().text().toStdString() << endl;
    } else {
        cout << "Database connected" << endl;
    }

}

Mybd::~Mybd()
{
    db.close();

}

void Mybd::randompokemon()
{
    QSqlDatabase db = QSqlDatabase::database(); // Obtient une référence à la base de données

    QSqlQuery query(db); // Crée une requête SQL liée à la base de données
    query.exec("SELECT * FROM pokemon ORDER BY RANDOM() LIMIT 1"); // Exécute une requête pour obtenir un Pokémon aléatoire
    int pokemonCount = 0; // Compteur de Pokémon

    if (query.next() && pokemonCount < 6) { // Vérifie s'il y a un résultat de requête et si le nombre de Pokémon est inférieur à 6
        // Récupère les valeurs des colonnes de la table "pokemon" pour le Pokémon sélectionné
        QString name = query.value("name").toString();
        double weight = query.value("weight").toDouble();
        double height = query.value("height").toDouble();
        int nblegs = query.value("nblegs").toInt();
        int maxLifePoints = query.value("lifepoint").toInt();
        double combatPower = query.value("combatpower").toDouble();
        string typeString = query.value("type").toString().toStdString();

        typePokemon type; // Enumération pour représenter le type de Pokémon

        // Convertit la chaîne de caractères "typeString" en valeur de l'énumération "typePokemon"
        if (typeString == "PokemonEAU") {
            type = PokemonEAU;
        } else if (typeString == "PokemonFEU") {
            type = PokemonFEU;
        } else if (typeString == "PokemonELECTRIK") {
            type = PokemonELECTRIK;
        } else if (typeString == "PokemonPLANT") {
            type = PokemonPLANT;
        } else {
            // Gérer les cas non valides si nécessaire
            type = PokemonEAU; // Par défaut, assigner une valeur appropriée
        }

        Pokemon* pokemon = nullptr; // Pointeur vers un objet Pokémon initialisé à nullptr

        // Crée une instance de la classe dérivée de Pokemon en fonction du type
        if (type == PokemonPLANT) {
            double speed = query.value("speed").toDouble();
            pokemon = new Plant(name.toStdString(), height, weight, maxLifePoints, combatPower, speed, nblegs, type);
        } else if (type == PokemonFEU) {
            pokemon = new Feu(name.toStdString(), height, weight, maxLifePoints, combatPower, nblegs, type);
        } else if (type == PokemonELECTRIK) {
            int wings = query.value("wings").toInt();
            int intensity = query.value("intensity").toInt();
            pokemon = new Electrik(name.toStdString(), height, weight, maxLifePoints, combatPower, nblegs, wings, intensity, type);
        } else if (type == PokemonEAU) {
            double speed = query.value("speed").toDouble();
            pokemon = new Water(name.toStdString(), height, weight, maxLifePoints, combatPower, speed, nblegs, type);
        }

        if (pokemon != nullptr) { // Vérifie si la création du Pokémon a réussi
            pokemons.push_back(pokemon); // Ajoute le Pokémon à la liste des Pokémon

            if (!dresseurs.empty()) { // Vérifie si la liste des dresseurs n'est pas vide
                dresseurs[0]->addPokemon(pokemon); // Ajoute le Pokémon au premier dresseur de la liste

                cout << "Random Pokemon: " << name.toStdString() << endl; // Affiche le nom du Pokémon sélectionné
                pokemonCount++; // Incrémente le compteur de Pokémon
            } else {
                cout << "No Dresseurs found." << endl; // Affiche un message si aucun dresseur n'est trouvé
            }
        } else {
            cout << "Failed to create Pokemon." << endl; // Affiche un message si la création du Pokémon a échoué
        }
    }
}


void Mybd::addDresseur(Dresseur* dresseur) {
    dresseurs.push_back(dresseur);
}



