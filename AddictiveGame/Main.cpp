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
	// This is the answer for level 2
	/*for (int i = 1; i <= count / 2; i++) {
		g << grid.manhattanDistance(i) << " ";
	}*/
	grid.initializeGrid();
	grid.completeGrid();
	f >> count;
	while (count--) {
		f >> color;
		int start, dist;
		f >> start >> dist;
		char dir;
		int x, y;
		x = grid.getPositionOnX(start);
		y = grid.getPositionOnY(start);
		int fineRoad = 0;
		bool fine = true;
		while (dist--) {
			f >> dir;
			if (fine == true) {
				fineRoad++;
				if (dir == 'N') {
					x--;
				}
				else if (dir == 'S') {
					x++;
				}
				else if (dir == 'E') {
					y++;
				}
				else {
					y--;
				}

				if (x<1 || y<1 || x>grid.getRows() || y>grid.getColumns()) {
					fine = false;
					if (fine == true) {
						if (grid.stateOfPosition(x, y) > 0 && grid.stateOfPosition(x, y) != color) {
							fine = false;
						}
					}
				}
			}	
		}
		if (fine == false || grid.stateOfPosition(x, y) != color) {
			g << -1 << " ";
		}
		else {
			g << 1 << " ";
		}
		g << fineRoad << " ";
	}
	return 0;
}