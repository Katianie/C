/** Reverse a Linked List: Main.c
* This program illustrates how reverse a linked list.
*
* Eddie O'Hagan
* Copyright © 2014 Katianie.com
*/
#include <stdio.h>

typedef struct Node
{
	int data;
	struct Node* next;

}Node;

void reverse(Node** head_ref)
{
	Node* currentNode = (*head_ref);
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

	*head_ref = prevNode;
}

void addNode(Node** head_ref, int new_data)
{
	Node* new_node = (Node*) malloc(sizeof(Node));
	Node* tempHead = (*head_ref);

	if ((*head_ref) == NULL)
	{
		*head_ref = new_node;
	}
	else
	{
		while (tempHead->next != NULL)
		{
			tempHead = tempHead->next;
		}

		tempHead->next = new_node;
	}

	new_node->data = new_data;
	new_node->next = NULL;
}

/* Function to print linked list */
void printList(Node* head)
{
	Node* temp = head;

	while (temp != NULL)
	{
		printf("%d  ", temp->data);
		temp = temp->next;
	}
}

int main()
{
	Node* head = NULL;

	for (int i = 1; i <= 10; i++)
	{
		addNode(&head, i);
	}

	printList(head);
	printf("\nHead is %d\n", head->data);

	reverse(&head);
	printList(head);
	printf("\nHead is %d\n", head->data);

	system("pause");
	return 0;
}