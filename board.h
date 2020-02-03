#ifndef BOARD_H
#define BOARD_H

#include "player.h"

class Board
{
private:
    char freshBoard[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int usedNumbers[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
public:
    Board();
    ~Board();

    void InitializeGame(Player *player1, Player *player2);
    void createPlayers(Player *player1, Player *player2);
    void drawBoard();
    void placeMarks(Player *player1, Player *player2);
    bool isUsed(int num);
    int checkForWin();
    void newGame(Player *player1, Player *player2);
};

#endif