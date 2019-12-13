#pragma once
#include <iostream>
char base64Chars[] =
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz"
"0123456789+/";

template <typename T>
int indexOfElement(T* arr, int size, T el)
{
	for (int i = 0; i < size; ++i)
		if (arr[i] == el)
			return i;
	return -1;
}

void decodeQuartet(char* encoded_quartet, char* decoded_triplet)
{
	char temp[4];
	for (int i = 0; i < 4; ++i)
	{
		if (encoded_quartet[i] == '=')
			temp[i] = 0;
		else
			temp[i] = indexOfElement(base64Chars, 64, encoded_quartet[i]);
	}
	decoded_triplet[0] = (temp[0] << 2) + (temp[1] >> 4);
	decoded_triplet[1] = ((temp[1] & 0b1111) << 4) + (temp[2] >> 2);
	decoded_triplet[2] = ((temp[2] & 0b11) << 6) + temp[3];
}

char* base64Decoder(char* encoded)
{
	int decoded_size = 3 * strlen(encoded) / 4;
	if (encoded[strlen(encoded) - 1] == '=')
		--decoded_size;
	if (encoded[strlen(encoded) - 2] == '=')
		--decoded_size;
	char* decoded = new char[decoded_size + 1];
	decoded[decoded_size] = '\0';

	int decoded_idx = 0;
	int encoded_idx = 0;
	char d_triplet[3];
	while (decoded_size - decoded_idx > 2)
	{
		decodeQuartet(encoded + encoded_idx, d_triplet);
		for (int i = 0; i < 3; ++i)
			decoded[decoded_idx++] = d_triplet[i];
		encoded_idx += 4;
	}
	if (decoded_size != decoded_idx)
	{
		decodeQuartet(encoded + encoded_idx, d_triplet);
		for (int i = 0; i < 3; ++i)
		{
			if (d_triplet[i] == 0)
				break;
			decoded[decoded_idx++] = d_triplet[i];
		}
	}
	return decoded;
}