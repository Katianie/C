/** Breadth First and Depth First Search: Queue.c
* This program shows how to traverse a Tree in various ways.
*
* Eddie O'Hagan
* Copyright © 2013 Katianie.com
*/
#include "Queue.h"

void enqueue(TreeNode* data)
{
	Node* nextNode = malloc(sizeof(Node));
	Node* tempHead;

	if (myHead == NULL)
	{
		myHead = nextNode;
	}
	else
	{
		tempHead = myHead;

		while (tempHead->next != NULL)
		{
			tempHead = tempHead->next;
		}

		tempHead->next = nextNode;
	}

	nextNode->data = data;
	nextNode->next = NULL;
}

Node* dequeue()
{
	Node* oldNode = NULL;
	Node* nextNode = NULL;

	if (myHead != NULL)
	{
		//Copy over the old data.
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

void printQueue()
{
	Node* temp = myHead;

	while (temp != NULL)
	{
		printf("%d  ", *temp->data);
		temp = temp->next;
	}

	printf("\n\0");
}

void emptyQueue()
{
	//Keep dequeueing aslong as there are things to dequeue.
	while (dequeue());
}

bool isQueueEmpty()
{
	return myHead == NULL;
}