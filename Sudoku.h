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
        void setCell(size_t r, size_t c, size_t val);
        bool isFull();
        bool isValid(size_t r, size_t c, size_t val);

    public:
        Sudoku();
        void randomizeBoard();
        bool isWinner();
        int getCell(int Id);
        void startGame();
};

#endif