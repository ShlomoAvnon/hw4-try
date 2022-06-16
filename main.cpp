//
// Created by shlom on 09/06/2022.
//
#include "Mtmchkin.h"
int main(){

    Mtmchkin game("C:\\Users\\shlom\\Desktop\\hw1_project2\\deck.txt");

        while(game.isGameOver()) {
            game.playRound();

        }
}
