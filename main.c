#include "setOfCards.h"

int main() {
    SetOfCards *fullSetOfCards = createEmptySetOfCards();
    fillSetOfCards(fullSetOfCards);
    displaySetOfCards(fullSetOfCards);
    shuffleSetOfCards(fullSetOfCards);
    printf("\n");
    displaySetOfCards(fullSetOfCards);
    deleteSetOfCards(&fullSetOfCards);
    return 0;
}
