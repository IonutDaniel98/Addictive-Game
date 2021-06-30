#include "Grid.h"

int Grid::getColumns()
{
    return columns;
}

int Grid::getRows() {
    return rows;
}


void Grid::setRows(int number)
{
    rows = number;
}

void Grid::setColumns(int number)
{
    columns = number;
}

int Grid::getPositionOnX(int number)
{
    int x = 1;
    if (number > columns) {
        x = number / columns;
        if (number % columns > 0) {
            x++;
        }
    }
    return x;
}

int Grid::getPositionOnY(int number)
{
    int y = 1;
    number = number % columns;
    if (number == 0) {
        y = columns;
    }
    if (number > 1) {
        y = number;
    }
    return y;
}

void Grid::addDot(int color, int number)
{
    std::pair<int, int> dot;
    dot.first = color;
    dot.second = number;
    dots.push_back(dot);
}

int Grid::manhattanDistance(int color)
{
    int dist = 0;
    int val1 = 0, val2 = 0;
    bool one = false, two = false;
    for (int i = 0; i < dots.size() && two == false; i++) {
        if (dots[i].first == color) {
            if (one == false) {
                val1 = dots[i].second;
                one = true;
            }
            else if (two == false) {
                val2 = dots[i].second;
                two = true;
            }
        }
    }
    int x1, x2, y1, y2;
    x1 = getPositionOnX(val1);
    y1 = getPositionOnY(val1);
    x2 = getPositionOnX(val2);
    y2 = getPositionOnY(val2);
    int distx = 0;
    int disty = 0;
    distx = x1 - x2;
    disty = y1 - y2;
    if (distx < 0) {
        distx *= -1;
    }
    if (disty < 0) {
       disty *= -1;
    }
    dist = distx + disty;
    return dist;
}

void Grid::initializeGrid()
{
    std::vector<int> row;
    for (int i = 0; i <= columns+1; i++) {
        row.push_back(0);
    }
    for (int j = 0; j <= rows+1; j++) {
        actualGrid.push_back(row);
    }
}

void Grid::completeGrid()
{
    int x, y;

    for (int i = 0; i < dots.size(); i++) {
        x = getPositionOnX(dots[i].second);
        y = getPositionOnY(dots[i].second);
        actualGrid[x][y] = dots[i].first;
    }
}

int Grid::stateOfPosition(int x, int y)
{
    return actualGrid[x][y];
}
