#include<fstream>
#include "Grid.h"
using namespace std;

ifstream f("input.txt");
ofstream g("output.txt");

int main() {
	int number;
	Grid grid = Grid();
	f >> number;
	grid.setRows(number);
	f >> number;
	grid.setColumns(number);

	int count;
	f >> count;
	while (count--) {
		int x = 1;
		int y = 1;
		f >> number;
		if (number > grid.getColumns()) {
			x = number / grid.getColumns();
			if (number % grid.getColumns() > 0) {
				x++;
			}
		}

		number = number % grid.getColumns();
		if (number == 0) {
			y = grid.getColumns();
		}
		if (number > 1) {
			y = number;
		}

		g << x << " " << y << " ";
	}
	return 0;
}