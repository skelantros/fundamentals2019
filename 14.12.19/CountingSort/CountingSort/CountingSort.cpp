#include <iostream>

void countingSort(char* arr, int size)
{
	int* count = new int[256];
	for (int i = 0; i < 256; ++i)
		count[i] = 0;

	for (int i = 0; i < size; ++i)
		++count[128 + arr[i]];

	int arr_idx = 0;
	int count_idx = 0;
	while (count_idx < 256 && arr_idx < size)
	{
		if (count[count_idx] == 0)
		{
			++count_idx;
			continue;
		}
		arr[arr_idx++] = count_idx - 128;
		--count[count_idx];
	}
	delete[] count;
}

int main()
{
	int size;
	std::cout << "SIZE: ";
	std::cin >> size;
	char* arr = new char[size];
	std::cout << "INTEGER CODES OF ELEMENTS: ";
	for (int i = 0; i < size; ++i)
	{
		int loc;
		std::cin >> loc;
		arr[i] = loc;
	}

	countingSort(arr, size);
	for (int i = 0; i < size; ++i)
		std::cout << (int) arr[i] << ' ';
}