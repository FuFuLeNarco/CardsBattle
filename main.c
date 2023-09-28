#include "cellOfCards.h"

int main() {
    CellOfCards *cellOfCards = createCellOfCards(12, Coeur);
    displayCellOfCards(cellOfCards);
    deleteCellOfCards(&cellOfCards);
    displayCellOfCards(cellOfCards);
    return 0;
}
