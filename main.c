#include "setOfCards.h"

int main() {
    SetOfCards *setOfCards = createEmptySetOfCards();
    CellOfCards *cellOfCards = createCellOfCards(12, Coeur);
    CellOfCards *cellOfCards1 = createCellOfCards(13, Carreau);
    CellOfCards *cellOfCards2 = createCellOfCards(10, Pique);
    CellOfCards *cellOfCards3 = createCellOfCards(5, Trefle);
    addCellOfCardToSetOfCardsByTail(setOfCards, cellOfCards);
    addCellOfCardToSetOfCardsByTail(setOfCards, cellOfCards1);
    addCellOfCardToSetOfCardsByTail(setOfCards, cellOfCards2);
    addCellOfCardToSetOfCardsByTail(setOfCards, cellOfCards3);
    displaySetOfCards(setOfCards);
    deleteSetOfCards(&setOfCards);
    displaySetOfCards(setOfCards);
    SetOfCards *fullSetOfCards = createEmptySetOfCards();
    fillSetOfCards(fullSetOfCards);
    displaySetOfCards(fullSetOfCards);
    deleteSetOfCards(&fullSetOfCards);
    return 0;
}
