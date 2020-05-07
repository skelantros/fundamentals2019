#include <iostream>
#include <fstream>
#include "String.h"
#include "DictPair.h"
#include "Vector.h"
#include "Dictionary.h"

typedef Vector<DictPair> Container;


/*int main()
{
	setlocale(LC_ALL, "Rus");
	char fname[] = "dictionary-ru.txt";

	std::ifstream fin(fname);
	if (!fin) throw "Cannot open dictionary";

	DictPair dp;
	Container dictionary;

	int i = 0;
	while (fin.peek() != EOF)
	{
		fin >> dp;
		//std::cout << dp << std::endl;
		dictionary.push_back(dp);
	}
	fin.close();

	std::cout << "Size of dictionary: " << dictionary.size() << std::endl;
	String word;
	while (true)
	{
		std::cout << "> ";
		std::cin >> word;
		if (word.length() < 1) break;
		int idx = dictionary.find(word);
		if (idx == -1)
			std::cout << "There is no word '" << word << "' in dictionary.\n";
		else
			std::cout << "Translation: " << dictionary[idx].translate() << std::endl;
	}
	return 0;
}*/

int main()
{
	Dictionary<String, String> dict;
	dict["a"] = "super";
	String b;
	std::cin >> b;
	dict[b] = "amazing";
	std::cout << dict[b];
}