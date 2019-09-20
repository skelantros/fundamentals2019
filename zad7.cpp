#include <iostream>
#include <cmath>

// задача 7 домашней работы на 21.09.19

int main()
{
	int x, n;
	std::cout << "Please input X: "; std::cin >> x;
	std::cout << "Please input N: "; std::cin >> n;

	double s = sin(x);
	for (int i = 0; i < n - 1; i++) { s = sin(s); }
	std::cout << s;

	return 0;
}