#include <iostream>

// задача 1 домашней работы на 21.09.19

int main()
{
	int n;
	std::cin >> n;
	// i - номер строки; k - число звездочек в строке
	for (int i = 0, k = 1; i < n; i++, k++)
	{
		for (int j = 0; j < k; j++)
			std::cout << '*';
		std::cout << "\n";
	}
}