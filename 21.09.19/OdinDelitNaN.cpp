#include <iostream>

// задача 1 домашней работы на 21.09.19

int main()
{
	unsigned int n;
	double s = 0;
	std::cin >> n;
	for (int i = 0; i < n; s += 1.0 / (++i));
	std::cout << s;
	return 0;
}