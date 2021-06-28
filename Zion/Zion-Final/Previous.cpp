#include "Previous.h"
#include <iostream>

using namespace std;

Previous::Previous(int nRows, int nCols) : m_r(nRows), m_c(nCols) {
	for (int i = 0; i < m_r; i++) {
		for (int j = 0; j < m_c; j++) {
			m_grid[i][j] = '.';
		}
	}
}

bool Previous::dropACrumb(int r, int c) {
	if (r > MAXROWS || r < 1 || c > MAXCOLS || c < 1) 
		return false;

	if (m_grid[r-1][c-1] == '.') {
		m_grid[r-1][c-1] = 'A';
		return true;
	}
	else if (m_grid[r-1][c - 1] > 'Z') {
		m_grid[r - 1][c - 1] = 'Z';
		return true;
	}
	else {
		m_grid[r - 1][c - 1]++;
		return true;
	}
}

void Previous::showPreviousMoves() const {
	clearScreen();
	for (int i = 0; i < m_r; i++) {
		for (int j = 0; j < m_c; j++) {
			cout << m_grid[i][j];
		}
		cout << "\n";
	}
	cout << endl;
}
