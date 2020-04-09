#pragma once

template <typename Type>
void Swap(Type& el1, Type& el2)
{
	Type tmp = el1;
	el1 = el2;
	el2 = tmp;
}

template <typename Type>
int qsort_part(Type* arr, int l_pos, int r_pos)
{
	int pivot_idx = (l_pos + r_pos) / 2;
	Type pivot = arr[pivot_idx];
	while (l_pos < r_pos)
	{
		while (pivot >= arr[l_pos] && l_pos < pivot_idx)
			++l_pos;
		while (pivot <= arr[r_pos] && r_pos > pivot_idx)
			--r_pos;
		if (l_pos == r_pos)
			break;
		Swap(arr[l_pos], arr[r_pos]);
		if (l_pos == pivot_idx)
			pivot_idx = r_pos;
		else if (r_pos == pivot_idx)
			pivot_idx = l_pos;
	}
	return l_pos;
}

template <typename Type>
void QSort(Type* arr, size_t size)
{
	if (size <= 1) return;

	int pivot = qsort_part(arr, 0, size - 1);
	QSort(arr, pivot);
	QSort(arr + pivot + 1, size - pivot - 1);
}