#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
private:
    std::string playerName = "";
    int playerPoints = 0;
public:
    Player();
    ~Player();

    void setPlayerName(std::string name);
    std::string getPlayerName();
    void setPlayerPoints();
    int getPlayerPoints();
};




#endif

