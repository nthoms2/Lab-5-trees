#include <iostream>
#include "BiTree.h"
using namespace std;

int main()
{
	BiTree tree;

	tree.BPutItem(10);
	tree.BPutItem(5);
	tree.BPutItem(7);
	tree.BPutItem(6);
	tree.BPutItem(4);
	tree.BPutItem(11);

	tree.printI();
	cout << "\n";
	tree.printD();
	cout << "\n";
	tree.printT();
}