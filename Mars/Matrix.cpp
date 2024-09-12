#include "Matrix.h"
#include <iostream>

Matrix::Matrix() 
{
	array = new double* [rows];
	for (int i = 0; i < rows; i++)
	{ 
		array[i] = new double[cols];
		for (int j = 0; j < cols; j++)
		{
			array[i][j] = 0;	
		}
	}
	std::cout << "Default Matrix is made!" << std::endl;
}
Matrix::Matrix(int r, int c) : rows(r),cols(c)
{
	if(rows < 1 || cols < 1)
	{
		throw std::exception("Wrong input! Arguments must be 1 or higher!");
	}
	array = new double* [rows];
	for (int i = 0; i < rows; i++)
	{
		array[i] = new double[cols];
		for (int j = 0; j < cols; j++)
		{
			array[i][j] = 0;
		}
	}
	std::cout << "Custom Matrix is made!" << std::endl;
}
Matrix::Matrix(const Matrix& ref)
{
	
	*this = ref;
}
Matrix::Matrix(Matrix&& doubleref) noexcept
{
	*this = std::move(doubleref);
}
Matrix::~Matrix()
{
	this->matrix_delete();
	if (rows == 3 && cols == 3) 
	{
		std::cout << "DEFAULT Matrix was deleted!" << std::endl;
	}
	else
	{
		std::cout << "CUSTOM Matrix with " << rows << " rows and " << cols << " cols " << "was deleted!" << std::endl;
	}
}
void Matrix::matrix_delete()
{
	if (array != nullptr)
	{
		for (int i = 0; i < rows; i++)
		{
			delete[] array[i];
		}
		delete[] array;
	}
}

void Matrix::print()
{
	for (int i = 0; i < rows; i++)
	{

		for (int j = 0; j < cols; j++)
		{	
			std::cout.width(3);
			std::cout << this->array[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Printed" << std::endl;
}
void Matrix::Fill(double element, double increment) 
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++) 
		{
			array[i][j] = element;
			element += increment;
		}
	}
}
bool Matrix::compare(const Matrix& ref)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
				if (array[i][j] != ref.array[i][j]) 
				{
					std::cout << "Compared Matrixes are not equal!" << std::endl;
					return false;
				}
		}
	}
	std::cout << "Compared Matrixes are equal!" << std::endl;
	return true;
}
const Matrix& Matrix::sum(const Matrix& matrix)
{
	if (rows != matrix.rows || cols != matrix.cols)
	{
		throw std::exception("invalid argument");
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{

			array[i][j] += matrix.array[i][j];
		}
	}

	return *this;
}
const Matrix& Matrix::sum(double val)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			array[i][j] += val;
		}
	}
	return *this;
}
const Matrix& Matrix::transpose()
{
	Matrix Temp (cols, rows);
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			Temp.array[i][j] = array[j][i];
		}
	}
	*this = std::move(Temp);
	return *this;
}
const Matrix& Matrix::multiply(const Matrix& matrix)
{
	if (cols != matrix.rows)
	{
		throw std::exception("Error! Multiplied matrix columns quality must match multiplier Matrix rows quality!");
	}
	Matrix Temp(rows,matrix.cols);
	for (int i = 0; i < Temp.rows; i++)
	{
		for (int j = 0; j < Temp.cols; j++)
		{
			Temp.array[i][j] = 0;
			for (int k = 0; k < cols; k++)
			{
				Temp.array[i][j] += (array[i][k]) * (matrix.array[k][j]);
			}
		}
	}
	*this = std::move(Temp);
	return *this;
}

const Matrix Matrix::getMinor(int row, int col) const
{
	if (row > rows || col > cols) //убрал >= потому что мы можем исключать крайние строки/столбцы
	{
		throw std::exception("Wrong imput: Matrix size is lesser!");
	}
	if (row < 0 || col < 0)
	{
		throw std::exception("Wrong imput: negative parametres!");
	}
	if (rows < 2 || cols < 2)
	{
		throw std::exception("Wrong matrix size!");
	}

	Matrix minor(rows - 1, cols - 1);
	for (int i = 0; i < minor.rows; i++)
	{
		int l = i >= row ? i + 1 : i;
		for (int j = 0; j < minor.cols; j++)
		{
			int k = j >= col ? j + 1 : j;
			minor.array[i][j] = array[l][k];
		}
	}
	return minor;
}
double Matrix::Determinant() const 
{
	if ( rows != cols) 
		throw std::exception("Matrix is not squared!");
	if ( rows == 1) 
		return array[0][0];
	double det = 0;
	for (int i = 0; i < cols; i++)
	{
		det += array[0][i] * getMinor(0, i).Determinant() * pow(-1,i);
	}
	return det;
}

bool Matrix::operator == (const Matrix& refC)
{
	return compare(refC);
}
const Matrix& Matrix::operator = (const Matrix& refC) //убрано дублирование кода, оставлен один if без else. Добавлен метод matrix_delete();
{
	if (rows != refC.rows || cols!=refC.cols) {
		this->matrix_delete();
		rows = refC.rows;
		cols = refC.cols;
		array = new double* [rows];
		for (int i = 0; i < rows; i++)
		{
			array[i] = new double[cols];
		}
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			array[i][j] = refC.array[i][j];
		}
	}
	std::cout << "Operator = used" << std::endl;
	return *this;
}
const Matrix& Matrix::operator = (Matrix&& ref) noexcept
{
	if (this != &ref) 
	{
		matrix_delete();
		array = ref.array;
		rows = ref.rows;
		cols = ref.cols;
		ref.array = nullptr;
		ref.rows = 0;
		ref.cols = 0;
	}
		
	return *this;
}
double& Matrix::operator () (int row_index, int col_index) 
{
	if (row_index < 0 || col_index < 0 || row_index > rows - 1 || col_index > cols - 1)
		throw std::exception("Wrong input");

	return array[row_index][col_index];
}