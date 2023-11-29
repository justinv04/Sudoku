#include "Sudoku.h"

Sudoku::Sudoku()
{
    int val = 0;
    for(int i = 1; i < 82; i++)
    {
        board[i - 1].setVal(val + 1);

        if(i % 9 == 0)
        {
            if(i % 27 == 0)
                val += 5;
            else
                val += 4;
        }
        else
            val++;

        val %= 9;
    }
}

void Sudoku::startGame()
{
    randomizeBoard();
}

void Sudoku::randomizeBoard()
{
    srand(time(0));
    Cell temp[9];

    int r1, r2, i, j, k;

    for(i = 0; i < 100; i++)
    {
        r1 = rand() % 3;
        r2 = rand() % 3;
        for(j = 0; j < 3; j++)
        {
            for(k = 0; k < 9; k++)
            {
                temp[k] = board[9*(r1 + 3*j) + k];
                board[9*(r1 + 3*j) + k] = board[9*(r2 + 3*j) + k];
                board[9*(r2 + 3*j) + k] = temp[k];
            }

            for(k = 0; k < 9; k++)
            {
                temp[k] = board[9*k + (r1 + 3*j)];
                board[9*k + (r1 + 3*j)] = board[9*k + (r2 + 3*j)];
                board[9*k + (r2 + 3*j)] = temp[k];
            }

        }
        
    }
}

int Sudoku::getCell(int Id)
{
    return board[Id].getVal();
}




