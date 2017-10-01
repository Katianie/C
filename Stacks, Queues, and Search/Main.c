/** Breadth First and Depth First Search: Main.c
* This program shows how to traverse a Tree in various ways.
*
* Eddie O'Hagan
* Copyright © 2013 Katianie.com
*/
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"

void addTreeNode(TreeNode* root, int num)
{
	TreeNode* numNode;

	if (num < root->data)
	{
		if (root->left == NULL)
		{
			numNode = malloc(sizeof(TreeNode));
			numNode->data = num;
			numNode->left = NULL;
			numNode->right = NULL;

			root->left = numNode;
		}
		else
		{
			addTreeNode(root->left, num);
		}
	}
	else
	{
		if (root->right == NULL)
		{
			numNode = malloc(sizeof(TreeNode));
			numNode->data = num;
			numNode->left = NULL;
			numNode->right = NULL;

			root->right = numNode;
		}
		else
		{
			addTreeNode(root->right, num);
		}
	}
}

void printBreadthFirst(TreeNode* root)
{
	Node* currNode;
	emptyQueue();
	enqueue(root);

	while (!isQueueEmpty()) 
	{
		currNode = dequeue();

		printf("%d ", currNode->data->data);
		
		if (currNode->data->left != NULL)
		{
			enqueue(currNode->data->left);
		}
		
		if (currNode->data->right != NULL)
		{
			enqueue(currNode->data->right);
		}
	}

	printf("\n\0");
}

void printDepthFirst(TreeNode* root)
{
	Node* currNode;
	emptyStack();
	push(root);

	while (!isStackEmpty())
	{
		currNode = pop();

		printf("%d ", currNode->data->data);

		if (currNode->data->left != NULL)
		{
			push(currNode->data->left);
		}

		if (currNode->data->right != NULL)
		{
			push(currNode->data->right);
		}
	}

	printf("\n\0");
}

TreeNode* createMirroredTree(TreeNode* root)
{
	TreeNode* currNode;

	if (root == NULL)
	{
		return NULL;
	}

	//Create a new node and recursively switch the left and right.
	currNode = malloc(sizeof(TreeNode));
	currNode->data = root->data;
	currNode->left = createMirroredTree(root->right);
	currNode->right = createMirroredTree(root->left);

	return currNode;
}

void printTree(TreeNode* root, short preorderInorderOrPost)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		if (preorderInorderOrPost == 0)
		{
			//Preorder: VLR
			printf("%d ", root->data);
			printTree(root->left, preorderInorderOrPost);
			printTree(root->right, preorderInorderOrPost);
		}
		else if (preorderInorderOrPost == 1)
		{
			//Inorder: LVR
			printTree(root->left, preorderInorderOrPost);
			printf("%d ", root->data);
			printTree(root->right, preorderInorderOrPost);
		}
		else
		{
			//Postorder: LRV
			printTree(root->left, preorderInorderOrPost);
			printTree(root->right, preorderInorderOrPost);
			printf("%d ", root->data);
		}
	}

}

void deleteTree(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}

	//Free memmory from the bottom upward to ensure we remove all nodes.
	deleteTree(root->left);
	deleteTree(root->right);
	free(root);
}

int main()
{
	TreeNode* theRoot = malloc(sizeof(TreeNode));
	TreeNode* temp;
	theRoot->data = 5;
	theRoot->left = NULL;
	theRoot->right = NULL;

	addTreeNode(theRoot, 6);
	addTreeNode(theRoot, 2);
	addTreeNode(theRoot, 4);
	addTreeNode(theRoot, 7);

	temp = createMirroredTree(theRoot);

	printf("\n=========Breath first and depth first traversals.=========\n\0");
	printBreadthFirst(theRoot);
	printDepthFirst(theRoot);

	printf("\n=========Print both trees (Preorder).=========\n\0");
	printTree(theRoot, 0);
	printf("\n\0");
	printTree(temp, 0);

	printf("\n=========Print both trees (Inorder).=========\n\0");
	printTree(theRoot, 1);
	printf("\n\0");
	printTree(temp, 1);

	printf("\n=========Print both trees (Postorder).=========\n\0");
	printTree(theRoot, 2);
	printf("\n\0");
	printTree(temp, 2);

	deleteTree(theRoot);
	deleteTree(temp);

	system("pause");
	return 0;
}