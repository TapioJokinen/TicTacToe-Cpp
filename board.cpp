#include <iostream>
#include <string>

#include "board.h"
#include "player.h"

//Helloadadsddd
std::cout << std::endl;

Board::Board(){
   
}

Board::~Board(){

}

void Board::InitializeGame(Player *player1, Player *player2){

    std::cout << std::endl;
    std::cout << "     Tic-Tac-Toe\n" << std::endl;
 
    while (1)
    {
        createPlayers(player1, player2);
        placeMarks(player1, player2);
        newGame(player1, player2);
    }
 
}

// Draw board to the screen.
void Board::drawBoard(){

    std::cout << std::endl;
    std::cout << "\t" << board[0] << "|" << board[1] << "|" << board[2] << std::endl;
    std::cout << "\t" << board[3] << "|" << board[4] << "|" << board[5] << std::endl;
    std::cout << "\t" << board[6] << "|" << board[7] << "|" << board[8] << "\n" << std::endl;
}

// Ask player to put their mark on the board.
// Draw board again after player's move.
// Check if player has won the game
void Board::placeMarks(Player *player1, Player *player2){

    int markCounter = 0;

    while(1){

        int playerOneChoice = 0;
        int playerTwoChoice = 0;

        drawBoard();

        std::cout << "Player 1, place your mark!(1-9): ";

        // Player 1's turn.
        while (1){

            std::cin >> playerOneChoice;

            if (playerOneChoice == 0 || isUsed(playerOneChoice) == true){
                std::cout << "Number needs to be between 1-9 and it can't be used already! Try again: " << std::endl;
            } else {
                board[playerOneChoice-1] = 'X';
                markCounter++;
                break;
            }
        }
        
        drawBoard();

        // Quit loop if board is full of marks.
        if (markCounter == 9){
            break;
        }

        if (checkForWin() == 1){
            std::cout << "Player 1 has won the game!" << std::endl;
            player1->setPlayerPoints();
            break;
        }

        std::cout << "Player 2, place your mark!(1-9): ";

        // Player 2's turn.
        while (1){

            std::cin >> playerTwoChoice;

            if (playerTwoChoice == 0 || isUsed(playerTwoChoice) == true){
                std::cout << "Number needs to be between 1-9 and it can't be used already! Try again: ";
            } else {
                board[playerTwoChoice-1] = 'O';
                markCounter++;
                break;
            }
        }

        if (checkForWin() == 2){
            drawBoard();
            std::cout << "Player 2 has won the game!" << std::endl;
            player2->setPlayerPoints();
            break;
        }
    }

    if (checkForWin() == 3){
        std::cout << "It's a tie!" << std::endl;
    }
    
}

// Check if player's number is already used.
bool Board::isUsed(int num){

    for (int i = 0; i < 9; i++)
    {
        if (usedNumbers[i] == num){
            return true;
        }
    }
    usedNumbers[num-1] = num;
    return false;
}

// Function returns 1 if Player 1 has won,
// 2 if Player 2 has won 
// or 3 if no one has won yet or it is a tie.
int Board::checkForWin(){

    // Win conditions for Player 1 starts here.
    if (board[0] == 'X' && board[1] == 'X' && board[2] == 'X'){
        return 1;
    } else if(board[3] == 'X' && board[4] == 'X' && board[5] == 'X'){
        return 1;
    } else if(board[6] == 'X' && board[7] == 'X' && board[8] == 'X'){
        return 1;
    } else if(board[0] == 'X' && board[4] == 'X' && board[8] == 'X'){
        return 1;
    } else if(board[2] == 'X' && board[4] == 'X' && board[6] == 'X'){
        return 1;
    } else if(board[0] == 'X' && board[3] == 'X' && board[6] == 'X'){
        return 1;
    } else if(board[1] == 'X' && board[4] == 'X' && board[7] == 'X'){
        return 1;
    } else if(board[2] == 'X' && board[5] == 'X' && board[8] == 'X'){
        return 1;
    }
    // Win conditions for Player 2 starts here.
    else if(board[0] == 'O' && board[1] == 'O' && board[2] == 'O'){
        return 2;
    } else if(board[3] == 'O' && board[4] == 'O' && board[5] == 'O'){
        return 2;
    } else if(board[6] == 'O' && board[7] == 'O' && board[8] == 'O'){
        return 2;
    } else if(board[0] == 'O' && board[4] == 'O' && board[8] == 'O'){
        return 2;
    } else if(board[2] == 'O' && board[4] == 'O' && board[6] == 'O'){
        return 2;
    } else if(board[0] == 'O' && board[3] == 'O' && board[6] == 'O'){
        return 2;
    } else if(board[1] == 'O' && board[4] == 'O' && board[7] == 'O'){
        return 2;
    } else if(board[2] == 'O' && board[5] == 'O' && board[8] == 'O'){
        return 2;
    } else {
        // No one has won yet/tie.
        return 3;
    }
}

// Set names for players.
void Board::createPlayers(Player *player1, Player *player2){

    std::string playerOneName = "";
    std::string playerTwoName = "";

    if (player1->getPlayerName() == ""){
        std::cout << "Create players! Note: player 1 always goes first" << std::endl;
        std::cout << "Give player 1 name: ";
        std::getline(std::cin, playerOneName);
        std::cout << "Give player 2 name: ";
        std::getline(std::cin, playerTwoName);

        player1->setPlayerName(playerOneName);
        player2->setPlayerName(playerTwoName);
        std::cout << std::endl;
        std::cout << "Players created! Player 1, " << player1->getPlayerName() 
                    << ", is X and Player 2, " << player2->getPlayerName() << ", is O!" << std::endl;
    }
    
}

// Print the current score.
// Start a new game and create fresh board
// or quit the program.
void Board::newGame(Player *player1, Player *player2){

    std::string newGame = "";

    std::cout << std::endl;
    std::cout << "Current score: " << player1->getPlayerName() << " |" << player1->getPlayerPoints() << 
                "| - |" << player2->getPlayerPoints() << "| " << player2->getPlayerName() << std::endl;  
    
    while (1)
    {
        std::cout << "Play again?(yes/no): ";
        std::cin >> newGame;

        if (newGame == "no" || newGame == "NO" || newGame == "n" || newGame == "N"){
            exit(1);
        } else if(newGame == "yes" || newGame == "YES" || newGame == "y" || newGame == "Y"){
            for (int i = 0; i < 9; i++){

                board[i] = freshBoard[i];
                usedNumbers[i] = 0;
            }
            
            break;
        } else {
            std::cout << "What?" << std::endl;
        }
    }
}