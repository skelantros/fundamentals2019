#include <iostream>

int translator(char* num, int base)
{
	int res = 0;
	for (int i = 0; i < strlen(num); ++i)
		res = res * base + (num[i] - '0');
	return res;
}

int main()
{
	char num[256];
	int base;
	std::cout << "Please input number: "; std::cin >> num;
	std::cout << "Now input base of number system: "; std::cin >> base;
	std::cout << translator(num, base);
	system("pause");
	return 0;
}