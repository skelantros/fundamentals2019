#include <iostream>

// 3 задача на побитовые операции из домашней работы на 21.09.19
// примечание: сий зверь инженерной мысли работает только с числами с четным числом двоичных разрядов

int main()
{
	int num, digits = 0;
	std::cin >> num;

	int n1 = num;
	while (n1 > 0) { digits++; n1 /= 2; }

	int a = 0;
	for (int i = 1; i <= digits; i += 2)
	{
		a += (num >> (digits - i - 1)) & 1; a <<= 1;
		a += (num >> (digits - i)) & 1; a <<= 1;	
	}
	a >>= 1;
	std::cout << a;

	return 0;
}
