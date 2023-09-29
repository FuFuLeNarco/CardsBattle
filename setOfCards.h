//
// Created by Le Gall on 28/09/2023.
//

#ifndef CARDSBATTLE_SETOFCARDS_H
#define CARDSBATTLE_SETOFCARDS_H
#include "cellOfCards.h"
#include <time.h>

typedef struct SetOfCards{
    CellOfCards *head;
    CellOfCards *tail;
}SetOfCards;


int lenOfSetOfCards(SetOfCards* setOfCards);
SetOfCards *createEmptySetOfCards();
void addCellOfCardToSetOfCardsByTail(SetOfCards* setOfCards, CellOfCards* cellOfCards);
void displaySetOfCards(SetOfCards* setOfCards);
void deleteSetOfCards(SetOfCards** setOfCards);
void fillSetOfCards(SetOfCards* setOfCards);
void shuffleSetOfCards(SetOfCards* setOfCards);
CellOfCards *pickFirstCellOfCardInSetOfCards(SetOfCards* setOfCards);

#endif //CARDSBATTLE_SETOFCARDS_H
