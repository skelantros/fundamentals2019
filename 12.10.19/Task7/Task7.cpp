#include <iostream>

int main()
{
	char str[1024];
	std::cin >> str;

	int max_len = 0, cur_len = 0,
		max_st = 0, cur_st = 0;

	for (int ch = 0; ch < strlen(str); ++ch)
	{
		if (str[ch] == '0')
			++cur_len;
		else
		{
			if (cur_len > max_len)
			{
				max_len = cur_len;
				max_st = cur_st;
			}
			cur_len = 0; cur_st = ch + 1;
		}
	}

	std::cout << "Length of longest zero-substring is " << max_len;
	std::cout << "\nIt starts from char numbered " << max_st + 1;
	system("pause");
}