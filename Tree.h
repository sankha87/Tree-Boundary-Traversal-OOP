#pragma once
#include "TreeNode.h"

class Tree
{
	TreeNode* root;
	int nodecount;
	void inordertraversal(TreeNode* root);

public:
	Tree();
	~Tree();
	Tree(int num);

	void inorder();
	TreeNode* insertLevelOrder(int arr[], TreeNode *root, int i, int n);
};

