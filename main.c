#include "cards.h"

int main() {
    Card *card = createCard(10, Pique);
    displayCard(card);
    deleteCard(&card);
    displayCard(card);
    return 0;
}
