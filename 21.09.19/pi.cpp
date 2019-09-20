#include <iostream>

// задача про разложение числа пи из домашней работы 21.09.19

int main()
{
	double e;
	std::cin >> e;

	int div = 3;
	double mn = -1.0;
	double s = 1;

	while (1.0 / div > e)
	{
		s += mn / div;
		div += 2;
		mn = -mn;
	}

	std::cout << s * 4;

	return 0;
}