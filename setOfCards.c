//
// Created by Le Gall on 28/09/2023.
//

#include "setOfCards.h"

int lenOfSetOfCards(SetOfCards* setOfCards){
    int len = 0;
    CellOfCards* temp = setOfCards->head;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }return len;
}

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

void shuffleSetOfCards(SetOfCards* setOfCards) {
    // Initialisation du générateur de nombres aléatoires avec une graine basée sur le temps
    srand((unsigned)time(NULL));
    int len = lenOfSetOfCards(setOfCards);
    // Créez un tableau temporaire pour stocker les pointeurs de cartes
    CellOfCards** cardArray = (CellOfCards**)malloc(len * sizeof(CellOfCards*));
    // Remplissez le tableau avec les pointeurs de cartes
    CellOfCards *temp = setOfCards->head;
    int index = 0;
    while (temp != NULL) {
        cardArray[index++] = temp;
        temp = temp->next;
    }
    // Effectuez le mélange Fisher-Yates
    for (int i = len - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        // Échangez les cartes aux indices i et j dans le tableau
        CellOfCards* temp = cardArray[i];
        cardArray[i] = cardArray[j];
        cardArray[j] = temp;
    }
    // Remettez les cartes mélangées dans la liste chaînée
    setOfCards->head = cardArray[0];
    setOfCards->tail = cardArray[len - 1];
    for (int i = 0; i < len - 1; i++) {
        cardArray[i]->next = cardArray[i + 1];
    }
    cardArray[len - 1]->next = NULL;
    // Libérez la mémoire allouée pour le tableau temporaire
    free(cardArray);
}


