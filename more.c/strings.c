#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

struct card{
    const char* rank;
    const char* suit;
};

void shuffle(struct card deck[52]);
void initDeck(struct card deck[52], char* ranks[13], char* suits[4]);
void printDeck(struct card arr[52]);


int main(int argc, char* argv[]){
    srand(time(NULL));

    char* suits[4] = {"Hearts", "Clubs", "Spades", "Diamonds"};
    char* ranks[13] = {"Deuce", "Ace", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "King", "Queen"};


    struct card deck[52];

    initDeck(deck, ranks, suits);
    printDeck(deck);
    shuffle(deck);

    void (*printDeckPtr)(struct card[]);

    printDeckPtr = printDeck;

    printDeckPtr(deck);

    return 0;
}

void printDeck(struct card arr[52]){
    int k = 0;
    for(int i = 0; i < 13; ++i){
        for(int j = 0; j < 4; ++j){
            printf(" [%-5s of %8s]  ", arr[k].rank, arr[k]. suit);
            ++k;
        }
        puts("");
    }
    puts("");
}

void initDeck(struct card deck[52], char* ranks[13], char* suits[4]){
    for(int i = 0; i < 52; ++i){
        deck[i].rank = ranks[i%13];
        deck[i].suit = suits[i/13];
    }
}

void shuffle(struct card deck[52]){
    for(int i = 0; i < (52*500); ++i){
        int randInt = rand()%52;
            struct card temp = deck[i%52];
            deck[i%52] = deck[randInt];
            deck[randInt] = temp;
    }

}