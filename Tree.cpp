#include "Tree.h"

void Tree::inordertraversal(TreeNode * root)
{
	if (root == NULL)
		return;
	else
	{
		inordertraversal(root->getLeft());
		std::cout << root->getData() << " ";
		inordertraversal(root->getRight());
	}
}

Tree::Tree()
{
}

Tree::~Tree()
{
	delete this->root;
}

Tree::Tree(int num)
{
	if (num == 0)
		return;

	int *arr = new int[num];

	for (int i = 1; i <= num; i++)
		arr[i - 1] = i;
	// arr = 1,2,3,4...10

	this->root = insertLevelOrder(arr, this->root, 0, num);
}

void Tree::inorder()
{
	inordertraversal(this->root);
}

TreeNode* Tree::insertLevelOrder(int arr[], TreeNode *root, int i, int n)
{
	// Base case for recursion
	if (i < n)
	{
		TreeNode *temp = new TreeNode();
		temp->setData(arr[i]);
		temp->setLeft(NULL);
		temp->setRight(NULL);
		this->root = temp;

		
		this->root->setLeft(insertLevelOrder(arr, root->getLeft(), 2 * i + 1, n));		// insert left child
																	//arr   = 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
																	//index = 0, 1, 2, 3, 4, 5, 6, 7, 8, 9

		
		this->root->setRight(insertLevelOrder(arr, root->getRight(), 2 * i + 2, n));		// insert right child
	}
	return this->root;
}