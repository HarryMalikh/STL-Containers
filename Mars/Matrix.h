#pragma once


class Matrix 
{
public:
	Matrix ();
	Matrix (int r, int c);
	Matrix (const Matrix& ref);
	Matrix (Matrix&& doubleref) noexcept;

	~Matrix();
	class Unequal {};

	void print();
	void Fill(double element, double increment);
	const Matrix& At(int row_index, int col_index);
	bool compare(const Matrix& ref);
	const Matrix& sum(const Matrix& matrix);
	const Matrix& sum(double val);
	const Matrix& transpose();
	const Matrix& multiply(const Matrix& matrix);

	double Determinant() const;

	bool operator == (const Matrix& refC);
	const Matrix& operator = (const Matrix& refC);
	const Matrix& operator = (Matrix&& ref) noexcept;
	double& operator () (int row_index, int col_index); //A(2, 2) = 5


private:
	int rows = 3;
	int cols = 3;
	double** array = nullptr;

	const Matrix getMinor(int row, int col) const;
	void matrix_delete();


	
	// ������ ������ ������� � ������ - ����������� ����������� �� �������� ������. ����� ����������.



	// ���������: 1.�� habr� ��� ������, ��� rval lval, ��������� � ������� ������
	//            2."������ ���"  - ������ ������
	//			  3. ������������, ����������� ����������
	//			  4. ����������� ������
	//			  5. ����� ���� (���� ����, ���), �����������, ������ size � top
	//			  
	//			  6. ��������� ��� ����� ������� (queue). ����������� queue.
	//			  7. �������������� ���� , �������� ����.
	//			  8. �������� ��� queue � stack ������������� �� ������ ��������
			
}; 
