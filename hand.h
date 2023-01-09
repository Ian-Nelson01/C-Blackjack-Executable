// Ian Nelson
// Nov 15th, 2022
// CS 361
// Assignment 8

// deck.h: Empty .h file

#pragma once  
#include "card.h"
#include "deck.h"
#include <vector>
using namespace std;



class hand {
public:
    hand();
    void addCardToHand(card inputCard);
    void drawHand();
    int handValueLow();
    int handValueHigh();
    
  friend bool operator> (hand& playHand, hand& compHand);
  friend bool operator>= (hand& playHand, hand& compHand);
  friend bool operator< (hand& playHand, hand& compHand);
  friend bool operator<= (hand& playHand, hand& compHand);
  friend bool operator== (hand& playHand, hand& compHand);
  friend bool operator!= (hand& playHand, hand& compHand);

    



private:
    vector<card> handArr;

};