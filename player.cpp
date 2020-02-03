#include <string>

#include "player.h"

Player::Player(){
    
}

Player::~Player(){

}

void Player::setPlayerName(std::string name){
    playerName = name;
}

std::string Player::getPlayerName(){
    return playerName;
}

// Add 1 point to player's total points
void Player::setPlayerPoints(){
    playerPoints++;
}

int Player::getPlayerPoints(){
    return playerPoints;
}
