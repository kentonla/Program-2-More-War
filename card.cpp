#include <iostream>
#include <string>
#include "card.h"
using namespace std;

// default Card needed for array
Card::Card(){}

// constructor to create a card, setting the suit and rank
Card::Card(char r, char s){
    rank = r;
    suit = s;
}

// display the card example: AC, 10S, KD
void Card::print(){
    switch (rank) {
        case 'A':
            cout << 'A';
            break;
        case '2':
            cout << '2';
            break;
        case '3':
            cout << '3';
            break;
        case '4':
            cout << '4';
            break;
        case '5':
            cout << '5';
            break;
        case '6':
            cout <<'6';
            break;
        case '7':
            cout << '7';
            break;
        case '8':
            cout <<'8';
            break;
        case '9':
            cout << '9';
            break;
        case 'T':
            cout << "10";
            break;
        case 'J':
            cout << 'J';
            break;
        case 'Q':
            cout <<'Q';
            break;
        case 'K':
            cout << 'K';
            break;
    }
    switch (suit) {
        case 'H':
            cout << 'H';
            break;
        case 'D':
            cout << 'D';
            break;
        case 'C':
            cout << 'C';
            break;
        case 'S':
            cout << 'S';
            break;
    }
}

int Card::compare(Card other){
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