#include "AI.hpp"

AI::AI(const char name, const std::string strategy) : Player(name)
{
    this->strategy = strategy;
    this->name = name;
}

int AI::getPlayerMove(Board board, Player opponent)
{
    heraldThePlayerMove();
    setTheTestingBoard(board);
    setTheAIOpponentName(opponent.getPlayerName());
    if (strategy == "random")
        return getRandomMove();
    else
        return getBestMove();
}

void AI::setTheTestingBoard(Board board)
{
    testingBoard = board;
}

void AI::setTheAIOpponentName(const char opponentName)
{
    this->opponentName = opponentName;
}

int AI::getRandomMove()
{
    int move;
    srand(time(0));
    do
        move = rand() % 9 + 1;
    while (!(testingBoard.isAIMoveValidate(move)));
    return move;
}

int AI::getBestMove()
{
    int bestScore = std::numeric_limits<int>::min();
    struct Move
    {
        int row = -1;
        int col = -1;
        int depth = 0;
    };

    Move currentBestMove;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            if (testingBoard.isGivenFieldEmpty(i, j))
            {
                testingBoard.updateWithCoords(i, j, name);

                std::vector<int> tempScoreAndDepth = minimax(0, std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), false);
                int tempScore = tempScoreAndDepth[0];
                int tempDepth = tempScoreAndDepth[1];

                testingBoard.updateWithCoords(i, j, ' ');

                if (bestScore < tempScore || (bestScore == tempScore && currentBestMove.depth > tempDepth))
                {
                    currentBestMove.row = i;
                    currentBestMove.col = j;
                    currentBestMove.depth = tempDepth;
                    bestScore = tempScore;
                }
            }
        }
    }
    return Board::getFieldID(currentBestMove.row, currentBestMove.col);
}

std::vector<int> AI::minimax(int depth, int alpha, int beta, bool isMaximizerTurn)
{
    int bestScore = evaluateCurrentState();

    if (bestScore == 1 || bestScore == -1 || bestScore == 0)
    {
        ;
    }

    else if (isMaximizerTurn)
    {
        bestScore = std::numeric_limits<int>::min();

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (testingBoard.isGivenFieldEmpty(i, j))
                {
                    testingBoard.updateWithCoords(i, j, name);

                    std::vector<int> tempScoreAndDepth = minimax(depth + 1, alpha, beta, false);
                    int tempScore = tempScoreAndDepth[0];
                    int tempDepth = tempScoreAndDepth[1];

                    testingBoard.updateWithCoords(i, j, ' ');

                    bestScore = std::max(bestScore, tempScore);
                    alpha = std::max(alpha, tempScore);
                    if (beta <= alpha)
                        break;
                }
            }
        }
    }
    else
    {
        bestScore = std::numeric_limits<int>::max();

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (testingBoard.isGivenFieldEmpty(i, j))
                {
                    testingBoard.updateWithCoords(i, j, opponentName);

                    std::vector<int> tempScoreAndDepth = minimax(depth + 1, alpha, beta, true);
                    int tempScore = tempScoreAndDepth[0];
                    int tempDepth = tempScoreAndDepth[1];

                    testingBoard.updateWithCoords(i, j, ' ');

                    bestScore = std::min(bestScore, tempScore);
                    beta = std::min(beta, tempScore);
                    if (beta <= alpha)
                        break;
                }
            }
        }
    }
    std::vector<int> bestScoreAndDepth{bestScore, depth};
    return bestScoreAndDepth;
}

int AI::evaluateCurrentState()
{
    GameMaster gm;
    gm.setTheGameStatus(testingBoard);
    char gameStatus = gm.getTheGameStatus();

    if (gameStatus == 'X')
    {
        return 1;
    }
    else if (gameStatus == 'O')
    {
        return -1;
    }
    else if (testingBoard.isThereFreeField())
        return -2;
    else
        return 0;
}
