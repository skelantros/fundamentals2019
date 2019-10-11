#include <iostream>

int translator(char* r_num)
{
	int num = 0;
	int num_len = strlen(r_num);
	bool is_first = true;
	for (int m = num_len - 1; m >= 0; --m)
	{
		char cur_m = r_num[m];
		char prev_m = m == num_len - 1 ? r_num[m] : r_num[m+1];
		if (cur_m == 'M')
			num += 1000;
		else if (cur_m == 'D')
			num += 500;
		else if (cur_m == 'C')
		{
			if (is_first)
				num += 100;
			else if (prev_m == 'D' || prev_m == 'M')
				num -= 100;
			else
				num += 100;
		}
		else if (cur_m == 'L')
			num += 50;
		else if (cur_m == 'X')
		{
			if (is_first)
				num += 10;
			else if (prev_m == 'C' || prev_m == 'L')
				num -= 10;
			else
				num += 10;
		}
		else if (cur_m == 'V')
			num += 5;
		else if (cur_m == 'I')
		{
			if (is_first)
				++num;
			else if (prev_m == 'X' || prev_m == 'V')
				--num;
			else
				++num;
		}
		else
			return -1;
		is_first = false;
	}

	return num;
}

int main()
{
	char num[256];
	std::cin >> num;
	std::cout << translator(num);
}