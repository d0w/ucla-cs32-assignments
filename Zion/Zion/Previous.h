#ifndef ZION_PREVIOUS_H
#define ZION_PREVIOUS_H

#include "globals.h"

class Previous
{
public:
	Previous(int nRows, int nCols);
	bool dropACrumb(int r, int c);
	void showPreviousMoves() const;

private:
	int m_r;
	int m_c;
	char m_grid[MAXROWS][MAXCOLS];

};

#endif

