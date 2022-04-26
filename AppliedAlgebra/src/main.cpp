#include <iostream>
#include "Metricies/Matrix.h"

int main()
{
	Matrix* matrix = new Matrix(10, 10);
	matrix->fillWithRange(10.f, 1243124.f);
	matrix->printMatrix();
	return 0;
}