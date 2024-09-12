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


	
	// почему ошибка доступа к памяти - конструктор копирования не выделяет память. нужно переделать.



	// Прочитать: 1.на habrе про ссылки, про rval lval, одинарная и двойная ссылка
	//            2."Чистый Код"  - Роберт Мартин
	//			  3. наследование, виртуальный деструктор
	//			  4. односвязный список
	//			  5. класс стек (поля сайз, птр), конструктор, методы size и top
	//			  
	//			  6. Прочитать что такое очередь (queue). Реализовать queue.
	//			  7. Протестировать стек , Сравнить стек.
	//			  8. подумать как queue и stack отнаследовать от одного родителя
			
}; 
