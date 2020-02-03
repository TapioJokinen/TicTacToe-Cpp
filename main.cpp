#include <iostream>

#include "board.h"
#include "player.h"

int main(void){

    Board board;
    Player player1;
    Player player2;

    board.InitializeGame(&player1, &player2);

    return 0;
}