#include <iostream>

// задачка 2 побитовая домашней работы от 21.09.19
int main()
{
	int n, s; std::cin >> n >> s;
	for (int i = 0; i * i < s * s; i++)
	{
		if (s < 0)
			n >>= 1;
		else
			n <<= 1;
	}
	std::cout << n;
}