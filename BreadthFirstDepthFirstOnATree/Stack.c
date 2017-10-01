/** Breadth First and Depth First Search: Stack.c
* This program shows how to traverse a Tree in various ways.
*
* Eddie O'Hagan
* Copyright © 2013 Katianie.com
*/
#include "Stack.h"

void push(TreeNode* item)
{
	Node* nextNode = malloc(sizeof(Node));

	if (myHead == NULL)
	{
		nextNode->next = NULL;
		myHead = nextNode;
	}
	else
	{
		nextNode->next = myHead;
		myHead = nextNode;
	}

	nextNode->data = item;
}

Node* pop()
{
	Node* nextNode = NULL;
	Node* oldNode = NULL;

	if (myHead != NULL)
	{
		//Copy the head node.
		oldNode = malloc(sizeof(Node));
		oldNode->data = myHead->data;
		oldNode->next = NULL;

		//Copy where myHead's next is.
		nextNode = myHead->next;

		//Delete what myHead is pointing to from memory.
		free(myHead);

		//Set our head to what was next.
		myHead = nextNode;
	}

	return oldNode;
}

void printStack()
{
	Node* temp = myHead;

	while (temp != NULL)
	{
		printf("%d  ", *temp->data);
		temp = temp->next;
	}

	printf("\n\0");
}

void emptyStack()
{
	//Keep popping aslong as there are things to dequeue.
	while (pop());
}

bool isStackEmpty()
{
	return myHead == NULL;
}
