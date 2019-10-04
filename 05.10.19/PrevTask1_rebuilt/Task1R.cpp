#include <iostream>

const int R = 7;
const int C = 10;

void snake(int** arr, bool first_down = false)
{
	int n = 1;
	if (!first_down)
	{
		for (int r = 0; r < R; ++r)
		{
			if (r % 2 == 0)
				for (int c = 0; c < C; ++c)
					arr[r][c] = n++;
			else
				for (int c = C - 1; c >= 0; --c)
					arr[r][c] = n++;
		}
	}
	else
	{
		for (int c = 0; c < C; ++c)
		{
			if (c % 2 == 0)
				for (int r = 0; r < R; ++r)
					arr[r][c] = n++;
			else
				for (int r = R - 1; r >= 0; --r)
					arr[r][c] = n++;
		}
	}
}

void printArray(int** arr)
{
	for (int r = 0; r < R; ++r)
	{
		for (int c = 0; c < C; std::cout << arr[r][c++] << ' ');
		std::cout << std::endl;
	}
}

int main()
{
	int** arr = new int* [R];
	for (int r = 0; r < R; arr[r++] = new int[C]);
	snake(arr, true); printArray(arr);
	
	delete[] arr;
	return 0;

	system("pause");
}