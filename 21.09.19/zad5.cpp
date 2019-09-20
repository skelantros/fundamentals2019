#include <iostream>

// задача 5 домашней работы от 21.09.19
// сумма 1 + x + x^2 + ... + x^n while abs(x^n) > e

int main()
{
	double x, sl, s, e;
	std::cin >> x >> e;
	s = 1;
	sl = x;
	while (sl * sl > e * e)
	{
		s += sl;
		sl *= x;
	}
	std::cout << s << "\t" << 1.0 / (1 - x);
	return 0;
}