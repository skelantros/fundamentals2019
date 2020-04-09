#pragma once

template <typename Type>
int binary_search(Type* arr, Type elem, int size)
{
	int left = 0;
	int right = size - 1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (arr[middle] == elem)
			return middle;
		else if (arr[middle] > elem)
			right = middle - 1;
		else
			left = middle + 1;
	}
	return -1;
}