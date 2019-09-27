#include <iostream>

int main()
{
	const short ROWS = 7, COLUMNS = 4;
	const bool ver = 1;
	int arr[ROWS][COLUMNS];

	long n = 1;
	if (!ver)
	{
		for (int r = 0; r < ROWS; r++)
		{
			if (r % 2 == 0)
				for (int c = 0; c < COLUMNS; c++)
					arr[r][c] = n++;
			else
				for (int c = COLUMNS - 1; c >= 0; c--)
					arr[r][c] = n++;
		}
	}
	else
	{
		for (int c = 0; c < COLUMNS; c++)
		{
			if (c % 2 == 0)
				for (int r = 0; r < ROWS; r++)
					arr[r][c] = n++;
			else
				for (int r = ROWS - 1; r >= 0; r--)
					arr[r][c] = n++;
		}
	}

	for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COLUMNS; c++)
			std::cout << arr[r][c] << ' ';
		std::cout << "\n";
	}

	return 0;
}