#include <iostream>

void transposeMatrix(int** s_matrix, int** t_matrix, int s_rows, int s_columns)
{
	for (int t_r = 0; t_r < s_columns; ++t_r)
		for (int t_c = 0; t_c < s_rows; ++t_c)
			t_matrix[t_r][t_c] = s_matrix[t_c][t_r];
}

void printArray(int** arr, int rows, int columns)
{
	for (int r = 0; r < rows; ++r)
	{
		for (int c = 0; c < columns; std::cout << arr[r][c++] << ' ');
		std::cout << std::endl;
	}
}

int main()
{
	int rows, columns; // size of source matrix
	std::cout << "Please input number of matrix's rows: "; std::cin >> rows;
	std::cout << "Please input number of matrix's columns: "; std::cin >> columns;

	// source matrix
	int** s_matrix = new int* [rows];
	for (int r = 0; r < rows; ++r)
		s_matrix[r] = new int[columns];

	// transposed matrix
	int** t_matrix = new int* [columns];
	for (int c = 0; c < columns; ++c)
		t_matrix[c] = new int[rows];

	std::cout << "Now input elements of matrix:\n";
	for (int r = 0; r < rows; ++r)
	{
		for (int c = 0; c < columns; ++c)
			std::cin >> s_matrix[r][c];
	}

	transposeMatrix(s_matrix, t_matrix, rows, columns);
	std::cout << "Transposed matrix is:\n";
	printArray(t_matrix, columns, rows);
	delete[] s_matrix; delete[] t_matrix;
	system("pause");
}