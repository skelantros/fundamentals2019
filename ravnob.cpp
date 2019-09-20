#include <iostream>

// задача 2 домашней работы к 21.09.19

// решение, вдохновленное словами о том, что в цикле можно инициализировать несколько переменных :)
void solution1(int h)
{
	int n = 2 * h - 1; // длина наибольшей (последней) стороны

	// bef - число пробелов перед звездочками
	// stars - число звездочек на текущей стркое
	// i - номер текущей строки
	for (int i = 0, bef = n / 2, stars = 1; i < n / 2 + 1; i++, bef--, stars += 2)
	{
		// вывод пробелов перед зведочками
		for (int k = 0; k < bef; k++)
			std::cout << ' ';
		// вывод звездочек
		for (int k = 0; k < stars; k++)
			std::cout << '*';
		std::cout << "\n";
	}
}

// более скучное решение, я полагаю
void solution2(int h)
{
	// l - длина строчки
	// cur_b - значение "границы" (число звездочек левее и правее центральной)
	// med - индекс средней звезды
	int l = 2 * h - 1, cur_b = 0, med = l / 2;

	for (int j = 0; j < h; j++)
	{
		for (int i = 0; i < l; i++)
		{
			if (med - cur_b <= i && i <= med + cur_b) { std::cout << '*'; }
			else { std::cout << ' '; }
		}
		std::cout << std::endl;
		cur_b += 1;
	}
}

int main()
{
	int h;
	std::cin >> h;
	solution1(h); std::cout << "\n"; solution2(h);
	return 0;
}