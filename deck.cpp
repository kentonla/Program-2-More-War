#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "deck.h"
#include "card.h"
using namespace std;

class Deck{
    private:
        Card pile[52];
        int topCard;
    // Deck constructor. Creates a deck of 52 cards
    public:
        Deck::Deck(){
            int index = -1;
            char rank;
            char suit;
            topCard = 52;
            for(int s = 0; s < 4; s++){
                switch (s) {
                    case 0:
                        suit = 'H';
                        break;
                    case 1:
                        suit = 'D';
                        break;
                    case 2:
                        suit = 'C';
                        break;
                    case 3:
                        suit = 'S';
                        break;
                }
                for(int r = 0; r < 13; r++){
                    switch (r) {
                        case 0:
                            rank = 'A';
                            break;
                        case 1:
                            rank = '2';
                            break;
                        case 2:
                            rank = '3';
                            break;
                        case 3:
                            rank = '4';
                            break;
                        case 4:
                            rank = '5';
                            break;
                        case 5:
                            rank = '6';
                            break;
                        case 6:
                            rank = '7';
                            break;
                        case 7:
                            rank = '8';
                            break;
                        case 8:
                            rank = '9';
                            break;
                        case 9:
                            rank = 'T';
                            break;
                        case 10:
                            rank = 'J';
                            break;
                        case 11:
                            rank = 'Q';
                            break;
                        case 12:
                            rank = 'K';
                            break;
                    }
                    // Card currentCard(rank, suit);
                    pile[++index] = Card(rank, suit);
                }
            }
        }

        // Deals a card by taking a card from the deck
        Card Deck::deal(){
            return pile[--topCard];
        }

        //Shows all the cards in the deck
        void Deck::print(){
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
        void Deck::shuffle(){
            for (int i = 0; i < topCard; i++){
                int random = rand() % topCard;
                Card temp = pile[i];
                pile[i] = pile[random];
                pile[random] = temp;
            }
        }
};