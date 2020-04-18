#include "BiTree.h"
#include <iostream>

using namespace std;

BiTree::BiTree()
{
	root = nullptr;
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

void BiTree::BPutItem(ItemType item)
{
	BInsert(root, item);
}

void BiTree::BInsert(TreeNode* node, ItemType item)
{
	if (node == nullptr)
	{
		node = new TreeNode;
		node->left = nullptr;
		node->right = nullptr;
		node->info = item;
	}
	else if (item < node->info)
		BInsert(node->left, item);
	else
		BInsert(node->right, item);
}

void BiTree::Delete(TreeNode* node, ItemType item)
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

void BiTree::DeleteNode(TreeNode* node)
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