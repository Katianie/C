/** Breadth First and Depth First Search: Stack.h
* This program shows how to traverse a Tree in various ways.
*
* Eddie O'Hagan
* Copyright © 2013 Katianie.com
*/
#includ
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Node.h"

Node* myHead;

void push(TreeNode* data);
Node* pop();
void printStack();
void emptyStack();
bool isStackEmpty();