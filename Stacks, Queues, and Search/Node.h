/** Breadth First and Depth First Search: TreeNode.c
* This program shows how to traverse a Tree in various ways.
*
* Eddie O'Hagan
* Copyright © 2013 Katianie.com
*/
#pragma once

typedef struct TreeNode
{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;

}TreeNode;

typedef struct Node
{
	TreeNode* data;
	struct Node* next;

}Node;

