#include "Player.hpp"
#include "Board.hpp"

int Player::counter = 0;

Player::Player(const char name)
{
    if (name == '0') this->name = 'O';
    else if (name == '1') this->name = 'L';
    else this->name = name;
    counter++;
    id = counter;
}
char Player::getPlayerName()
{
    return name;
}

int Player::getPlayerID()
{
    return id;
}

int Player::getPlayerMove(Board board)
{
    heraldThePlayerMove();
    return board.getValidateMove();
}

void Player::heraldThePlayerMove()
{
    std::cout << "Player " << Player::getPlayerID() << " move.\n";
}
