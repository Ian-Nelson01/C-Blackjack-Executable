// Ian Nelson
// Nov 15th, 2022
// CS 361
// Assignment 8

 //deck.cpp: Code uses a class file to create A DECK FOR playing cards



// Preprocessing Directives
//#pragma once
//#include <iostream>

#include "deck.h"
#include <time.h>

//#include <algorithm>
using namespace std;

deck::deck() {

    // use a nested forloop to fill vector with one of each card
    int valueCounter = 0;
    int suitCounter = 0;
    while (suitCounter != 4) {
        while (valueCounter != 13) {

            cardArr.push_back(card(cards::cardSuit(suitCounter), cards::cardValue(valueCounter)));
            valueCounter++;
        }
        valueCounter = 0;
        suitCounter++;
    }
}

// returns size of cardArr
int deck::deckSize() {
    return cardArr.size();
}

// dealcard returns a random object of type card, removing it from the vector
card deck::dealCard() {
    srand(time(0));
    std::random_shuffle(cardArr.begin(), cardArr.end());
    card drawn = cardArr[cardArr.size() - 1];
    cardArr.pop_back();
    return drawn;
}


