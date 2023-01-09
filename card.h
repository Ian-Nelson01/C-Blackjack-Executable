// Ian Nelson
// Nov 15th, 2022
// CS 361
// Assignment 8

// deck.h: Empty .h file


#include <iostream>
#include <ostream>
#pragma once
using namespace std;


// cards namespace definition with the cardSuit and CardValue enumerated variables
namespace cards {
    enum class cardSuit {
        spade, heart, diamond, club
    };
    enum class cardValue {
        Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King
    };
}


class card {
public:
    card(cards::cardSuit mySuit, cards::cardValue myValue);
    card();

    void setCardValue(cards::cardValue inputValue); // changes value
    cards::cardValue getCardValue();

    void setCardSuit(cards::cardSuit inputSuit); // changes value
    cards::cardSuit getCardSuit();

    friend std::ostream& operator << (std::ostream& os, card& myCard); // os is overwritten
    int valueConvert();
    int suitConvert();





private:
    cards::cardSuit secretSuit;
    cards::cardValue secretValue;

    void xBorder(int num);
    void yBorder(int num);
    void cardMid();


};