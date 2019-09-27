#include <iostream>

int main()
{
	const short ROWS = 4, COLUMNS = 7;
	int arr[ROWS][COLUMNS];

	bool right_dir = 1; // 0 if starting direction is right-up, 1 if left-down

	long n = 1;
	for (int i = 0; i <= ROWS + COLUMNS - 2; i++) 
	{
		if (right_dir)
		{
			for (int row = i < ROWS ? i : ROWS - 1, column = i - row; row >= 0 && column < COLUMNS; row--, column++)
				arr[row][column] = n++;
		}
		else
			for (int column = i < COLUMNS ? i : COLUMNS - 1, row = i - column; column >= 0 && row < ROWS; column--, row++)
				arr[row][column] = n++;
		right_dir = !right_dir; // changing direction
	}

	for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COLUMNS; c++)
			std::cout << arr[r][c] << ' ';
		std::cout << "\n";
	}
}