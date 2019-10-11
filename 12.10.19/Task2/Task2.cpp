#include <iostream>

void printArray(int** arr, int rows, int columns)
{
	for (int r = 0; r < rows; ++r)
	{
		for (int c = 0; c < columns; std::cout << arr[r][c++] << ' ');
		std::cout << std::endl;
	}
}

void inputArray(int** arr, int rows, int columns)
{
	for (int r = 0; r < rows; ++r)
		for (int c = 0; c < columns; ++c)
			std::cin >> arr[r][c];
}

int multiplyRowByColumn(int** r_matrix, int row, int** c_matrix, int column, int common)
{
	int s = 0;
	for (int el = 0; el < common; ++el)
		s += r_matrix[row][el] * c_matrix[el][column];
	return s;
}

void multiplyMatrixes(int** matrix1, int** matrix2, int** mul_matrix, int m1_rows, int common, int m2_columns)
{
	for (int r = 0; r < m1_rows; ++r)
		for (int c = 0; c < m2_columns; ++c)
			mul_matrix[r][c] = multiplyRowByColumn(matrix1, r, matrix2, c, common);
}

int main()
{
	int rows1, columns1;
	
	std::cout << "Please input number of 1st matrix's rows: "; std::cin >> rows1;
	std::cout << "Please input number of 1st matrix's columns: "; std::cin >> columns1;

	int** matrix1 = new int* [rows1];
	for (int r = 0; r < rows1; ++r)
		matrix1[r] = new int[columns1];
	inputArray(matrix1, rows1, columns1);

	int columns2, rows2 = columns1;
	std::cout << "Please input number of 2nd matrix's columns (number of rows is equal to number of 1st matrix's columns): "; std::cin >> columns2;

	int** matrix2 = new int* [rows2];
	for (int r = 0; r < rows2; ++r)
		matrix2[r] = new int[columns2];
	inputArray(matrix2, rows2, columns2);

	int** mul_matrix = new int* [rows1];
	for (int r = 0; r < rows1; ++r)
		mul_matrix[r] = new int[columns2];
	multiplyMatrixes(matrix1, matrix2, mul_matrix, rows1, columns1, columns2);
	std::cout << "Result of multiplication is:\n";
	printArray(mul_matrix, rows1, columns2);
	system("pause");
}