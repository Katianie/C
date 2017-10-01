/** Breadth First and Depth First Search: LinkedList.c
* This program shows how to traverse a Tree in various ways.
*
* Eddie O'Hagan
* Copyright © 2013 Katianie.com
*/
#include "LinkedList.h"

void reverse()
{
	Node* currentNode = (*myHead);
	Node* prevNode = NULL;
	Node* nextNode = currentNode->next;

	while (currentNode != NULL)
	{
		//Handle to of whats ahead since we will break that chain.
		nextNode = currentNode->next;

		//Break the chain by seting the currentNode to what was behind it (Reversing it).
		currentNode->next = prevNode;

		//Move the prevNode and the currentNode up.
		prevNode = currentNode;
		currentNode = nextNode;
	}

	*myHead = prevNode;
}

Node** addNode(int new_data)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	Node* tempHead;

	if ((*myHead) == NULL)
	{
		*myHead = new_node;
	}
	else
	{
		tempHead = (*myHead);

		while (tempHead->next != NULL)
		{
			tempHead = tempHead->next;
		}

		tempHead->next = new_node;
	}

	new_node->data = new_data;
	new_node->next = NULL;

	return myHead;
}

void printList()
{
	Node* temp = myHead;

	while (temp != NULL)
	{
		printf("%d  ", temp->data);
		temp = temp->next;
	}
}