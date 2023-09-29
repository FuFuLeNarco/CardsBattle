//
// Created by Le Gall on 28/09/2023.
//

#ifndef CARDSBATTLE_COLORS_H
#define CARDSBATTLE_COLORS_H
#include <stdio.h>

typedef enum Color{
    Pique = 1, Coeur = 2, Trefle = 3, Carreau = 4
}Color;

char* returnColorString(Color color);

#endif //CARDSBATTLE_COLORS_H
