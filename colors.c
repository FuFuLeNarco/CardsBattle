//
// Created by Le Gall on 28/09/2023.
//

#include "colors.h"

char* returnColorString(Color color){
    switch (color) {
        case Coeur:
            return "Coeur";
        case Pique:
            return "Pique";
        case Trefle:
            return "Trèfle";
        case Carreau:
            return "Carreau";
    }
}
