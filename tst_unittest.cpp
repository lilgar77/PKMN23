#include <QtTest>
#include "../pokemon/pokemon.h"
#include "../pokemon/feu.h"
#include "../pokemon/electrik.h"
#include "../pokemon/plant.h"
#include "../pokemon/water.h"
#include "QtTest/qtestcase.h"
#include "../pokemon/dresseur.h"

// add necessary includes here

class UnitTest : public QObject
{
    Q_OBJECT
    Pokemon *p1;
    Pokemon *p2;
    Pokemon *p3;
    Pokemon *p4;

public:
    UnitTest();
    ~UnitTest();

private slots:
    void test_getItsLifePoint();
    void test_getItsCombatPower();
    void test_getItsName();
    void test_getItsHeight();
    void test_getItsWeight();
    void test_getItsSpeed();
    void test_getItstype();
    void test_pokemonFeuAttack();
    void test_pokemonWaterAttack();
    void test_pokemonElectrikAttack();
    void test_pokemonPlantAttack();


};

UnitTest::UnitTest()
{
   p1 = new Feu("Salameche", 1, 1562, 100, 50, 2,PokemonFEU );
   p2 = new Water("Carapuce", 1,1255, 100, 50, 1.9, 4, PokemonEAU);


  p3 = new Plant("Bulbizarre", 1, 1562, 100, 50, 0.9, 2, PokemonPLANT);

  p4 = new Electrik("Pikachu",1, 1255, 100, 50, 9, 2,3,PokemonELECTRIK);


}

UnitTest::~UnitTest()
{
    delete p1;
    delete p2;
    delete p3;
    delete p4;

}

void UnitTest::test_getItsLifePoint ()
{
    QCOMPARE(p1->getItsLifePoint(),100);
    QCOMPARE(p2->getItsLifePoint(),100);
    QCOMPARE(p3->getItsLifePoint(),100);
    QCOMPARE(p4->getItsLifePoint(),100);



}
void UnitTest::test_getItsCombatPower()
{
    QCOMPARE(p1->getItsCombatPower(),50);
    QCOMPARE(p2->getItsCombatPower(),50);
    QCOMPARE(p3->getItsCombatPower(),50);
    QCOMPARE(p4->getItsCombatPower(),50);

}
void UnitTest::test_getItsName()
{
    QCOMPARE(p1->getItsName(),"Salameche");
    QCOMPARE(p2->getItsName(),"Carapuce");
    QCOMPARE(p3->getItsName(),"Bulbizarre");
    QCOMPARE(p4->getItsName(),"Pikachu");
}

void UnitTest::test_getItsHeight()
{
    QCOMPARE(p1->getItsHeight(),1);
    QCOMPARE(p2->getItsHeight(),1);
    QCOMPARE(p3->getItsHeight(),1);
    QCOMPARE(p4->getItsHeight(),1);

}

void UnitTest::test_getItsWeight()
{
    QCOMPARE(p1->getItsWeight(),1562);
    QCOMPARE(p2->getItsWeight(),1255);
    QCOMPARE(p3->getItsWeight(),1562);
    QCOMPARE(p4->getItsWeight(),1255);

}


void UnitTest::test_getItsSpeed()
{
    QCOMPARE(p1->getItsSpeed(),93);
    QCOMPARE(p2->getItsSpeed(),200);
    QCOMPARE(p3->getItsSpeed(),0);
    QCOMPARE(p4->getItsSpeed(),0);

}

void UnitTest::test_getItstype()
{
    QCOMPARE(p1->getItstype(),PokemonFEU);
    QCOMPARE(p2->getItstype(),PokemonEAU);
    QCOMPARE(p3->getItstype(),PokemonPLANT);
    QCOMPARE(p4->getItstype(),PokemonELECTRIK);
}
void UnitTest::test_pokemonFeuAttack()
{
    // Test Feu
     // Create a Pokemon Feu
    // Create a trainer with a fire Pokemon
    Dresseur d("Sacha", 1);
    Feu f("Charmander", 0.6, 8.5, 39, 52, 4, PokemonFEU);
    d.addPokemon(&f);

    // Create a water Pokemon for the opponent
    Water e("Carapuce", 1, 1255, 100, 50, 1.9, 4, PokemonEAU);

    // The attack should be super effective and reduce opponent's life points
    int originalLifePoints = e.getItsLifePoint();
    f.attack(e);
    QVERIFY(e.getItsLifePoint() < originalLifePoints);


    // Create an electric Pokemon for the opponent
    Electrik g("Pikachu",1, 1255, 100, 50, 9, 2,3,PokemonELECTRIK);

    // The attack should be not very effective and not reduce opponent's life points
    originalLifePoints = g.getItsLifePoint();
    f.attack(g);
    QVERIFY(g.getItsLifePoint() < originalLifePoints);

    // Create a plant Pokemon for the opponent
    Plant h("Bulbizarre", 1, 1562, 100, 50, 0.9, 2, PokemonPLANT);

    // The attack should be super effective and reduce opponent's life points
    originalLifePoints = h.getItsLifePoint();
    f.attack(h);
    QVERIFY(h.getItsLifePoint() < originalLifePoints);
}

