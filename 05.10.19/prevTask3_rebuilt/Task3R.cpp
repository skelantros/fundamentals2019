#include <iostream>

const int ROWS = 7;
const int COLUMNS = 15;

void zigzag(int** arr, bool right_dir = false)
{
	long n = 1;
	for (int i = 0; i <= ROWS + COLUMNS - 2; ++i)
	{
		if (right_dir)
		{
			for (int row = i < ROWS ? i : ROWS - 1, column = i - row; row >= 0 && column < COLUMNS; --row, ++column)
				arr[row][column] = n++;
		}
		else
			for (int column = i < COLUMNS ? i : COLUMNS - 1, row = i - column; column >= 0 && row < ROWS; --column, ++row)
				arr[row][column] = n++;
		right_dir = !right_dir; // changing direction
	}
}

void printArray(int** arr)
{
	for (int r = 0; r < ROWS; ++r)
	{
		for (int c = 0; c < COLUMNS; std::cout << arr[r][c++] << ' ');
		std::cout << std::endl;
	}
}

int main()
{
	int** arr = new int* [ROWS];
	for (int r = 0; r < ROWS; arr[r++] = new int[COLUMNS]);
	zigzag(arr, true); printArray(arr);
	return 0;

	system("pause");
}