#include <iostream>

#include <iostream>

// задачка 1 на побитовые операции из домашней работы 21.09.19

// решение без побитовых операций
int solution1(int n)
{
	int ones = 0;
	while (n > 0)
	{
		ones += n % 2;
		n /= 2;
	}
	return ones;
}

// решение с применением побитовых операций
int solution2(int n)
{
	int ones = 0;
	for (; n > 0; ones += (n & 1), n >>= 1);
	return ones;
}

int main()
{
	int n; std::cin >> n;
	std::cout << solution1(n) << ' ' << solution2(n);
}