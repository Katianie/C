/** Breadth First and Depth First Search: Queue.h
* This program shows how to traverse a Tree in various ways.
*
* Eddie O'Hagan
* Copyright © 2013 Katianie.com
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Node.h"

Node* myHead;

void enqueue(TreeNode* data);
Node* dequeue();
void printQueue();
void emptyQueue();
bool isQueueEmpty();
