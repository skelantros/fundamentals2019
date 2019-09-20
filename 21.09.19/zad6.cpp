#include <iostream>
#include <cmath>

// задача 6 из домашней работы на 21.09.19

int main()
{
	double x; std::cout << "Please input X: "; std::cin >> x;
	double e; std::cout << "Please input E: "; std::cin >> e;
	
	short mark = -1;
	double s = x;
	long long cur_fac = 3;

	double cur_add = x * x * x / 1 / 2 / 3;

	while (cur_add > e)
	{
		s += mark * (cur_add);

		mark = -mark;
		cur_add *= x * x;
		cur_add /= (cur_fac + 1) * (cur_fac + 2);
		cur_fac += 2;
	}

	std::cout << sin(x) << " " << s;
	return 0;
}