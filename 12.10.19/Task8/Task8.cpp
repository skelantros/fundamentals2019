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

int indexOfMaxInRow(int** arr, int columns, int row)
{
	int ind_max = 0;
	int cur_max = arr[row][0];
	for (int c = 1; c < columns; ++c)
	{
		if (arr[row][c] > cur_max)
		{
			ind_max = c;
			cur_max = arr[row][c];
		}
	}
	return ind_max;
}

int indexOfMinInColumn(int** arr, int rows, int column)
{
	int ind_min = 0;
	int cur_min = arr[0][column];
	for (int r = 1; r < rows; ++r)
	{
		if (arr[r][column] < cur_min)
		{
			ind_min = r;
			cur_min = arr[r][column];
		}
	}
	return ind_min;
}

int main()
{
	int rows, columns;

	std::cout << "Please input number of matrix's rows: "; std::cin >> rows;
	std::cout << "Please input number of matrix's columns: "; std::cin >> columns;

	int** matrix = new int* [rows];
	for (int r = 0; r < rows; ++r)
		matrix[r] = new int[columns];
	inputArray(matrix, rows, columns);

	int req_r = -1, req_c = -1;
	for (int r = 0; r < rows; ++r)
	{
		int col_index = indexOfMaxInRow(matrix, columns, r);
		if (indexOfMinInColumn(matrix, rows, col_index) == r)
		{
			req_r = r; req_c = col_index;
			break;
		}
	}

	if (req_r == -1)
		std::cout << "Required element sadly is not found ):";
	else
		std::cout << "Required element is found! It is located in row " << req_r << ", column " << req_c;

	delete[] matrix;
	system("pause");
}