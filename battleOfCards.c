//
// Created by Le Gall on 29/09/2023.
//

#include "battleOfCards.h"

AreaBattle *createAreaBattleByCharacters(Character *character1, Character *character2) {
    AreaBattle *newAreaBattle = (AreaBattle *) malloc(sizeof(AreaBattle));
    newAreaBattle->character1 = character1;
    newAreaBattle->character2 = character2;
    newAreaBattle->baseSetOfCards = createEmptySetOfCards();
    fillSetOfCards(newAreaBattle->baseSetOfCards);
    shuffleSetOfCards(newAreaBattle->baseSetOfCards);
    return newAreaBattle;
}

AreaBattle *createAreaBattleByNames(char *name1, char *name2) {
    AreaBattle *newAreaBattle = (AreaBattle *) malloc(sizeof(AreaBattle));
    newAreaBattle->character1 = createCharacterWithEmptySet(name1);
    newAreaBattle->character2 = createCharacterWithEmptySet(name2);
    newAreaBattle->baseSetOfCards = createEmptySetOfCards();
    fillSetOfCards(newAreaBattle->baseSetOfCards);
    shuffleSetOfCards(newAreaBattle->baseSetOfCards);
    return newAreaBattle;
}

void distributeBaseOfSetToCharacters(AreaBattle *areaBattle) {
    int lenOfBaseSetOfCards = lenOfSetOfCards(areaBattle->baseSetOfCards);
    for (int i = 0; i <= 1; ++i) {
        for (int j = 1; j <= lenOfBaseSetOfCards / 2; ++j) {
            CellOfCards *tempCellOfCards = areaBattle->baseSetOfCards->head;
            areaBattle->baseSetOfCards->head = areaBattle->baseSetOfCards->head->next;
            tempCellOfCards->next = NULL;
            if (i == 0) {
                addCellOfCardToSetOfCardsByTail(areaBattle->character1->setOfCards, tempCellOfCards);
            } else {
                addCellOfCardToSetOfCardsByTail(areaBattle->character2->setOfCards, tempCellOfCards);
            }
            if (lenOfSetOfCards(areaBattle->baseSetOfCards) == 0) {
                areaBattle->baseSetOfCards->head = NULL;
                areaBattle->baseSetOfCards->tail = NULL;
            }
        }
    }
}

void displayAreaBattle(AreaBattle *areaBattle) {
    printf("Les joueurs %s et %s s'affrontent :\n", areaBattle->character1->name, areaBattle->character2->name);
    displayCharacter(areaBattle->character1);
    displayCharacter(areaBattle->character2);
}

void deleteAreaBattleAndCharacters(AreaBattle *areaBattle) {
    deleteCharacter(areaBattle->character1);
    deleteCharacter(areaBattle->character2);
    deleteSetOfCards(areaBattle->baseSetOfCards);
    free(areaBattle);
    areaBattle = NULL;
}

void deleteAreaBattleWithoutDeleteCharacters(AreaBattle *areaBattle) {
    deleteSetOfCards(areaBattle->baseSetOfCards);
    free(areaBattle);
    areaBattle = NULL;
}

