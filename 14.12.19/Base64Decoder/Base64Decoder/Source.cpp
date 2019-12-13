#include "Base64Decoder.h"
#include <iostream>

int main()
{
	/*char quartet[] = { 'a', 'A', '=', '=' };
	char triplet[] = { 1,1,1 };
	decodeQuartet(quartet, triplet);
	std::cout << triplet[0] << triplet[1] << triplet[2];*/

	char encoded[] = "aA==";
	std::cout << base64Decoder(encoded);
}