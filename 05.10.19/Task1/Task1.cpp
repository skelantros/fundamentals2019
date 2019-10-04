#include <iostream>

int main()
{
	const int N = 13; // ������ ����� (�������� �������������)

	const int MED = N / 2; // �������� ��������� ����� (��������, ��� ����� ����� ���������� � ����)

	/* ������, ��������������� ���������� ����� �� ������� ������
	�� ���� ��������� ��� ����� ���������� */
	char* str = new char[N + 1];
	str[N] = '\0';
	
	for (int i = 0; i < N; i++)
		str[i] = i == N / 2 ? '*' : ' ';

	bool reverse = false; // ���� reverse = false, ����� ����� ����� � ������� ����� �������������, ����� - �����������
	int cur_b = 0; // ��������� ���������� �����, ��� ��� ����� ����� �� ������ ������� ����� ��������� � ���������� [MED - cur_b; MED + cur_b]

	while (str[MED] != ' ') {
		if (str[0] == '*')
			reverse = true;

		std::cout << str << std::endl;

		if (!reverse)
		{
			str[MED + ++cur_b] = '*';
			str[MED - cur_b] = '*';
		}
		else
		{
			str[MED + cur_b] = ' ';
			str[MED - cur_b--] = ' ';
		}
	}
	delete[] str;

	return 0;
	system("pause");
}