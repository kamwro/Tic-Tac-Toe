#include <iostream>

#include "Board.hpp"
#include "GameMaster.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include "AI.hpp"

int main()
{
    Board board;
    GameMaster gm;
    Game game;
    Player player1('O');

    GameMaster::greetings();

    gm.setGameType();
    int gameType = gm.getGameType();

    switch (gameType)
    {
    case 1:
    {
        Player player2('X');
        game.gameLoopPlayerVsPlayer(player1, player2, board, gm);
        break;
    }
    case 2:
    {
        AI player2('X', "random");
        game.gameLoopPlayerVsComputer(player1, player2, board, gm);
        break;
    }
    case 3:
    {
        AI player2('X', "genius");
        game.gameLoopPlayerVsComputer(player1, player2, board, gm);
        break;
    }
    default:
    {
        Player player2('X');
        game.gameLoopPlayerVsPlayer(player1, player2, board, gm);
        break;
    }
    }
}