#include "BiTree.h"
#include <iostream>

using namespace std;

BiTree::BiTree()
{
	root = nullptr;
	length = 0;
}

BiTree::~BiTree()
{
	MakeEmpty();
}

void BiTree::MakeEmpty()
{

}

bool BiTree::IsEmpty()
{
	if (root == nullptr)
		return true;

	return false;
}

bool BiTree::IsFull()
{
	try
	{
		TreeNode* temp = new TreeNode;

		delete temp;
		return false;
	}
	catch (bad_alloc e)
	{
		return true;
	}
}

int BiTree::GetLength()
{
	return length;
}

ItemType BiTree::GetItem(ItemType item, bool& found)
{
	return ItemType();
}

void BiTree::DeleteItem(ItemType item)
{
	Delete(root, item);
}

void BiTree::ResetTree()
{
}

ItemType BiTree::GetNextItem(bool& finished)
{
	return ItemType();
}

void BiTree::printI()
{
	printingI(root);
}
//Outputs in decreasing order.
void BiTree::printingI(TreeNode*& node)
{
	if (node != nullptr)
	{
		if (node->left != nullptr)
		{
			printingI(node->left);
		}
		cout << node->info << ", ";
		if (node->right != nullptr)
		{
			printingI(node->right);
		}
	}
	else
		cout << "tree is empty" << endl;
}

void BiTree::printD()
{
	printingD(root);
}
//Outputs in decreasing order.
void BiTree::printingD(TreeNode*& node)
{
	if (node != nullptr)
	{
		if (node->right != nullptr)
		{
			printingD(node->right);
		}
		cout << node->info << ", ";
		if (node->left != nullptr)
		{
			printingD(node->left);
		}
		
	}
	else
		cout << "tree is empty" << endl;
}

//goes through the length of the tree and prints each level accordingly.
void BiTree::printT()
{ 
	
	for (int i = 1; i <= length; i++)
	{
		int level = 1;
		printingT(root, i, level);
		cout << endl;
	}
}

//This function keeps track of the different levels of the tree and outputs infortation for a given level.
void BiTree::printingT(TreeNode*& node, int& i, int& level)
{
	if (node != nullptr)
	{
		if (node->left != nullptr)
		{
			level++;
			printingT(node->left, i, level);
		}

		if (level == i)
			cout << node->info << " ";
		
		if (node->right != nullptr)
		{
			level++;
			printingT(node->right, i, level);
		}
		level--;
	}
	else
		cout << "tree is empty" << endl;
}

void BiTree::BPutItem(ItemType item)
{
	int temp = 1;
	BInsert(root, item, temp);
}
 
//I modified this function so it would keep track of the length of the tree.
void BiTree::BInsert(TreeNode*& node, ItemType item, int& temp)
{

	if (node == nullptr)
	{
		node = new TreeNode;
		node->left = nullptr;
		node->right = nullptr;
		node->info = item;
	}

	else if (item < node->info)
	{
		BInsert(node->left, item, temp);
		temp++;
	}
	else
	{
		BInsert(node->right, item, temp);
		temp++;
	}
	if (temp > length)
		length = temp;
}

void BiTree::Delete(TreeNode*& node, ItemType item)
{
	if (item < node->info)
		Delete(node->left, item);
	else if (item > node->info)
		Delete(node->right, item);
	else
	{
		DeleteNode(node);
	}
}

void BiTree::DeleteNode(TreeNode*& node)
{
	TreeNode* temp = node;
	TreeNode* parent;
	if (node->left == nullptr && node->right == nullptr)
	{
		delete node;
	}
	else if (node->left != nullptr && node->right == nullptr)
	{
		node->info = node->left->info;
		temp = node->left;
		node->right = node->left->right;
		node->left = node->left->left;
		delete temp;
	}
	else if (node->left == nullptr && node->right != nullptr)
	{
		node->info = node->right->info;
		temp = node->right;
		node->left = node->right->left;
		node->right = node->right->right;
		delete temp;
	}
	else
	{
		temp = node->right;
		parent = temp;
		while (temp->left != nullptr)
		{
			parent = temp;
			temp = temp->left;
		}
		parent->left = temp->right;
		node->info = temp->info;
		delete temp;
	}
}