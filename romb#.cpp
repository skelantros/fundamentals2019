#include <iostream>

// клетчатый ромб (во всяком случае, как я его понял), домашка от 21.09.19

int main()
{
	int n;
	std::cin >> n;

	int m = n / 2;
	for (int i = 0, b = 0; i <= n / 2; i++, b++)
	{
		for (int k = 0; k < n; k++)
		{
			if (k >= m - b && k <= m + b && k % 2 != i % 2)
				std::cout << '*';
			else
				std::cout << ' ';
		}
		std::cout << "\n";
	}

	for (int i = 0, b = n / 2; i < n / 2; i++, b--)
	{
		for (int k = 0; k < n; k++)
		{
			if (k >= m - b && k <= m + b && k % 2 != i % 2)
				std::cout << '*';
			else
				std::cout << ' ';
		}
		std::cout << "\n";
	}
	return 0;
}