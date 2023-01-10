#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include "Board.hpp"

class Player
{
protected:
    char name = 'X';
    static int counter;
    int id;

public:
    // Returns the player name.
    char getPlayerName();

    // Returns the player ID.
    int getPlayerID();

    // Initializes a new instance of the Player class, provided the name (X, O or any other symbol). Also generates unique user ID.
    Player(const char name);

    // Returns a board's field ID after validation (has wrapped Board class method getValidateMove()) and announcing the player move (wrapped heraldThePlayerMove() class method).
    int getPlayerMove(Board board);

    // Prints the message about incoming player's move.
    void heraldThePlayerMove();
};

#endif