void makeOneRound(AreaBattle *areaBattle) {
    Character *winner = NULL;
    while (winner == NULL && lenOfSetOfCards(areaBattle->character1->setOfCards) != 0 &&
           lenOfSetOfCards(areaBattle->character2->setOfCards) != 0) {
        CellOfCards *cellOfCardsOfCharacter1 = pickFirstCellOfCardInSetOfCards(areaBattle->character1->setOfCards);
        CellOfCards *cellOfCardsOfCharacter2 = pickFirstCellOfCardInSetOfCards(areaBattle->character2->setOfCards);
        if (cellOfCardsOfCharacter1->card->value > cellOfCardsOfCharacter2->card->value) {
            winner = areaBattle->character1;
        } else if (cellOfCardsOfCharacter1->card->value < cellOfCardsOfCharacter2->card->value) {
            winner = areaBattle->character2;
        } else {
            winner = NULL;
        }
        printf("Round | %s : ", areaBattle->character1->name);
        displayCellOfCards(cellOfCardsOfCharacter1);
        printf(" and %s : ", areaBattle->character2->name);
        displayCellOfCards(cellOfCardsOfCharacter2);
        printf(" | Winner : ");
        if (winner != NULL) {
            printf("%s\n", winner->name);
            addCellOfCardToSetOfCardsByTail(winner->setOfCards, cellOfCardsOfCharacter1);
            addCellOfCardToSetOfCardsByTail(winner->setOfCards, cellOfCardsOfCharacter2);
            if (lenOfSetOfCards(areaBattle->baseSetOfCards) > 0) {
                addCellOfCardToSetOfCardsByTail(winner->setOfCards, areaBattle->baseSetOfCards->head);
                winner->setOfCards->tail = areaBattle->baseSetOfCards->tail;
                areaBattle->baseSetOfCards->head = NULL;
                areaBattle->baseSetOfCards->tail = NULL;
            }
        } else {
            printf("Battle\n    ");
            addCellOfCardToSetOfCardsByTail(areaBattle->baseSetOfCards, cellOfCardsOfCharacter1);
            addCellOfCardToSetOfCardsByTail(areaBattle->baseSetOfCards, cellOfCardsOfCharacter2);
            CellOfCards *returnCard1 = pickFirstCellOfCardInSetOfCards(areaBattle->character1->setOfCards);
            CellOfCards *returnCard2 = pickFirstCellOfCardInSetOfCards(areaBattle->character1->setOfCards);
            addCellOfCardToSetOfCardsByTail(areaBattle->baseSetOfCards, returnCard1);
            addCellOfCardToSetOfCardsByTail(areaBattle->baseSetOfCards, returnCard2);
            printf("Return Card | %s : ", areaBattle->character1->name);
            displayCellOfCards(returnCard1);
            printf(" and %s : ", areaBattle->character2->name);
            displayCellOfCards(returnCard2);
            if(lenOfSetOfCards(areaBattle->character1->setOfCards) != 0 &&
               lenOfSetOfCards(areaBattle->character2->setOfCards) != 0){
                printf("\n    ");
            }else{
                printf("\n");
            }

        }
    }
    if (lenOfSetOfCards(areaBattle->character1->setOfCards) == 0 ||
        lenOfSetOfCards(areaBattle->character2->setOfCards) == 0) {
        Character *looser = NULL;
        if (lenOfSetOfCards(areaBattle->character1->setOfCards) == 0) {
            winner = areaBattle->character2;
            looser = areaBattle->character1;
        } else {
            winner = areaBattle->character1;
            looser = areaBattle->character2;
        }
        printf("%s has no more cards so %s has won !\n", looser->name, winner->name);
        if (lenOfSetOfCards(areaBattle->baseSetOfCards) > 0) {
            addCellOfCardToSetOfCardsByTail(winner->setOfCards, areaBattle->baseSetOfCards->head);
            winner->setOfCards->tail = areaBattle->baseSetOfCards->tail;
            areaBattle->baseSetOfCards->head = NULL;
            areaBattle->baseSetOfCards->tail = NULL;
        }
    }
}

void makeSeveralRounds(AreaBattle *areaBattle, int numberOfRounds) {
    for (int i = 1; i <= numberOfRounds && lenOfSetOfCards(areaBattle->character1->setOfCards) != 0 &&
                    lenOfSetOfCards(areaBattle->character2->setOfCards) != 0; ++i) {
        makeOneRound(areaBattle);
    }
}

void makeAllRounds(AreaBattle *areaBattle) {
    while (lenOfSetOfCards(areaBattle->character1->setOfCards) != 0 &&
           lenOfSetOfCards(areaBattle->character2->setOfCards) != 0) {
        makeOneRound(areaBattle);
    }
}
