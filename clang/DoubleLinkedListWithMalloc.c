#include <stdio.h>

struct node {
	struct node* prev;
	struct node* next;
	int value;
};

struct node* init;

void insert(int v);
void _remove(int v);
void print();

int main(void)
{
	insert(10); insert(20); insert(15); insert(17); insert(5); insert(25); insert(3); insert(27); insert(23);
	_remove(15); _remove(25);  _remove(23);  _remove(3); _remove(27); _remove(17); _remove(10); _remove(20); _remove(5);

	return 0;
}

void insert(int v)	//Eve`ry inserted node should be sorted in ascending order of value.
{
	struct node* ptr = (struct node*)malloc(sizeof(struct node));
	ptr->value = v;
	ptr->next = NULL;
	ptr->prev = NULL;

	if (init == NULL) {
		init = ptr;
	}
	else {
		struct node* current = init;

		if (init->value > v) {
			init->prev = ptr;
			ptr->next = init;
			init = ptr;
		}
		else {
			while (current->next != NULL && current->next->value < v) {
				current = current->next;
			}
			// the current node is the last node 
			if (current->next == NULL) {
				current->next = ptr;
				ptr->prev = current;
			}
			// at least the last node is the last node
			else {
				current->next->prev = ptr;
				ptr->prev = current;
				ptr->next = current->next;
				current->next = ptr;
				
			}
		}
	}

	print();
}

void _remove(int v) //The node whose value is 'v' will be removed
{
	if (init == NULL) {
		printf("Nothing to be popped\n");
	}
	else if (init->next == NULL) {
		free(init);
		init = NULL;
	}
	else {
		struct node* current = init;
		
		while (current->value != v) {
			current = current->next;
		}
		if (init->value == v) {
			init = current->next;
			current->next->prev = NULL;
		}
		else if (current->next == NULL) {
			current->prev->next = NULL;
		}
		else {
			current->prev->next = current->next;
			current->next->prev = current->prev;
		}
		free(current);
	}
	print();
}

void print()
{
	if (init == NULL) {
		printf("The stack just emptied.");
	}
	else {
		struct node* current = init;
		while (current->next != NULL) {
			printf("%d ", current->value);
			current = current->next;
		}
		printf("%d \n", current->value);
	}
}
