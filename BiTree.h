#ifndef BiTree_H
#define BiTree_H

#include <iostream>
#include <string>
using namespace std;

typedef int ItemType;

struct TreeNode
{
	ItemType info;
	TreeNode* left;
	TreeNode* right;
};

class BiTree
{
public:
	BiTree();
	~BiTree();

	//BiTree(BiTree& oTree);
	//void operator=(BiTree& oTree);
	void MakeEmpty();
	bool IsEmpty();
	bool IsFull();
	int GetLength();
	ItemType GetItem(ItemType item, bool& found);

	//allows usage of the delete functions
	void DeleteItem(ItemType item);

	void ResetTree();
	ItemType GetNextItem(bool& finished);

	//allows usage of printingI
	void printI();
	//This function print the tree in increasing order.
	//precondition: It is called in PrintI and and the root is passed through.
	//postcondition: Every item in the tree is outputed to the screen in the correct order.
	void printingI(TreeNode*& node);

	//allows usage of printingD
	void printD();
	//This function print the tree in decreasing order.
	//precondition: It is called in PrintD and and the root is passed through.
	//postcondition: Every item in the tree is outputed to the screen in the correct order.
	void printingD(TreeNode*& node);

	//allows usage of PrintingT
	void printT();
	//This function prints the tree by items foun.d in each level of the tree
	//precondition: It is called in PrintT and and the root is passed through, along with i and level.
	//postcondition: Every item in the tree is outputed to the screen in the correct order.
	void printingT(TreeNode*& node, int& i, int& level);
	//void Print(ofstream& outfile);

	//allows usage of Binsert
	void BPutItem(ItemType item);

private:
	int length;
	TreeNode* root;

	void BInsert(TreeNode*& node, ItemType item, int& temp);
	void Delete(TreeNode*& node, ItemType item);
	void DeleteNode(TreeNode*& node);
};


#endif // !BiTree_H

