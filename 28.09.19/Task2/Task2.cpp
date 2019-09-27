#include <iostream>

int main()
{
	const short ROWS = 10, COLUMNS = 15;
	const bool VER = 1; // истина, если первый ход улитки - вниз; ложь, если вправо

	int arr[ROWS][COLUMNS];
	// определение границ, в рамках которых двигается улитка. в ходе исполнения программы они изменяются
	int l_b = 0, r_b = COLUMNS - 1,
		u_b = 0, d_b = ROWS - 1;

	/* массив массивов упорядоченных ходов улитки.
	в первом массиве ходы упорядочены на случай, если улитка сделает первый ход вправо,
	во втором - вниз.
	0 соответствует шагу вправо, 1 - вниз, 2 - влево, 3 - вверх
	*/
	const int DIRECTIONS[2][4] = { {0,1,2,3}, {1,0,3,2} };

	// переменные для хранения номеров текущих строки и столбца и номера ячейки
	int row = 0, column = 0, n = 1;
	for (int i = 0; (r_b >= l_b) && (d_b >= u_b); i++)
	{
		// здесь и кое-где далее я использовал маааленький абуз компилятора, заключающийся в том, что
		// при использовании булево-переменной в качестве целочисленной она оказывается равной 1, если она истинна
		// и 0, если ложна
		switch (DIRECTIONS[VER][i % 4])
		{
			case 0: // шаг вправо
			{
				for (; column <= r_b; arr[row][column++] = n++);
				column--;
				d_b -= VER; u_b += !VER;
				row += VER ? -1 : 1;
				break;
			}
			case 1: // вниз
			{
				for (; row <= d_b; arr[row++][column] = n++);
				row--;
				l_b += VER; r_b -= !VER;
				column += VER ? 1 : -1;
				break;
			}
			case 2: // влево
			{
				for (; column >= l_b; arr[row][column--] = n++);
				column++;
				d_b -= !VER; u_b += VER;
				row += VER ? 1 : -1;
				break;
			}
			case 3: // вверх
			{
				for (; row >= u_b; arr[row--][column] = n++);
				row++;
				l_b += !VER; r_b -= VER;
				column += VER ? -1 : 1;
				break;
			}
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