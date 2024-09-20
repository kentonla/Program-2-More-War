// Name: Kenton La
// CECS 325-01
// Prog 1 - One Card War
// Sep 18, 2024

// I certify that this program is my own original work. I did not copy any part of this program from any other source.
// I further certify that I typed each and every line of code in this program.

#include "card.h"
#include "deck.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime> 
using namespace std;

int main() {
    Deck myDeck;  // creates new deck
    string player1;
    string player2;
    srand(time(0));       //Changes seed of rand() to be used in shuffle()
    cout << "Please enter Player 1's name: ";
    cin >> player1;
    cout << "Please enter Player 2's name: ";
    cin >> player2;
    cout << endl << "Original Deck" << endl;
    myDeck.print();       //Display unshuffeled deck
    myDeck.shuffle();     //Shuffle the deck
    cout << "Shuffled Deck" << endl;
    myDeck.print();       //Display shuffled deck
    
    //stat tracker
    int p1_wins = 0;
    int p2_wins = 0;
    int ties = 0;

    //Play 26 games
    for (int i = 0; i < 26; i++){
        cout << "Game " << i + 1 << endl << "--------" << endl;
        Card p1_card = myDeck.deal();
        Card p2_card = myDeck.deal();
        int result = p1_card.compare(p2_card);
        //Anounce the winner (or tie) of EACH game
        if (result == 1) {
            cout << "\t" << player1 << "=>";
            p1_card.print();
            cout << endl << "\t" << player2 << "=>";
            p2_card.print();
            cout << endl << player1 << "=> Winner" << endl << endl;
            p1_wins++;
        } else if (result == -1) {
            cout << "\t" << player1 << "=>";
            p1_card.print();
            cout << endl << "\t" << player2 << "=>";
            p2_card.print();
            cout << endl << player2 << "=> Winner" << endl << endl;
            p2_wins++;
        } else {
            cout << "\t" << player1 << "=>";
            p1_card.print();
            cout << endl << "\t" << player2 << "=>";
            p2_card.print();
            cout << endl << "Tie game" << endl << endl;
            ties++;
        }
    }

    //After 26 games are played, print the statistics
    cout << endl << "The game has ended!" << endl << "------------------" << endl << "Final Stats:" << endl;
    cout << player1 << " won " << p1_wins << " rounds and lost " << p2_wins << " rounds." << endl;
    cout << player2 << " won " << p2_wins << " rounds and lost " << p1_wins << " rounds." << endl;
    cout << "There were " << ties << " ties." << endl;

    return 0;
}