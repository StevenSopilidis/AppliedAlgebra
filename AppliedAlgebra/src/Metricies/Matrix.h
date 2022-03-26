#include <iostream>

#define SQUARED 1
#define NOT_SQUARED 0

#pragma once
class Matrix
{
private:
	int rows, cols;
	float* matrix;
public:
	Matrix(int rows, int cols);
	void fillWithZeros();
	void fillWithOnes();
	void fillWithRange(float min, float max);
	void printMatrix();
	bool isMatrixZero() const;
	unsigned int isSquared() const;
	float* getMainDiag() const;
	float* getSecDiag() const;
	float* getMatrix() const;
	float getRows() const;
	float getCols() const;
	void setValueAtPosition(float value, int row, int col);
	Matrix* getInverse() const;
	Matrix operator + (const Matrix& matrix) const
	{
		//only perform addition if matricies are of the same size
		if (this->rows != matrix.rows || this->cols != matrix.cols)
		{
			return Matrix(0,0);
		}
		Matrix newMatrix(this->rows, this->cols);
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->cols; j++)
			{
				float* matrix1 = this->matrix;
				float* matrix2 = matrix.matrix;
				float value1 = matrix1[i * this->cols + j];
				float value2 = matrix2[i * this->cols + j];
				newMatrix.setValueAtPosition(value1 + value2, i + 1, j + 1);
			}
		}
		return newMatrix;
	};
	Matrix operator - (const Matrix& matrix) const
	{
		//perform subtraction only if the matix are of the same type
		if (this->rows != matrix.rows || this->cols != matrix.cols)
		{
			return Matrix(0, 0);
		}
		Matrix newMatrix(this->rows, this->cols);
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->cols; j++)
			{
				float* matrix1 = this->matrix;
				float* matrix2 = matrix.matrix;
				float value1 = matrix1[i * this->cols + j];
				float value2 = matrix2[i * this->cols + j];
				newMatrix.setValueAtPosition(value1 - value2, i + 1, j + 1);
			}
		}
		return newMatrix;
	}
	bool operator == (const Matrix& matrix) const
	{
		if (rows != matrix.rows && cols != matrix.cols)
			return false;
		for (int i = 0; i < rows * cols; i++)
		{
			if (this->matrix[i] != matrix.matrix[i])
				return false;
		}
		return true;
	}
	void operator ~() const
	{
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->cols; j++)
			{
				int value = this->matrix[i * this->cols + j];
				this->matrix[i * this->cols + j] = -value;
			}
		}
	}
	bool isStohastic() const;
	bool isTriangleUp() const;
	bool isTriangleDown() const;
	static Matrix* copyMatrix(Matrix* matrixToCopy);

	//fundemental row operations
	void multiplieRow(int row, float l);
	void changeRows(int row1, int row2);
	void addRows(int row1,int row2, float l);

	//fundemental col operations
	void multiplieCol(int col, float l);
	void changeCols(int col1, int col2);
	void addCols(int col1, int col2, float l);	
};

