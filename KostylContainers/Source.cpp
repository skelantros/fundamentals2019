#include <iostream>
#include "Vector.h"
#include "DoubleList.h"
#include "List.h"
#include "BinTree.h"
#include <time.h>
#include "AvlTree.h"

typedef AvlTree<int> Container;

int main()
{

	/* //avl test
	int a;
	std::cin >> a;
	Container tree;
	while (a != 0)
	{
		tree.push_back(a);
		std::cout << "Current height (size =  " << tree.size() << "): " << tree.height() << std::endl;
		std::cout << *tree.find(a) << std::endl;
		std::cin >> a;
	}*/

	Container tree;
	/*tree.push_back(7);
	tree.push_back(3);
	tree.push_back(13);
	tree.push_back(4);
	tree.push_back(5);
	tree.push_back(1);
	tree.push_back(6);
	tree.push_back(9);
	tree.push_back(17);
	tree.push_back(8);*/


	while (true)
	{
		int a;
		std::cin >> a;
		tree.push_back(a);
		for (auto i = tree.begin(); i != tree.end(); ++i)
		{
			std::cout << *i << ' ';
		}
		std::cout << "(height of tree: " << tree.height() << ")." << std::endl;
	}

}