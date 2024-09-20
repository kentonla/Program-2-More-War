#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>
using namespace std;


class Card{
    private:
        char rank;
        char suit;

    public:
        Card();

        Card(char rank, char suit);

        void print();

        int compare(Card);
};

#endif