#include <iostream>

// задача 4 домашней работы к 21.09.19

int main()
{
	int n;
	std::cin >> n;

	for (int i = 0, bef = n / 2, stars = 1; i < n / 2 + 1; i++, bef--, stars += 2)
	{
		for (int k = 0; k < bef; k++)
			std::cout << ' ';
		for (int k = 0; k < stars; k++)
			std::cout << '*';
		std::cout << "\n";
	}

	for (int i = 0, bef = 1, stars = n - 2; i < n / 2; i++, bef++, stars -= 2)
	{
		for (int k = 0; k < bef; k++)
			std::cout << ' ';
		for (int k = 0; k < stars; k++)
			std::cout << '*';
		std::cout << "\n";
	}
	return 0;
}