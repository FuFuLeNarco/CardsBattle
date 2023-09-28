//
// Created by Le Gall on 28/09/2023.
//

#ifndef CARDSBATTLE_COLORS_H
#define CARDSBATTLE_COLORS_H
#include <stdio.h>

typedef enum Color{
    Pique, Coeur, Trefle, Carreau
}Color;

char* returnColorString(Color color);

#endif //CARDSBATTLE_COLORS_H
