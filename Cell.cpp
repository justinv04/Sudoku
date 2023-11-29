#include "Cell.h"

Cell::Cell()
{
    ID = 0;
    value = 0;
    currValue = 0;
    possibleValues = {};
    notedValues = {};
}

Cell::Cell(int val, int Id)
{
    ID = Id;
    value = val;
    currValue = 0;
    possibleValues = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    notedValues = {};
}

void Cell::setVal(int val)
{
    value = val;
}

void Cell::setCurrVal(int val)
{
    currValue = val;
}

int Cell::getVal()
{
    return value;
}

int Cell::getCurrVal()
{
    return currValue;
}

vector<int> Cell::getPVals()
{
    return possibleValues;
}

vector<int> Cell::getNVals()
{
    return notedValues;
}