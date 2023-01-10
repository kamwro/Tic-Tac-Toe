#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <vector>

class Board
{
private:
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

public:
    // Prints the actual board array and the corresponding helper array with field ID's in it.
    void print();

    // Updates the board field with the player name, given the board ID.
    void updateWithFieldID(const int fieldToUpdate, const char name);

    // Updates the board field with the player name, given the row and column coordinates.
    void updateWithCoords(const int row, const int col, const char name);

    // Replaces the current board with another provided board.
    void replace(const char replacementBoard[3][3]);

    // Takes the user input (should be one of the board's fields ID's), validates it and returns it.
    int getValidateMove();

    // Takes an AI move as a desired field number, and returns the info if AI can move to that field.
    bool isAIMoveValidate(const int move);

    // Returns the board's field ID based on the given coordinates.
    static int getFieldID(const int row, const int col);

    // Returns the coordinates of the board's fields, given the field ID.
    static std::vector<int> getCoordinates(const int fieldId);

    // Returns one of the game statuses (1 for ongoing game, D for draw, 0 for player1 win, X for player2 win) based ONLY on the rows and columns situation.
    char getGameStatusForRowsAndCols();

    // Returns one of the game statuses (1 for ongoing game, D for draw, 0 for player1 win, X for player2 win) based ONLY on the diagonals situation.
    char getGameStatusForDiagonals();

    // Returns true if there is at least one free (filled with ' ') field on the board.
    bool isThereFreeField();

    // Returns true if a field of the given coordinates is empty.
    bool isGivenFieldEmpty(const int row, const int col);
};

#endif