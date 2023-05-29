#include "game.h"
#include "QtSql/qsqlerror.h"
#include "color.h"
#include "mybd.h"
#include <thread>
#include <chrono>

Game::Game()
{

}

Game::~Game()
{
    // Supprimer tous les objets pointés par les pointeurs dans le vecteur de Dresseurs
    for (auto dresseur : dresseurs) {
        delete dresseur;
    }

    // Supprimer tous les objets pointés par les pointeurs dans le vecteur de Pokemons
    for (auto pokemon : pokemons) {
        delete pokemon;
    }
}

void Game::run()
{
    // initialisation des bases de données
    Mybd database;
    Mybd database2;


    displaylogo();// affichage du logo

    //demander au joueur les noms des dresseurs

    cout << GREEN << "Entrez votre nom de dresseur:";
    string dresseur1;
    cin >> dresseur1;
    cout<<endl;
    cout << GREEN << "Entrez votre nom de dresseur:";
    string dresseur2;
    cin >> dresseur2;
    cout<<endl;

    // Créer un dresseur
    Dresseur* dresseur = new Dresseur(dresseur1, 1);
    Dresseur* dre = new Dresseur(dresseur2, 2);
    database.addDresseur(dresseur); // Utiliser la méthode addDresseur
    database2.addDresseur(dre); // Utiliser la méthode addDresseur


    // Barre de progression

    int total = 100; // Nombre total d'itérations
    int width = 50; // Largeur de la barre de chargement
    cout<<BLUE<<"Chargement aleatoire des Pokemon"<<endl;

    for (int progress = 0; progress <= total; ++progress) {
        afficherBarreDeChargement(progress, total, width);

        // Simuler un temps de chargement
        this_thread::sleep_for(chrono::milliseconds(50));

    }




    // Générer un Pokémon aléatoire
    for (int var = 0; var < 12; ++var) {
        database.randompokemon();
        database2.randompokemon();
        var += 1;
    }
    //affichage des dresseurs
    dresseur->display();
    dre->display();


//clear le terminal
#if __LINUX__ or __APPLE__
    system("clear");
#else
    system("cls");
#endif


    //boucle du jeu
    while (dresseur->getPokemonTeam().size() > 0 && dre->getPokemonTeam().size() > 0) {

        displaylogo();

        cout << WHITE;
        // Effectuer une attaque entre les dresseurs plus ajouter leurs points
        dresseur->attackDresseur(dre);
        dresseur->increasePoints();
        dresseur->levelUp();
        dre->attackDresseur(dresseur);
        dre->increasePoints();
        dre->levelUp();

        // Afficher les informations du dresseur et de son équipe après l'attaque
        dresseur->display();
        cout<<endl;
        cout<< "------------------------"<<endl;
        dre->display();

        std::this_thread::sleep_for(std::chrono::seconds(1));//permet de faire une pause

//clear du terminal
#if __LINUX__ or __APPLE__
        system("clear");
#else
        system("cls");
#endif


    }

    //affichage du logo et des dresseurs
    displaylogo();
    dresseur->display();
    dre->display();

//clear du terminal
#if __LINUX__ or __APPLE__
    system("clear");
#else
    system("cls");
#endif


    // Vérifier le gagnant et l'ajouter à la base de données
    if (dresseur->getPokemonTeam().empty()) {
        addWinnerToDatabase(dre);
    } else if (dre->getPokemonTeam().empty()) {
        addWinnerToDatabase(dresseur);
    }


    // Libérer la mémoire
    delete dresseur;
    delete dre;







}

void Game::displaylogo(){

    cout << RED << R"(
                                  ,'\
    _.----.        ____         ,'  _\   ___    ___     ____
_,-'       `.     |    |  /`.   \,-'    |   \  /   |   |    \  |`.
\      __    \    '-.  | /   `.  ___    |    \/    |   '-.   \ |  |
 \.    \ \   |  __  |  |/    ,','_  `.  |          | __  |    \|  |
   \    \/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |
    \     ,-'/  /   \    ,'   | \/ / ,`.|         /  /   \  |     |
     \    \ |   \_/  |   `-.  \    `'  /|  |    ||   \_/  | |\    |
      \    \ \      /       `-.`.___,-' |  |\  /| \      /  | |   |
       \    \ `.__,'|  |`-._    `|      |__| \/ |  `.__,'|  | |   |
        \_.-'       |__|    `-._ |              '-.|     '-.| |   |
                                `'                            '-._|
                      Develop by Lilian Garcia
                        \:.             .:/
                         \``._________.''/
                          \             /
                  .--.--, / .':.   .':. \
                 /__:  /  | '::' . '::' |
                    / /   |`.   ._.   .'|
                   / /    |.'         '.|
                  /___-_-,|.\  \   /  /.|
                       // |''\.;   ;,/ '|
                       `==|:=         =:|
                           `.          .'
                             :-._____.-:
                            `''       `''
)" << '\n';

}


void Game::afficherBarreDeChargement(int progress, int total, int width) {

    float ratio = static_cast<float>(progress) / total;
    int barWidth = static_cast<int>(ratio * width);

    cout << "[";
    for (int i = 0; i < width; ++i) {
        if (i < barWidth)
            cout << "=";
        else
            cout << " ";
    }
    cout << "] " << static_cast<int>(ratio * 100.0) << "%\r";
    cout.flush();


}

void Game::addWinnerToDatabase(Dresseur* winner) {
    if (winner != nullptr) {
        cout << YELLOW << "Le gagnant est : " << winner->getItsName() << endl;
        string nom = winner->getItsName();
        int niveau = winner->getLevel();
        cout << WHITE;

        QSqlDatabase db2 = QSqlDatabase::database();
        db2.setDatabaseName("pokemon.db");

        if (db2.open()) {
            QString queryStr = QString("INSERT INTO dresseur (name, level) VALUES ('%1', %2)").arg(QString::fromStdString(nom)).arg(niveau);
            QSqlQuery query = db2.exec(queryStr);

            if (query.isActive()) {
                cout << "Le gagnant a été enregistré dans la base de données." << endl;
            } else {
                cout << "Erreur lors de l'enregistrement du gagnant dans la base de données." << endl;
            }
        } else {
            cout << "La connexion à la base de données n'a pas pu être ouverte." << endl;
        }
    } else {
        cout << "La partie est terminée en égalité." << endl;
    }
}

