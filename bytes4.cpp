#include <iostream>

// задача 4 побитовая из домашней работы на 21.09.19

// решение без приеменения побитовых операций
int solution1(int n, int n1, int n2)
{
	int cur_power = 1;

	int s = 0;

	for (int i = 0; i < n; i++)
	{
		s += cur_power * (n2 % 2 + (n1 % 2) * 2);
		n1 /= 2; n2 /= 2; cur_power *= 4;
	}
	return s;
}

// решение с применением побитовых операций
int solution2(int n, int n1, int n2)
{
	int s = 0;	
	for (int i = 1; i <= n; i++)
	{
		s += (n1 >> n - i) & 1;
		s <<= 1;
		s += (n2 >> n - i) & 1;
		s <<= 1;
	}
	s >>= 1; // после исполнения цикла у переменной s лишний нуль в конце
	return s;
}

int main()
{
	int n1, n2, n;
	std::cout << "Please input numbers: ";
	std::cin >> n1 >> n2;
	std::cout << "Please input n: ";
	std::cin >> n;

	std::cout << solution1(n, n1, n2) << ' ' << solution2(n, n1, n2);
	return 0;
}