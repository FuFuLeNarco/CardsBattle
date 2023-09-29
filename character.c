//
// Created by Le Gall on 29/09/2023.
//

#include "character.h"

Character *createCharacterWithEmptySet(char* name){
    if(strlen(name) <= 21){
        Character *newCharacter = (Character*) malloc(sizeof (Character));
        strcpy(newCharacter->name, name);
        newCharacter->setOfCards = createEmptySetOfCards();
        return newCharacter;
    }else{
        return NULL;
    }
}

void displayCharacter(Character* character){
    printf("Le joueur %s detient les cartes suivantes :\n", character->name);
    displaySetOfCards(character->setOfCards);
}

void deleteCharacter(Character* character){
    deleteSetOfCards(character->setOfCards);
    free(character);
    character = NULL;
}
