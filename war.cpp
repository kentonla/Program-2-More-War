// Name: Kenton La
// CECS 325-01
// Prog 2 - More War
// Sep 30, 2024

// I certify that this program is my own original work. I did not copy any part of this program from any other source.
// I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include <ctime> 
using namespace std;

class Card{
    private:
        char rank;
        char suit;

    public:
        // constructor to create a card, setting the suit and rank
        Card(char r, char s){
            rank = r;
            suit = s;
        }

        // display the card example: AC, 10S, KD
        void print(){
            switch (rank) {
                case 'A': cout << 'A'; break;
                case '2': cout << '2'; break;
                case '3': cout << '3'; break;
                case '4': cout << '4'; break;
                case '5': cout << '5'; break;
                case '6': cout <<'6'; break;
                case '7': cout << '7'; break;
                case '8': cout <<'8'; break;
                case '9': cout << '9'; break;
                case 'T': cout << "10"; break;
                case 'J': cout << 'J'; break;
                case 'Q': cout <<'Q'; break;
                case 'K': cout << 'K'; break;
            }
            switch (suit) {
                case 'H': cout << 'H'; break;
                case 'D': cout << 'D'; break;
                case 'C': cout << 'C'; break;
                case 'S': cout << 'S'; break;
            }
        }

        int compare(Card other){
            char ranks[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};        //creates an array of ranks in order
            char p1 = rank;
            char p2 = other.rank;
            int p1_index;
            int p2_index;
            for(int i = 0; i < 13; i++){
                if (p1 == ranks[i]){
                    p1_index = i;
                }
                if (p2 == ranks[i]){
                    p2_index = i;
                }
            }
            // return 1 for win, 0 for tie, -1 for lose
            if (p1_index > p2_index) return 1;
            if (p1_index < p2_index) return -1;
            return 0;
        }
};

class Deck{
    private:
        // use vector to store cards in deck
        vector<Card> pile;
        int topCard;
    // Deck constructor. Creates a deck of 52 cards
    public:
        Deck(){
            char rank;
            char suit;
            topCard = 52;
        // use vector to store cards in deck
            for (int s = 0; s < 4; s++) {
                switch (s) {
                    case 0: suit = 'H'; break;
                    case 1: suit = 'D'; break;
                    case 2: suit = 'C'; break;
                    case 3: suit = 'S'; break;
                }
                for (int r = 0; r < 13; r++) {
                    switch (r) {
                        case 0: rank = 'A'; break;
                        case 1: rank = '2'; break;
                        case 2: rank = '3'; break;
                        case 3: rank = '4'; break;
                        case 4: rank = '5'; break;
                        case 5: rank = '6'; break;
                        case 6: rank = '7'; break;
                        case 7: rank = '8'; break;
                        case 8: rank = '9'; break;
                        case 9: rank = 'T'; break;
                        case 10: rank = 'J'; break;
                        case 11: rank = 'Q'; break;
                        case 12: rank = 'K'; break;
                    }
                    // Card currentCard(rank, suit);
                    pile.push_back(Card(rank, suit));
                }
            }
        }

        // Deals a card by taking a card from the deck
        // Deal a card if possible, otherwise Raise exception if # of games to play is > cards in deck
        Card deal(){
            if (pile.empty()){
                throw runtime_error("Number of games exceeds cards in deck.");
            }
            Card dealtCard = pile.back();
            pile.pop_back();
            --topCard;
            return dealtCard;
        }

        //Shows all the cards in the deck
        void print(){
            for (int i = 0; i < topCard; i++){
                if (i%13 == 0 && i != 0){
                    cout << "\n";
                }
                pile[i].print();
                cout << " ";
            }
            cout << endl << endl;
        }

        //Shuffles the cards in the deck
        void shuffle(){
            for (int i = 0; i < topCard; i++){
                int random = rand() % topCard;
                Card temp = pile[i];
                swap(pile[i], pile[random]);
            }
        }

        //Return true if deck is empty
        bool isEmpty() {
            return pile.empty();
        }
};

int main() {
    Deck myDeck;  // creates new deck
    string player1;
    string player2;
    int gamesToPlay;
    srand(time(0));       //Changes seed of rand() to be used in shuffle()
    cout << "Please enter Player 1's name: ";
    cin >> player1;
    cout << "Please enter Player 2's name: ";
    cin >> player2;
    cout << "How many games will they play? ";
    cin >> gamesToPlay; //if games > (cards in deck / 2) -> raise exception in Deck class (deal() function), main will catch and resolve the exception
    cout << endl << "Original Deck" << endl;
    myDeck.print();       //Display unshuffeled deck
    myDeck.shuffle();     //Shuffle the deck
    cout << "Shuffled Deck" << endl;
    myDeck.print();       //Display shuffled deck
    
    //stat tracker
    int p1_wins = 0;
    int p2_wins = 0;
    int ties = 0;

    //Play x amount of games
    //If games being played is greater than cards in deck, an exception will be thrown
    try{
        for (int i = 0; i < gamesToPlay; i++){
            if(myDeck.isEmpty()) throw runtime_error("Number of games exceeds cards in deck.");
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
    }
    catch (const exception& e){
        cerr << "Exception caught: " << e.what() << endl;
    }

    //After 26 games are played, print the statistics
    cout << endl << "The game has ended!" << endl << "------------------" << endl << "Final Stats:" << endl;
    cout << player1 << " won " << p1_wins << " rounds and lost " << p2_wins << " rounds." << endl;
    cout << player2 << " won " << p2_wins << " rounds and lost " << p1_wins << " rounds." << endl;
    cout << "There were " << ties << " ties." << endl;

    return 0;
}