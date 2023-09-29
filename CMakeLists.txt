cmake_minimum_required(VERSION 3.24)
project(CardsBattle C)

set(CMAKE_C_STANDARD 99)

add_executable(CardsBattle main.c cards.c cards.h colors.c colors.h setOfCards.c setOfCards.h cellOfCards.c cellOfCards.h character.c character.h battleOfCards.c battleOfCards.h)
