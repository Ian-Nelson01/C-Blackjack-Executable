
// Ian Nelson
// Nov 15th, 2022
// CS 361
// Assignment 8

 // card.cpp:  Code uses a class file to create playing cards



// Preprocessing Directives
//#pragma once
#include "card.h"




// cards namespace definition with the cardSuit and CardValue enumerated variables


// card suit and value are private


// function creates top and bottom border of card.
void card::xBorder(int num) {
    for (int i = 0; i < num; i++) {
        std::cout << char(205);
    }
}
// adds spaces in middle of card.
void card::yBorder(int num) {
    for (int i = 0; i < num; i++) {
        std::cout << ' ';
    }
}
// created middle of card.
void card::cardMid() {
    for (int i = 0; i < 7; i++) {
        std::cout << char(186);
        yBorder(10);
        std::cout << char(186) << std::endl;
    }
}



// card constructor is public
card::card(cards::cardSuit mySuit, cards::cardValue myValue) {
    setCardValue(myValue);
    setCardSuit(mySuit);
}

// function sets card value
void card::setCardValue(cards::cardValue inputValue) { // changes value
    secretValue = inputValue;
}

// function sets card value
cards::cardValue card::getCardValue() { // returns value
    return secretValue;
}

// function sets card suit
void card::setCardSuit(cards::cardSuit inputSuit) { // changes suit
    secretSuit = inputSuit;
}

// function sets card value
cards::cardSuit card::card::getCardSuit() { // returns value
    return secretSuit;
}

// master function for card drawing.
std::ostream& operator << (std::ostream& os, card& myCard) { // os is overwritten
    // declare char values for cards
    char charValue;
    char charSuit;
    // switch statements assigns chars based on enumeration
    switch (myCard.secretValue) {
    case cards::cardValue::Ace:
        charValue = char(65);
        break;
    case cards::cardValue::Two:
        charValue = char(50);
        break;
    case cards::cardValue::Three:
        charValue = char(51);
        break;
    case cards::cardValue::Four:
        charValue = char(52);
        break;
    case cards::cardValue::Five:
        charValue = char(53);
        break;
    case cards::cardValue::Six:
        charValue = char(54);
        break;
    case cards::cardValue::Seven:
        charValue = char(55);
        break;
    case cards::cardValue::Eight:
        charValue = char(56);
        break;
    case cards::cardValue::Nine:
        charValue = char(57);
        break;
    case cards::cardValue::Ten:
        charValue = char(88);
        break;
    case cards::cardValue::Jack:
        charValue = char(74);
        break;
    case cards::cardValue::Queen:
        charValue = char(81);
        break;
    case cards::cardValue::King:
        charValue = char(75);
        break;
    }
    switch (myCard.secretSuit) {
    case cards::cardSuit::heart:
        charSuit = char(3);
        break;
    case cards::cardSuit::diamond:
        charSuit = char(4);
        break;
    case cards::cardSuit::club:
        charSuit = char(5);
        break;
    case cards::cardSuit::spade:
        charSuit = char(6);
        break;
    }
    // card is drawn
    // top

    os << charValue;
    os << charSuit << endl;
    
    // removes card drawing
   /*
    
    os << char(201);

    //myCard.xBorder(10);
    for (int i = 0; i < 10; i++) {
        os << char(205);
    }

    os << char(187) << std::endl;
    // top label
    os << char(186);
    if (myCard.secretValue == cards::cardValue::Ten) {
        os << char(49) << charValue << charSuit;
    }
    else {
        os << charValue << charSuit << ' ';
    }


    //myCard.yBorder(7);
    for (int i = 0; i < 7; i++) {
        os << ' ';
    }

    os << char(186) << std::endl;
    // body


    //myCard.cardMid();
    for (int i = 0; i < 7; i++) {
        os << char(186);
        //yBorder(10);
        for (int i = 0; i < 10; i++) {
            os << ' ';
        }

        os << char(186) << std::endl;
    }


    // bottom label
    os << char(186);

    //myCard.yBorder(7);
    for (int i = 0; i < 7; i++) {
        os << ' ';
    }

    if (myCard.secretValue == cards::cardValue::Ten) {
        os << char(49) << charValue << charSuit;
    }
    else {
        os << ' ' << charValue << charSuit;
    }
    os << char(186) << std::endl;
    // bottom
    os << char(200);

    //myCard.xBorder(10);
    for (int i = 0; i < 10; i++) {
        os << char(205);
    }


    os << char(188) << std::endl;
    */
    return os;
}


// added default constructor
card::card() {

}


// added getters for card int values and int suits
// making my enums typesafe kinda broke everything.
// this is so sad.
int card::valueConvert() {
    int trueValue = 0;
    switch (secretValue) {
    case cards::cardValue::Ace:
        trueValue = 1;
        break;
    case cards::cardValue::Two:
        trueValue = 2;
        break;
    case cards::cardValue::Three:
        trueValue = 3;
        break;
    case cards::cardValue::Four:
        trueValue = 4;
        break;
    case cards::cardValue::Five:
        trueValue = 5;
        break;
    case cards::cardValue::Six:
        trueValue = 6;
        break;
    case cards::cardValue::Seven:
        trueValue = 7;
        break;
    case cards::cardValue::Eight:
        trueValue = 8;
        break;
    case cards::cardValue::Nine:
        trueValue = 9;
        break;
    case cards::cardValue::Ten:
        trueValue = 10;
        break;
    case cards::cardValue::Jack:
        trueValue = 10;
        break;
    case cards::cardValue::Queen:
        trueValue = 10;
        break;
    case cards::cardValue::King:
        trueValue = 10;
        break;
    }
    return trueValue;
}

int card::suitConvert() {
    int trueValue = 0;
    switch (secretSuit) {
    case cards::cardSuit::heart:
        trueValue = 1;
        break;
    case cards::cardSuit::club:
        trueValue = 2;
        break;
    case cards::cardSuit::diamond:
        trueValue = 3;
        break;
    case cards::cardSuit::spade:
        trueValue = 4;
        break;
    }
    return trueValue;
}



