//
// Created by Le Gall on 29/09/2023.
//

#ifndef CARDSBATTLE_BATTLEOFCARDS_H
#define CARDSBATTLE_BATTLEOFCARDS_H
#include "character.h"

typedef struct AreaBattle{
    Character *character1;
    Character *character2;
    SetOfCards *baseSetOfCards;
}AreaBattle;

AreaBattle *createAreaBattleByCharacters(Character* character1, Character* character2);
AreaBattle *createAreaBattleByNames(char* name1, char *name2);
void distributeBaseOfSetToCharacters(AreaBattle* areaBattle);
void displayAreaBattle(AreaBattle* areaBattle);
void deleteAreaBattleAndCharacters(AreaBattle* areaBattle);
void deleteAreaBattleWithoutDeleteCharacters(AreaBattle* areaBattle);
void makeOneRound(AreaBattle* areaBattle);
void makeSeveralRounds(AreaBattle* areaBattle, int numberOfRounds);
void makeAllRounds(AreaBattle* areaBattle);

#endif //CARDSBATTLE_BATTLEOFCARDS_H
