#include<fstream>
#include "Grid.h"
using namespace std;

ifstream f("input.txt");
ofstream g("output.txt");

int main() {
	int number, color;
	Grid grid = Grid();
	f >> number;
	grid.setRows(number);
	f >> number;
	grid.setColumns(number);

	int count;
	f >> count;
	for(int i = 0;i < count; i++){
		f >> number  >> color;
		//This is the answer for level 1
		//g << grid.getPositionOnX(number) << " " << grid.getPositionOnY(number) << " ";
		grid.addDot(color, number);
	}
	for (int i = 1; i <= count / 2; i++) {
		g << grid.manhattanDistance(i) << " ";
	}
	return 0;
}