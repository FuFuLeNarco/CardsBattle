//
// Created by Le Gall on 28/09/2023.
//

#include "setOfCards.h"

SetOfCards *createEmptySetOfCards(){
    SetOfCards *newSetOfCards = (SetOfCards*) malloc(sizeof (SetOfCards));
    newSetOfCards->head = NULL;
    newSetOfCards->tail = NULL;
    return newSetOfCards;
}
void addCellOfCardToSetOfCardsByTail(SetOfCards* setOfCards, CellOfCards* cellOfCards){
    if(setOfCards->head == NULL){
        setOfCards->head = cellOfCards;
        setOfCards->tail = cellOfCards;
    }else{
        setOfCards->tail->next = cellOfCards;
        setOfCards->tail = cellOfCards;
    }
}

void displaySetOfCardsRecursivly(CellOfCards* cellOfCards){
    if(cellOfCards != NULL){
        displayCellOfCards(cellOfCards);
        if(cellOfCards->next != NULL){
            printf(", ");
        }else{
            printf("\n");
        }
        displaySetOfCardsRecursivly(cellOfCards->next);
    }
}

void displaySetOfCards(SetOfCards* setOfCards){
    if(setOfCards != NULL){
        displaySetOfCardsRecursivly(setOfCards->head);
    }
}

void deleteSetOfCardsRecursivly(CellOfCards** cellOfCards){
    if(*cellOfCards != NULL){
        deleteSetOfCardsRecursivly(&(*cellOfCards)->next);
        deleteCellOfCards(cellOfCards);
    }
}

void deleteSetOfCards(SetOfCards** setOfCards) {
    deleteSetOfCardsRecursivly(&((*setOfCards)->head));
    free(*setOfCards);
    *setOfCards = NULL;
}

void fillSetOfCards(SetOfCards* setOfCards){
    if(setOfCards->head == NULL){
        for (int i = 1; i < 5; ++i) {
            for (int j = 2; j < 15; ++j) {
                addCellOfCardToSetOfCardsByTail(setOfCards, createCellOfCards(j, i));
            }
        }
    }
}


