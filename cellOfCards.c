//
// Created by Le Gall on 28/09/2023.
//

#include "cellOfCards.h"

CellOfCards *createCellOfCards(int value, Color color){
    CellOfCards *newCellOfCards = (CellOfCards*) malloc(sizeof (CellOfCards));
    newCellOfCards->card = createCard(value, color);
    newCellOfCards->next = NULL;
    return newCellOfCards;
}
void displayCellOfCards(CellOfCards* cellOfCards){
    if(cellOfCards != NULL){
        displayCard(cellOfCards->card);
    }
}
void deleteCellOfCards(CellOfCards* cellOfCards){
    deleteCard(cellOfCards->card);
    free(cellOfCards);
    cellOfCards = NULL;
}
