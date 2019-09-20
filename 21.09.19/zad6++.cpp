#include <iostream>
#include <iomanip>
#include <cmath>

// дополнение к задаче 6 из домашней работы на 21.09.19

int main()
{
	double x1; std::cout << "Please input X1: "; std::cin >> x1;
	double x2; std::cout << "Please input X2: "; std::cin >> x2;
	double d; std::cout << "Please input D: "; std::cin >> d;
	double e; std::cout << "Please input E: "; std::cin >> e;
	
	std::cout << "x\tTaylor\tsin(x)\n";

	for (double i = x1; i <= x2; i += d)
	{
		short mark = -1;
		double s = i;
		long long cur_fac = 3;

		double cur_add = i * i * i / 1 / 2 / 3;

		while (cur_add > e)
		{
			s += mark * (cur_add);

			mark = -mark;
			cur_add *= i * i;
			cur_add /= (cur_fac + 1) * (cur_fac + 2);
			cur_fac += 2;
		}
		std::cout << std::setprecision(4) << i << "\t" << s << "\t" << sin(i) << "\n";
	}
	return 0;
}