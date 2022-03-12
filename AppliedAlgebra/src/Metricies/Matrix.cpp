#include "Matrix.h"
#include <stdlib.h>

Matrix::Matrix(int rows, int cols)
{
	this->rows = rows;
	this->cols = cols;
	this->matrix = (int* )malloc(sizeof(int) * rows * cols);
}
void Matrix::fillWithZeros()
{
	for (int i=0; i<this->rows*cols; i++)
	{
		matrix[i] = 0;
	}
}
void Matrix::fillWithOnes()
{
	for (int i=0; i < this->rows * cols; i++)
	{
		matrix[i] = 1;
	}
}
void Matrix::printMatrix()
{
	for (int i=0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			std::cout << this->matrix[i * this->cols + j] << " ";
		}
		std::cout << "\n";
	}
}
bool Matrix::isMatrixZero()
{
	for (int i = 0; i < this->rows * this->cols; i++)
	{
		if (this->matrix[i] != 0)
			return false;
	}
	return true;
}
void Matrix::fillWithRange(unsigned int min, unsigned int max)
{
	unsigned int range = max - min + 1;
	for (int i = 0;i < this->rows * this->cols;i++)
	{
		srand(i);
		this->matrix[i] = min + (rand() % range);
	}
}
unsigned int Matrix::isSquared()
{
	return this->rows == this->cols ? SQUARED : NOT_SQUARED;
}
int* Matrix::getMainDiag()
{
	if (this->isSquared() != SQUARED)
	{
		return NULL;
	}
	int* mainDiag = new int[this->rows];
	for (int i = 0; i < rows; i++)
	{
		mainDiag[i] = this->matrix[i * this->cols + i];
		std::cout << mainDiag[i] << std::endl;
	}
	return mainDiag;
}
int* Matrix::getSecDiag(){
	if (this->isSquared() == NOT_SQUARED)
		return NULL;
	int* secondDiag = new int[this->rows];;
	for (int i = 0; i < this->rows; i++)
	{
		secondDiag[i] = this->matrix[this->cols + i * this->rows - i -1];
		std::cout << secondDiag[i] << std::endl;
	}
	return secondDiag;
}
int* Matrix::getMatrix()
{
	return this->matrix;
}
int Matrix::getRows()
{
	return this->rows;
}
int Matrix::getCols()
{
	return this->cols;
}
void Matrix::setValueAtPosition(int value, int row, int col)
{
	this->matrix[(row - 1) * this->cols + col - 1] = value;
}
Matrix* Matrix::getInverse()
{
	Matrix* newMatrix = new Matrix(this->cols, this->rows);
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			int value = this->matrix[i * this->cols + j];
			newMatrix->setValueAtPosition(value, j + 1, i + 1);
		}
	}
	return newMatrix;
}