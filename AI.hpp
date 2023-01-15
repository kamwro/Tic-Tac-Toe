#ifndef AI_HPP
#define AI_HPP

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <limits>
#include <vector>

#include "Player.hpp"
#include "GameMaster.hpp"
#include "Board.hpp"

class AI : public Player
{
private:
    std::string strategy = "random";
    Board testingBoard;
    char opponentName;

public:
    // Initializes a new instance of the AI class, provided name of the computer player (O or X) and the AI strategy (random or smart).
    AI(const char name, const std::string strategy);

    // Returns a board's field ID (depending on strategy has wrapped getRandomMove() or getBestMove() class method) and announces the computer player move (wrapped heraldThePlayerMove() parent class method).
    int getPlayerMove(Board board, Player opponent);

    // Returns a board's field ID after validation (has wrapped Board isAIMoveValidate() class method).
    // The strategy is based on selecting random free board's field.
    int getRandomMove();

    // Sets the Board object used by the AI class.
    void setTheTestingBoard(Board board);

    // Sets the opponent name used by the AI class.
    void setTheAIOpponentName(const char opponentName);

    // Returns a board's field ID after validation (has wrapped Board isAIMoveValidate() class method).
    // The strategy is based on the Minimax algorithm and it will return best possible move. Also takes in account the depth of the move (moves with the same value will have compared their depths).
    int getBestMove();

    // Minimax function based on the Minimax algorithm with addition of alpha-pruning method to save computational time. The idea is to traverse all the possible moves and get the highest move value. One player is maximizer, which will always choose the best move, and another one is minimizer which will choose the worst move for the maximizer every single time.
    // After searching all the possible moves from the current state, the function will return the best score, when choosing to move there, and its depth.
    std::vector<int> minimax(int depth, int alpha, int beta, bool isMaximizerTurn);

    // Calculates a score value for current state on the board (0 for tie, 1 for maximizer win, -1 for minimizer win, -2 for ongoing game). This is the part of the Minimax algorithm.
    int evaluateCurrentState();
};
#endif