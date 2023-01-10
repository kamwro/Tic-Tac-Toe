#include "Board.hpp"

void Board::print()
{

    std::cout << "  " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "            ";
    std::cout << "  1 | 2 | 3  "
              << " \n";

    std::cout << "  " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "            ";
    std::cout << "  4 | 5 | 6  "
              << " \n";

    std::cout << "  " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "            ";
    std::cout << "  7 | 8 | 9  "
              << " \n";
}

void Board::updateWithFieldID(const int fieldToUpdate, const char name)
{
    std::vector<int> coords = getCoordinates(fieldToUpdate);
    int row = coords[0];
    int col = coords[1];
    board[row][col] = name;
}

void Board::updateWithCoords(const int row, const int col, const char name)
{
    board[row][col] = name;
}

void Board::replace(const char replacementBoard[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = replacementBoard[i][j];
        }
    }
}

int Board::getValidateMove()
{
    int choice = -1;

    while (true)
    {
        std::cout << "choose the empty existing field (1-9): ";
        std::cin >> choice;
        if (choice < 1 || choice > 9)
            continue;
        std::cout << std::endl; // flushing the buffer
        std::vector<int> coords = getCoordinates(choice);
        int row = coords[0];
        int col = coords[1];
        if (board[row][col] == ' ')
        {
            return choice;
        }
    }
}

bool Board::isAIMoveValidate(const int move)
{
    std::vector<int> coords = getCoordinates(move);
    int row = coords[0];
    int col = coords[1];
    if (board[row][col] == ' ')
        return true;
    return false;
}

int Board::getFieldID(const int row, const int col)
{
    switch (row)
    {
    case 0:
        switch (col)
        {
        case 0:
            return 1;
            break;
        case 1:
            return 2;
            break;
        case 2:
            return 3;
            break;
        default:
            return 1;
            break;
        }
        break;
    case 1:
        switch (col)
        {
        case 0:
            return 4;
            break;
        case 1:
            return 5;
            break;
        case 2:
            return 6;
            break;
        default:
            return 1;
            break;
        }
        break;
    case 2:
        switch (col)
        {
        case 0:
            return 7;
            break;
        case 1:
            return 8;
            break;
        case 2:
            return 9;
            break;
        default:
            return 1;
            break;
        }
        break;
    default:
        return 1;
        break;
    }
}

std::vector<int> Board::getCoordinates(const int fieldId)
{
    int row = 4;
    int col = 4;
    static std::vector<int> coords(2, 0);
    switch (fieldId)
    {
    case 1:
        row = 0;
        col = 0;
        break;
    case 2:
        row = 0;
        col = 1;
        break;
    case 3:
        row = 0;
        col = 2;
        break;

    case 4:
        row = 1;
        col = 0;
        break;
    case 5:
        row = 1;
        col = 1;
        break;
    case 6:
        row = 1;
        col = 2;
        break;

    case 7:
        row = 2;
        col = 0;
        break;
    case 8:
        row = 2;
        col = 1;
        break;
    case 9:
        row = 2;
        col = 2;
        break;

    default:
        break;
    }
    coords[0] = row;
    coords[1] = col;
    return coords;
}

char Board::getGameStatusForRowsAndCols()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][0] == board[i][2])
            return board[i][0];
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return board[0][i];
    }
    return '1';
}

char Board::getGameStatusForDiagonals()
{
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] != ' ' && board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return board[1][1];
    return '1';
}

bool Board::isThereFreeField()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
                return true;
        }
    }
    return false;
}

bool Board::isGivenFieldEmpty(const int row, const int col)
{
    if (board[row][col] == ' ')
        return true;
    else
        return false;
}