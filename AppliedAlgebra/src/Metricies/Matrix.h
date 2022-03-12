#include <iostream>

#define SQUARED 1
#define NOT_SQUARED 0

#pragma once
class Matrix
{
private:
	int rows, cols;
	int* matrix;
public:
	Matrix(int rows, int cols);
	void fillWithZeros();
	void fillWithOnes();
	void fillWithRange(unsigned int min, unsigned int max);
	void printMatrix();
	bool isMatrixZero();
	unsigned int isSquared();
	int* getMainDiag();
	int* getSecDiag();
	int* getMatrix();
	int getRows();
	int getCols();
	void setValueAtPosition(int value, int row, int col);
	Matrix* getInverse();
};

