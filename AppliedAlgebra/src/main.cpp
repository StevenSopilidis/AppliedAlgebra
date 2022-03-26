#include <iostream>
#include "Metricies/Matrix.h"

int main()
{
	Matrix* matrix = new Matrix(10, 10);
	matrix->fillWithRange(10.f, 1243124.f);
	matrix->printMatrix();
	std::cout << "----------------" << std::endl;
	//matrix->multiplieRow(1, 10.f);
	//matrix->changeRows(1, 4);
	//matrix->addRows(1, 2, 3);
	//matrix->multiplieCol(1, 10.f);
	//matrix->changeCols(1, 5);
	matrix->addCols(1, 3, 2);
	matrix->printMatrix();
	return 0;
}