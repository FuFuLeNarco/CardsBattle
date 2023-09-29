//
// Created by Le Gall on 28/09/2023.
//

#ifndef CARDSBATTLE_CELLOFCARDS_H
#define CARDSBATTLE_CELLOFCARDS_H
#include "cards.h"

typedef struct CellOfCards{
    Card *card;
    struct CellOfCards *next;
}CellOfCards;

CellOfCards *createCellOfCards(int value, Color color);
void displayCellOfCards(CellOfCards* cellOfCards);
void deleteCellOfCards(CellOfCards** cellOfCards);

#endif //CARDSBATTLE_CELLOFCARDS_H
