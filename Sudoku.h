#ifndef SUDOKU_H
#define SUDOKU_H

#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <ctime>
#include "Cell.h"

using std::size_t;

class Sudoku
{
    private:
        Cell board[81];
        void randomizeBoard();

    public:
        Sudoku();
        void startGame();
        int getCell(int Id);
        bool isWinner();
};

#endif