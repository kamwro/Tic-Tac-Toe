#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>

#include "Player.hpp"
#include "Board.hpp"
#include "AI.hpp"
#include "GameMaster.hpp"

class Game
{
public:
    // Game loop function for Player vs Computer games, invoked after user chooses the game type.
    void gameLoopPlayerVsComputer(Player player1, AI player2, Board board, GameMaster gm);

    // Game loop function for Player vs Player games, invoked after user chooses the game type.
    void gameLoopPlayerVsPlayer(Player player1, Player player2, Board board, GameMaster gm);
};

#endif