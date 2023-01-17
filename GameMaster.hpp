#ifndef GAMEMASTER_HPP
#define GAMEMASTER_HPP

#include <iostream>

#include "Board.hpp"
#include "Player.hpp"
#include "AI.hpp"

class GameMaster
{
private:
    char gameStatus = '1';
    int gameType = 0;

public:
    // Prints the salutations message.
    static void greetings();

    // Sets the game type based on user input (1 - Player vs Player, 2 - Player vs Random Computer, 3 - Player vs Genius Computer).
    void setGameType();

    // Returns the game type (1 - Player vs Player, 2 - Player vs Random Computer, 3 - Player vs Genius Computer).
    int getGameType();

    // Sets the game status using setTheGameStatus() class method, prints appropiate message regarding current game status and possibly terminating the game by invoking gameOver() method.
    void checkTheGameStatus(Board board, char player1Name, char player2Name);

    // evaluates the game status (1 for ongoing game, 0 for draw, player name for player win) by checking if the game is ongoing based on the Board methods (in provided order): getGameStatusForDiagonals(), getGameStatusForRowsAndCols(), isThereFreeField() (for draw).
    void evaluateTheGameStatus(Board board);

    // Returns a game status (1 for ongoing game, 0 for draw, player name for player win).
    char getTheGameStatus();

    // Prints the message about the end of the game, pausing the game waiting for user input, and exiting the program by using exit() function.
    void gameOver();
};

#endif