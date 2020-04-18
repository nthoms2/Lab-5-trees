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
	void DeleteItem(ItemType item);
	void ResetTree();
	ItemType GetNextItem(bool& finished);
	//void Print(ofstream& outfile);

	void BPutItem(ItemType item);

private:
	int length;
	TreeNode* root;

	void BInsert(TreeNode* node, ItemType item);
	void Delete(TreeNode* node, ItemType item);
	void DeleteNode(TreeNode* node);
};


#endif // !BiTree_H
