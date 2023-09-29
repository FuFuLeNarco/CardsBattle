//
// Created by Le Gall on 29/09/2023.
//

#ifndef CARDSBATTLE_CHARACTER_H
#define CARDSBATTLE_CHARACTER_H
#define MAX_LENGTH_NAME 20
#include "setOfCards.h"
#include <string.h>

typedef struct Character{
    char name[MAX_LENGTH_NAME];
    SetOfCards *setOfCards;
}Character;

Character *createCharacterWithEmptySet(char name[MAX_LENGTH_NAME]);
void displayCharacter(Character* character);
void deleteCharacter(Character* character);

#endif //CARDSBATTLE_CHARACTER_H
