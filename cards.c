//
// Created by Le Gall on 28/09/2023.
//

#include "cards.h"

char* returnSignWithValue(int value){
    switch (value) {
        case 11:
            return "Valet";
        case 12:
            return "Dame";
        case 13:
            return "Roi";
        case 14:
            return "As";
        default:
            return "";
    }
}

Card *createCard(int value, Color color){
    Card *newCard = (Card*) malloc(sizeof (Card));
    newCard->value = value;
    newCard->color = color;
    return newCard;
}

void displayCard(Card* card){
    if(card != NULL){
        if(card->value >= 2 && card->value <= 10){
            printf("%d de %s", card->value, returnColorString(card->color));

        }else{
            printf("%s de %s", returnSignWithValue(card->value), returnColorString(card->color));
        }
    }
}

void deleteCard(Card** card){
    free(*card);
    *card = NULL;
}
