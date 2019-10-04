#include <iostream>

const int ROWS = 7;
const int COLUMNS = 15;

void snail(int** arr, bool ver);
void printArray(int** arr);

int main()
{
	int** arr = new int* [ROWS];
	for (int r = 0; r < ROWS; arr[r++] = new int[COLUMNS]);

	snail(arr, true); printArray(arr);
	delete[] arr;
	system("pause");
	return 0;
}

void snail(int** arr, bool ver = false)
{
	const int DIRECTIONS[2][4] = { {0,1,2,3}, {1,0,3,2} };

	int l_b = 0, r_b = COLUMNS - 1,
		u_b = 0, d_b = ROWS - 1;
	int row = 0, column = 0, n = 1;
	for (int i = 0; (r_b >= l_b) && (d_b >= u_b); i++)
	{
		switch (DIRECTIONS[ver][i % 4])
		{
			case 0:
			{
				for (; column <= r_b; arr[row][column++] = n++);
				column--;
				d_b -= ver; u_b += !ver;
				row += ver ? -1 : 1;
				break;
			}
			case 1:
			{
				for (; row <= d_b; arr[row++][column] = n++);
				row--;
				l_b += ver; r_b -= !ver;
				column += ver ? 1 : -1;
				break;
			}
			case 2:
			{
				for (; column >= l_b; arr[row][column--] = n++);
				column++;
				d_b -= !ver; u_b += ver;
				row += ver ? 1 : -1;
				break;
			}
			case 3:
			{
				for (; row >= u_b; arr[row--][column] = n++);
				row++;
				l_b += !ver; r_b -= ver;
				column += ver ? -1 : 1;
				break;
			}
		}
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
