#include <iostream>

// пустой ромб, задача из домашки на 21.09.19

int main()
{
	int h; std::cin >> h;
	int m = h / 2, b = 0;
	while (m + b < h - 1)
	{
		for (int i = 0; i < h; i++)
		{
			if (i == m + b || i == m - b)
				std::cout << '*';
			else
				std::cout << ' ';
		}
		b++; std::cout << "\n";
	}

	while (b >= 0)
	{
		for (int i = 0; i < h; i++)
		{
			if (i == m + b || i == m - b)
				std::cout << '*';
			else
				std::cout << ' ';
		}
		b--; std::cout << "\n";
	}
}