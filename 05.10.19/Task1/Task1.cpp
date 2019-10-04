#include <iostream>

int main()
{
	const int N = 13; // высота ромба (задается пользователем)

	const int MED = N / 2; // середина диагонали ромба (учитывая, что точки ромба нумеруются с нуля)

	/* строка, соответствующая отображеию ромба на текущей строке
	по ходу программы она будет изменяться */
	char* str = new char[N + 1];
	str[N] = '\0';
	
	for (int i = 0; i < N; i++)
		str[i] = i == N / 2 ? '*' : ' ';

	bool reverse = false; // если reverse = false, число точек ромба с проходм цикла увеличивается, иначе - уменьшается
	int cur_b = 0; // служебная переменная такая, что все точки ромба на данном проходе цикла находятся в промежутке [MED - cur_b; MED + cur_b]

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