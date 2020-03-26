#include "KostylVector.h"

int main()
{
	KostylVector<int> kv(1, 1);
	kv.print();
	std::cout << kv[0] << std::endl;
	std::cout << (kv[0] = 50) << std::endl;
	try {
		std::cout << kv[1];
	}
	catch (const char* str)
	{
		std::cout << str << std::endl;
	}
	for (int i = 100; i < 1000; i += 100)
	{
		kv.pushBack(i)->pushBack(i + 50);
		kv.print();
	}
}