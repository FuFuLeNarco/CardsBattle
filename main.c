#include "setOfCards.h"

int main() {
    SetOfCards *fullSetOfCards = createEmptySetOfCards();
    fillSetOfCards(fullSetOfCards);
    displaySetOfCards(fullSetOfCards);
    printf("%d", lenOfSetOfCards(fullSetOfCards));
    shuffleSetOfCards(fullSetOfCards);
    printf("\n");
    displaySetOfCards(fullSetOfCards);
    printf("%d", lenOfSetOfCards(fullSetOfCards));
//    deleteSetOfCards(&fullSetOfCards);
    printf("\n");
    CellOfCards *pickedCards1 = pickFirstCellOfCardInSetOfCards(fullSetOfCards);
    CellOfCards *pickedCards2 = pickFirstCellOfCardInSetOfCards(fullSetOfCards);
    CellOfCards *pickedCards3 = pickFirstCellOfCardInSetOfCards(fullSetOfCards);
    CellOfCards *pickedCards4 = pickFirstCellOfCardInSetOfCards(fullSetOfCards);
    SetOfCards *newSet = createEmptySetOfCards();
    addCellOfCardToSetOfCardsByTail(newSet, pickedCards1);
    addCellOfCardToSetOfCardsByTail(newSet, pickedCards2);
    addCellOfCardToSetOfCardsByTail(newSet, pickedCards3);
    addCellOfCardToSetOfCardsByTail(newSet, pickedCards4);
    displaySetOfCards(fullSetOfCards);
    printf("%d", lenOfSetOfCards(fullSetOfCards));
    displaySetOfCards(newSet);
    printf("%d", lenOfSetOfCards(newSet));
    return 0;
}
