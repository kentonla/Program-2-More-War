#ifndef DECK_H
#define DECK_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "card.h"
using namespace std;

class Deck{
    private:
        Card pile[52];
        int topCard;
    
    public:
        Deck();
        Card deal();
        void print();
        void shuffle();
};

#endif