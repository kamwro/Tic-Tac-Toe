#include "Game.hpp"

void Game::gameLoopPlayerVsComputer(Player player1, AI player2, Board board, GameMaster gm)
{
    char player1Name = player1.getPlayerName();
    char player2Name = player2.getPlayerName();

    board.print();

    while (true)
    {
        int player1Choice = player1.getPlayerMove(board);
        board.updateWithFieldID(player1Choice, player1Name);
        board.print();
        gm.checkTheGameStatus(board, player1Name, player2Name);

        int player2Choice = player2.getPlayerMove(board, player1);
        board.updateWithFieldID(player2Choice, player2Name);
        board.print();
        gm.checkTheGameStatus(board, player1Name, player2Name);
    }
}

void Game::gameLoopPlayerVsPlayer(Player player1, Player player2, Board board, GameMaster gm)
{
    char player1Name = player1.getPlayerName();
    char player2Name = player2.getPlayerName();

    board.print();

    while (true)
    {
        int player1Choice = player1.getPlayerMove(board);
        board.updateWithFieldID(player1Choice, player1Name);
        board.print();
        gm.checkTheGameStatus(board, player1Name, player2Name);

        int player2Choice = player2.getPlayerMove(board);
        board.updateWithFieldID(player2Choice, player2Name);
        board.print();
        gm.checkTheGameStatus(board, player1Name, player2Name);
    }
}