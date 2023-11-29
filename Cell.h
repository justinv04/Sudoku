#ifndef CELL_H
#define CELL_H

#include <vector>

using std::vector;

class Cell
{
    private:
        int ID, value, currValue;
        vector<int> possibleValues, notedValues;

    public:
        Cell();
        Cell(int val);
        Cell(int val, int Id);
        void setVal(int val);
        void setCurrVal(int val);
        int getVal();
        int getCurrVal();
        vector<int> getPVals();
        vector<int> getNVals();
};

#endif