// Ian Nelson
// Nov 22th, 2022
// CS 361
// Assignment 9

// main.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include "card.h"
#include "deck.h"
#include "hand.h"


#include <memory>



using namespace std;


// override operators
bool operator> (hand &myHand, hand &dHand){
//cout << "this is one of the lesser moments of all time." << endl;
    int playerTotal = 0;
    if (myHand.handValueHigh() <= 21) {
        playerTotal = myHand.handValueHigh();
    }
    else {
        playerTotal = myHand.handValueLow();
    }

    int dealerTotal = 0;
    if (dHand.handValueHigh() <= 21) {
        dealerTotal = dHand.handValueHigh();
    }
    else {
        dealerTotal = dHand.handValueLow();
    }
return playerTotal > dealerTotal;
}

bool operator< (hand& myHand, hand& dHand){
//cout << "this is one of the greater moments of all time." << endl;
    int playerTotal = 0;
    if (myHand.handValueHigh() <= 21) {
        playerTotal = myHand.handValueHigh();
    }
    else {
        playerTotal = myHand.handValueLow();
    }

    int dealerTotal = 0;
    if (dHand.handValueHigh() <= 21) {
        dealerTotal = dHand.handValueHigh();
    }
    else {
        dealerTotal = dHand.handValueLow();
    }
return playerTotal < dealerTotal;
}

bool operator== (hand& myHand, hand& dHand){
//cout << "this is one of the equal moments of all time." << endl;
    int playerTotal = 0;
    if (myHand.handValueHigh() <= 21) {
        playerTotal = myHand.handValueHigh();
    }
    else {
        playerTotal = myHand.handValueLow();
    }

    int dealerTotal = 0;
    if (dHand.handValueHigh() <= 21) {
        dealerTotal = dHand.handValueHigh();
    }
    else {
        dealerTotal = dHand.handValueLow();
    }
return playerTotal == dealerTotal;
}


int main()
{



    // create deck
    deck theDeck;

    // create player hand
    std::unique_ptr<hand> myHand(new hand());
    // create dealer hand
    std::unique_ptr<hand> dHand(new hand());



    // deal first card
    myHand->addCardToHand(theDeck.dealCard());
    // deal first card
    dHand->addCardToHand(theDeck.dealCard());
    cout << "The dealer's up card is:" << endl;
    dHand->drawHand();
    // deal second card
    myHand->addCardToHand(theDeck.dealCard());
    // deal second card
    dHand->addCardToHand(theDeck.dealCard());


    // draw the hand
    cout << "The player's hand is:" << endl;
    myHand->drawHand();


    // check for blackjack
    if (myHand->handValueHigh() == 21) {
        cout << "Player has a blackjack! " << endl;
    }

    else {

        //String for input
        string inChoice = "hit";


        // loop plays out for players turn. allows players to hit or stay until bust.
        while (inChoice != "n" && inChoice != "out") {
            cout << "Do you wish to hit (y/n)? ";

            cin >> inChoice;
            if (inChoice == "y") {
                myHand->addCardToHand(theDeck.dealCard());
                myHand->drawHand();
            }
            else if (inChoice == "n") {
                break;
            }
            if (myHand->handValueLow() > 21) {
                cout << "The player busted and lost." << endl;
                break;
            }
            
            
            
            int loopPTotal = 0;
            if (myHand->handValueHigh() <= 21) {
            loopPTotal = myHand->handValueHigh();
            }else{
            loopPTotal = myHand->handValueLow();
            }
            if (loopPTotal == 21){
            cout << "The player totaled up to bkackjack." << endl;

            break;
            }
         }
    }


    // dealer makes use of choice string
    string inChoice = "hit";

    // dealer choices in loop, similar to player, loops until bust.
    while (inChoice != "stay" && inChoice != "out") {
        if (dHand->handValueHigh() <= 16) {
            dHand->addCardToHand(theDeck.dealCard());
        }
        else if (dHand->handValueHigh() >= 17 && dHand->handValueHigh() <= 21) {
            inChoice = "stay";

        }

        else if (dHand->handValueLow() > 21) {
            inChoice = "out";
        }

        // if hightotal is above 21, but low is below 21, it freaks out
        else if (dHand->handValueLow() <= 17 && dHand->handValueLow() > 21) {

            dHand->addCardToHand(theDeck.dealCard());
        }
        else {
            inChoice = "stay";
        }

    }

    


 


    // only displays if player has not already busted.

    if (myHand->handValueLow() <= 21) {
        cout << "The dealers hand is:" << endl;
        dHand->drawHand();

    }
    
    // used for testing
   /*
cout << "player hand low value" <<  myHand->handValueLow() << endl;
cout << "player hand high value" << myHand->handValueHigh() << endl;
cout << "comp hand low value" << dHand->handValueLow() << endl;
cout << "comp hand high value" << dHand->handValueHigh() << endl;
*/

// compares player totals using overloads
if ( myHand->handValueLow() <= 21 && dHand->handValueLow() <= 21 && *myHand == *dHand){
                cout << "Push, both player tie." << endl;
}
else if ( myHand->handValueLow() > 21 && dHand->handValueLow() > 21){
        cout << "The dealers hand is:" << endl;
                dHand->drawHand();
                cout << "both players bust" << endl;
}
      else if (dHand->handValueLow() > 21) {
        cout << "Dealer busted -- Player wins!" << endl;
    }
          else if (myHand->handValueLow() > 21) {
        cout << "" << endl;
    } 
   else{
        if (*myHand > *dHand) {
            cout << "Player wins!" << endl;
        }
        else if (*myHand < *dHand) {
            cout << "Dealer wins!" << endl;
        }
        else{
        cout << "this shouldnt happen";
        }
    }






}
