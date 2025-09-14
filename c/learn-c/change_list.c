#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insert_node(int data, Node* head)
{
	struct Node* current = head;
	struct Node* new = malloc(sizeof(struct Node));
	if (head == NULL)
	{
		new->next = NULL;
		new->data = data;
		return new;
	}
	while (current->next != NULL)
	{
		current = current->next;
	}
	new->data = data;
	new->next = NULL;
	current->next = new;
	return head;
}

Node* delete_node(int target, Node* head)
{
	struct Node* current = head;
	struct Node* previous = NULL;

	while (current != NULL)
	{
		if (current->data == target)
		{
			if (previous == NULL)
			{
				head = current->next;
				free(current);
				return head;
			}
			previous->next = current->next;
			free(current);
			return head;
		}
		previous = current;
		current = current->next;
	}
	return head;
}

void print_list(Node *head)
{
	while (head != NULL)
	{
		printf("%d", head->data);
		head = head->next;
	}
	printf("\n");
}

void empty_list(Node *head)
{
	struct Node *temp = head;
	while (head != NULL)
	{
		head = head->next;
		free(temp);
		temp = head;
	}
}

Node* reverse_list(Node *head)
{
	struct Node *upcoming = NULL;
	struct Node *previous = NULL;
	struct Node *current = head;
	while (current != NULL)
	{
		upcoming = current->next;
		current->next = previous;
		previous = current;
		current = upcoming;
	}
	return previous;
}

int main()
{
	int i = 0;
	struct Node *head = NULL;

	while (i < 10)
	{
		head = insert_node(i, head);
		i++;
	}
	print_list(head);
	head = reverse_list(head);
	print_list(head);
}
