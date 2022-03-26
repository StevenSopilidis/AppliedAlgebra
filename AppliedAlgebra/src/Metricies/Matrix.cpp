#include "Matrix.h"
#include <stdlib.h>

Matrix::Matrix(int rows, int cols)
{
	this->rows = rows;
	this->cols = cols;
	this->matrix = new float[rows * cols];
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
bool Matrix::isMatrixZero() const
{
	for (int i = 0; i < this->rows * this->cols; i++)
	{
		if (this->matrix[i] != 0)
			return false;
	}
	return true;
}
void Matrix::fillWithRange(float min, float max)
{
	unsigned int range = max - min + 1;
	for (int i = 0;i < this->rows * this->cols;i++)
	{
		srand(i);
		this->matrix[i] = min + (rand() % range);
	}
}
unsigned int Matrix::isSquared() const
{
	return this->rows == this->cols ? SQUARED : NOT_SQUARED;
}
float* Matrix::getMainDiag() const
{
	if (this->isSquared() != SQUARED)
	{
		return NULL;
	}
	float* mainDiag = new float[this->rows];
	for (int i = 0; i < rows; i++)
	{
		mainDiag[i] = this->matrix[i * this->cols + i];
		std::cout << mainDiag[i] << std::endl;
	}
	return mainDiag;
}
float* Matrix::getSecDiag() const{
	if (this->isSquared() == NOT_SQUARED)
		return NULL;
	float* secondDiag = new float[this->rows];;
	for (int i = 0; i < this->rows; i++)
	{
		secondDiag[i] = this->matrix[this->cols + i * this->rows - i -1];
		std::cout << secondDiag[i] << std::endl;
	}
	return secondDiag;
}
float* Matrix::getMatrix() const
{
	return this->matrix;
}
float Matrix::getRows() const
{
	return this->rows;
}
float Matrix::getCols() const
{
	return this->cols;
}
void Matrix::setValueAtPosition(float value, int row, int col)
{
	this->matrix[(row - 1) * this->cols + col - 1] = value;
}
Matrix* Matrix::getInverse() const
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
bool Matrix::isStohastic() const
{
	if (isSquared() != SQUARED)
		return false;
	int sum = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			sum += matrix[i * cols + j];
		}
		if (sum == 1)
			return false;
	}
	return true;
}
bool Matrix::isTriangleUp() const
{
	if (isSquared() != SQUARED)
		return false;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i > j && matrix[i * cols + j] != 0)
			{
				return false;
			}
		}
	}
	return true;
}
bool Matrix::isTriangleDown() const
{
	if (isSquared() != SQUARED)
	{
		std::cout << "NOt" << std::endl;
		return false;
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i < j && matrix[i * cols + j] != 0)
			{
				return false;
			}
		}
	}
	return true;
}
Matrix* Matrix::copyMatrix(Matrix* matrixToCopy)
{
	int rows = matrixToCopy->getRows();
	int cols= matrixToCopy->getCols();
	float* matrixToCopyValues = matrixToCopy->getMatrix();
	Matrix* copiedMatrix = new Matrix(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			float value = matrixToCopyValues[i * cols + j];
			copiedMatrix->setValueAtPosition(value, i + 1, j + 1);
		}
	}
	copiedMatrix->printMatrix();
	return copiedMatrix;
}
void Matrix::multiplieRow(int row, float l)
{
	if (row <= 0 || row > this->rows)
		return;
	for (int i = 0; i < this->cols; i++)
	{
		this->matrix[(row - 1) * this->cols + i] *= l;
	}
}
void Matrix::changeRows(int row1, int row2)
{
	if (row1 <= 0 || row1 > this->rows || row2 <= 0 || row2 > this->rows)
		return;
	float temp;
	for (int i = 0; i < this->cols; i++)
	{
		temp = this->matrix[(row1 - 1) * this->cols + i];
		this->matrix[(row1 - 1) * this->cols + i] = this->matrix[(row2 - 1) * this->cols + i];
		this->matrix[(row2 - 1) * this->cols + i] = temp;
	}
}
/// <summary>
/// performs row1 + l*row2
/// </summary>
/// <param name="row1">destination row</param>
/// <param name="row2">source row</param>
/// <param name="l">how many time will row2 multiplied before adding to row1</param>
void Matrix::addRows(int row1, int row2, float l)
{
	if (row1 <= 0 || row1 > this->rows || row2 <= 0 || row2 > this->rows)
		return;
	for (int i = 0; i < this->cols; i++)
	{
		this->matrix[(row1 - 1) * this->cols + i] += l * this->matrix[(row2 - 1) * this->cols + i];
	}
}
void Matrix::multiplieCol(int col, float l)
{
	if (col <= 0 || col > this->cols)
		return;
	for (int i = 0; i < this->rows; i++)
	{
		this->matrix[i * this->cols + (col - 1)] *= l;
	}
}
void Matrix::changeCols(int col1, int col2)
{
	if (col1 <= 0 || col1 > this->cols || col2 <= 0 || col2 > this->cols)
		return;
	float temp;
	for (int i = 0; i < this->rows; i++)
	{
		temp = this->matrix[i * this->cols + (col1 - 1)];
		this->matrix[i * this->cols + (col1 - 1)] = this->matrix[i * this->cols + (col2 - 1)];
		this->matrix[i * this->cols + (col2 - 1)] = temp;
	}
}
/// <summary>
/// performs col1 + l*col2
/// </summary>
/// <param name="col1">destination row</param>
/// <param name="col2">source row</param>
/// <param name="l">how many time will col2 multiplied before adding to col1</param>
void Matrix::addCols(int col1, int col2, float l)
{
	if (col1 <= 0 || col1 > this->cols || col2 <= 0 || col2 > this->cols)
		return;
	for (int i = 0; i < this->rows; i++)
	{
		this->matrix[i * this->cols + (col1 - 1)] += l * this->matrix[i * this->cols + (col2 - 1)];
	}
}