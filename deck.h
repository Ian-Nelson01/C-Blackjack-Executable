// Ian Nelson
// Nov 15th, 2022
// CS 361
// Assignment 8

// deck.h: Empty .h file

#pragma once
#include "card.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;



class deck {
public:
    deck();
    int deckSize();
    card dealCard();

private:
    vector<card> cardArr;

};