void UnitTest::test_pokemonWaterAttack(){
    // Test Water
     // Create a Pokemon Feu
    // Create a trainer with a fire Pokemon
    Dresseur d("Sacha", 1);
    Water f("Carapuce", 1, 1255, 100, 50, 1.9, 4, PokemonEAU);
    d.addPokemon(&f);

    // Create a water Pokemon for the opponent
    Feu e("Charmander", 0.6, 8.5, 39, 52, 4, PokemonFEU);

    // The attack should be super effective and reduce opponent's life points
    int originalLifePoints = e.getItsLifePoint();
    f.attack(e);
    QVERIFY(e.getItsLifePoint() < originalLifePoints);


    // Create an electric Pokemon for the opponent
    Electrik g("Pikachu",1, 1255, 100, 50, 9, 2,3,PokemonELECTRIK);

    // The attack should be not very effective and not reduce opponent's life points
    originalLifePoints = g.getItsLifePoint();
    f.attack(g);
    QVERIFY(g.getItsLifePoint() < originalLifePoints);

    // Create a plant Pokemon for the opponent
    Plant h("Bulbizarre", 1, 1562, 100, 50, 0.9, 2, PokemonPLANT);

    // The attack should be super effective and reduce opponent's life points
    originalLifePoints = h.getItsLifePoint();
    f.attack(h);
    QVERIFY(h.getItsLifePoint() < originalLifePoints);
}

void UnitTest::test_pokemonElectrikAttack(){
    // Test Electrik
     // Create a Pokemon Feu
    // Create a trainer with a fire Pokemon
    Dresseur d("Sacha", 1);

    Electrik f("Pikachu",1, 1255, 100, 50, 9, 2,3,PokemonELECTRIK);
    d.addPokemon(&f);

    // Create a water Pokemon for the opponent
    Feu e("Charmander", 0.6, 8.5, 39, 52, 4, PokemonFEU);

    // The attack should be super effective and reduce opponent's life points
    int originalLifePoints = e.getItsLifePoint();
    f.attack(e);
    QVERIFY(e.getItsLifePoint() < originalLifePoints);


    // Create an electric Pokemon for the opponent

    Water g("Carapuce", 1, 1255, 100, 50, 1.9, 4, PokemonEAU);
    // The attack should be not very effective and not reduce opponent's life points
    originalLifePoints = g.getItsLifePoint();
    f.attack(g);
    QVERIFY(g.getItsLifePoint() < originalLifePoints);

    // Create a plant Pokemon for the opponent
    Plant h("Bulbizarre", 1, 1562, 100, 50, 0.9, 2, PokemonPLANT);

    // The attack should be super effective and reduce opponent's life points
    originalLifePoints = h.getItsLifePoint();
    f.attack(h);
    QVERIFY(h.getItsLifePoint() < originalLifePoints);
}

void UnitTest::test_pokemonPlantAttack(){
    // Test Plant
     // Create a Pokemon Feu
    // Create a trainer with a fire Pokemon
    Dresseur d("Sacha", 1);


    Plant f("Bulbizarre", 1, 1562, 100, 50, 0.9, 2, PokemonPLANT);
    d.addPokemon(&f);

    // Create a water Pokemon for the opponent
    Feu e("Charmander", 0.6, 8.5, 39, 52, 4, PokemonFEU);

    // The attack should be super effective and reduce opponent's life points
    int originalLifePoints = e.getItsLifePoint();
    f.attack(e);
    QVERIFY(e.getItsLifePoint() < originalLifePoints);


    // Create an electric Pokemon for the opponent

    Water g("Carapuce", 1, 1255, 100, 50, 1.9, 4, PokemonEAU);
    // The attack should be not very effective and not reduce opponent's life points
    originalLifePoints = g.getItsLifePoint();
    f.attack(g);
    QVERIFY(g.getItsLifePoint() < originalLifePoints);

    // Create a plant Pokemon for the opponent
    Electrik h("Pikachu",1, 1255, 100, 50, 9, 2,3,PokemonELECTRIK);
    // The attack should be super effective and reduce opponent's life points
    originalLifePoints = h.getItsLifePoint();
    f.attack(h);
    QVERIFY(h.getItsLifePoint() < originalLifePoints);
}

QTEST_APPLESS_MAIN(UnitTest)

#include "tst_unittest.moc"
