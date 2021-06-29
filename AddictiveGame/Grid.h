#pragma once
#include<utility>
#include<vector>
class Grid
{
private:
	int rows;
	int columns;
	std::vector<std::pair<int, int> > dots;
	std::vector<std::vector<int> > actualGrid;
public:
	int getRows();
	int getColumns();
	void setRows(int number);
	void setColumns(int number);
	int getPositionOnX(int number);
	int getPositionOnY(int number);
	void addDot(int color, int number);
	int manhattanDistance(int color);
	void initializeGrid();
};

