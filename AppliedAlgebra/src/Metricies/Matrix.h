#include <iostream>

#define SQUARED 1
#define NOT_SQUARED 0

#pragma once
class Matrix
{
private:
	unsigned int rows, cols;
	float* matrix;
public:
	Matrix(int rows, int cols);
	/// <summary>
	/// fills the matrix with zeroes
	/// </summary>
	void fillWithZeros();
	/// <summary>
	/// fiils the matrix with ones
	/// </summary>
	void fillWithOnes();
	/// <summary>
	/// fills the matrix with values withing a given range
	/// </summary>
	/// <param name="min">lower bound of the range</param>
	/// <param name="max">upper bound  of the range</param>
	void fillWithRange(float min, float max);
	/// <summary>
	/// prints the matrix to the console
	/// </summary>
	void printMatrix();
	/// <summary>
	/// checks if the matrix is a zero matrix
	/// </summary>
	/// <returns> boolean indicating wether the matrix a zero matrix</returns>
	bool isMatrixZero() const;
	/// <summary>
	/// checks if the matrix is squared
	/// </summary>
	/// <returns> returns SQUARED if the metrix is squared else returns NOT_SQUARED </returns>
	unsigned int isSquared() const;
	/// <summary>
	/// gets the main diagonal of the matrix
	/// if its squared
	/// </summary>
	/// <returns> returns an array containing the elements of the main diagonal </returns>
	float* getMainDiag() const;
	/// <summary>
	/// gets the secondary diagonnal of the matrix
	/// if its squared
	/// </summary>
	/// <returns> returns an array containing the elements of the secondary diagonal </returns>
	float* getSecDiag() const;
	/// <summary>
	/// get the matrix
	/// </summary>
	/// <returns> returns the matrix </returns>
	float* getMatrix() const;
	/// <summary>
	/// gets the number of rows of the matrix
	/// </summary>
	/// <returns> returns the number of rows </returns>
	unsigned int getRows() const;
	/// <summary>
	/// gets the number of cols of the matrix
	/// </summary>
	/// <returns> returns the number of cols </returns>
	unsigned int getCols() const;
	/// <summary>
	/// sets the value of an element within the matrix
	/// </summary>
	/// <param name="value"> value we want to set </param>
	/// <param name="row"> row of the element </param>
	/// <param name="col"> col of the element </param>
	void setValueAtPosition(float value, int row, int col);
	/// <summary>
	/// gets the inverse of the current matrix
	/// </summary>
	/// <returns> returns a matrix representing the inverse of the matrix </returns>
	Matrix* getInverse() const;
	/// <summary>
	/// adds two matricies
	/// </summary>
	/// <param name="matrix">matrix to add</param>
	/// <returns> returs the sum Matrix </returns>
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
	/// <summary>
	/// subtracts two matricies
	/// </summary>
	/// <param name="matrix"> matrix to subtract </param>
	/// <returns> returns subtract Matrix </returns>
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
	/// <summary>
	/// checks if two matricies are equal
	/// </summary>
	/// <param name="matrix"> matrix to compare to </param>
	/// <returns> returns a boolean indicating wether the matricies are the same </returns>
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
	/// <summary>
	/// turns the current matrix to its opposite
	/// </summary>
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
	/// <summary>
	/// checks if the current matrix is stohastic
	/// </summary>
	/// <returns> returns boolean indicating wether the matrix is stohastic </returns>
	bool isStohastic() const;
	/// <summary>
	/// checks if the matrix is triangleUp
	/// </summary>
	/// <returns>returns boolean indicating wether the matrix is triangle up</returns>
	bool isTriangleUp() const;
	/// <summary>
	/// checks if the matrix is triangleUp
	/// </summary>
	/// <returns>returns boolean indicating wether the matrix is triangle up</returns>
	bool isTriangleDown() const;
	/// <summary>
	/// returns a copie of a matrix
	/// </summary>
	/// <param name="matrixToCopy"> Matrix to copy </param>
	/// <returns> returns the copy of the passed matrix </returns>
	static Matrix* copyMatrix(Matrix* matrixToCopy);

	//fundemental row operations

	/// <summary>
	/// multiple a row with a value
	/// </summary>
	/// <param name="row">row to multiplie </param>
	/// <param name="l">value to use</param>
	void multiplieRow(int row, float l);
	/// <summary>
	/// changes the position of two rows
	/// </summary>
	/// <param name="row1">first row</param>
	/// <param name="row2">second row</param>
	void changeRows(int row1, int row2);
	/// <summary>
	/// adds to a row another row multipled by a value
	/// </summary>
	/// <param name="row1">row1</param>
	/// <param name="row2">row2 (row we are a adding)</param>
	/// <param name="l">value to multiplie  row2</param>
	void addRows(int row1,int row2, float l);

	//fundemental col operations
	void multiplieCol(int col, float l);
	void changeCols(int col1, int col2);
	void addCols(int col1, int col2, float l);	
};

