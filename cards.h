//
// Created by Le Gall on 28/09/2023.
//

#ifndef CARDSBATTLE_CARDS_H
#define CARDSBATTLE_CARDS_H
#define NAMEMAX 10
#include "colors.h"
#include <stdlib.h>

typedef struct Card{
    int value;
    Color color;
}Card;

char* returnSignWithValue(int value);
Card *createCard(int value, Color color);
void displayCard(Card* card);
void deleteCard(Card** card);

#endif //CARDSBATTLE_CARDS_H
