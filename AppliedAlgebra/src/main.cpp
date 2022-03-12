#include <iostream>
#include "Metricies/Matrix.h"

int main()
{
	Matrix *matrix = new Matrix(10, 10);
	matrix->fillWithRange(50,245);
	matrix->printMatrix();
	std::cout << "----------------------" << std::endl;
	Matrix* inverseMatrix = matrix->getInverse();
	inverseMatrix->printMatrix();
}