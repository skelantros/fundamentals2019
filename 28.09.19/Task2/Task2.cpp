#include <iostream>

int main()
{
	const short ROWS = 10, COLUMNS = 15;
	const bool VER = 1; // ������, ���� ������ ��� ������ - ����; ����, ���� ������

	int arr[ROWS][COLUMNS];
	// ����������� ������, � ������ ������� ��������� ������. � ���� ���������� ��������� ��� ����������
	int l_b = 0, r_b = COLUMNS - 1,
		u_b = 0, d_b = ROWS - 1;

	/* ������ �������� ������������� ����� ������.
	� ������ ������� ���� ����������� �� ������, ���� ������ ������� ������ ��� ������,
	�� ������ - ����.
	0 ������������� ���� ������, 1 - ����, 2 - �����, 3 - �����
	*/
	const int DIRECTIONS[2][4] = { {0,1,2,3}, {1,0,3,2} };

	// ���������� ��� �������� ������� ������� ������ � ������� � ������ ������
	int row = 0, column = 0, n = 1;
	for (int i = 0; (r_b >= l_b) && (d_b >= u_b); i++)
	{
		// ����� � ���-��� ����� � ����������� ����������� ���� �����������, ������������� � ���, ���
		// ��� ������������� ������-���������� � �������� ������������� ��� ����������� ������ 1, ���� ��� �������
		// � 0, ���� �����
		switch (DIRECTIONS[VER][i % 4])
		{
			case 0: // ��� ������
			{
				for (; column <= r_b; arr[row][column++] = n++);
				column--;
				d_b -= VER; u_b += !VER;
				row += VER ? -1 : 1;
				break;
			}
			case 1: // ����
			{
				for (; row <= d_b; arr[row++][column] = n++);
				row--;
				l_b += VER; r_b -= !VER;
				column += VER ? 1 : -1;
				break;
			}
			case 2: // �����
			{
				for (; column >= l_b; arr[row][column--] = n++);
				column++;
				d_b -= !VER; u_b += VER;
				row += VER ? 1 : -1;
				break;
			}
			case 3: // �����
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