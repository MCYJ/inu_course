#include <stdio.h>

struct node {
	struct node* prev;
	struct node* next;
	int value;
};

struct node array[10];
int g_index = -1;
struct node* init;

void insert(int v);
void _remove(int v);
void print();

int main(void)
{
	insert(10); insert(20);insert(15); insert(17); insert(5); insert(25); insert(3); insert(27); insert(23);
	_remove(15); _remove(25);  _remove(23); _remove(3); _remove(27); _remove(17); _remove(10); _remove(20); 
	_remove(5);

	return 0;
}

void insert(int v)
{
	//Managed nodes are defined as ones each whose value is not zero.
	//'init' always indicates the node whose value is minimal among managed nodes. 
	//e.g., managed nodes are '10', '20', and '15' (meaning insert(10); insert(20);insert(15); are called in turn), then, 'init' indicates the node whose value is '10'. 
	//All managed nodes are connected each other with member variables 'prev' and 'next'. 
	//Also, for each node (of managed ones), the value of the 'prev' node should be smaller than the node (except the first one), and
	//the value of the 'next' node should be larger than the node (except the last one).
	//'g_index' always indicates the index (of struct node array) of the node whose value was recently assigned.
	//e.g., managed nodes are '10', '20', and '15'(meaning insert(10); insert(20);insert(15); are called in turn), then, array[g_index] indicates the node whose value is 15. 
	//'prev' of the node indicated by 'init' is null.
	//'next' of the last node among manage nodes is null.
	g_index++;
	array[g_index].value = v; // 다음 index의 array의 value 에 v 할당

	if (init == NULL)
	{
		init = &array[g_index];
	}
	else
	{
		struct node* current = init;
	//	while (current->next != NULL && current->next->value < current->value)
		while (current->next != NULL && array[g_index].value > current->value) { // current 가 마지막 직전이거나 current의 value가 입력값보다 커지는 경우 멈춤
			current = current->next;
		}

		//there would be three cases
		// the node is inserted before the first node
		// the node is inserted after the last node
		// the node is inserted between two nodes
		
		if (array[g_index].value < current->value) {
			if (current->prev == NULL) {
				init = &array[g_index];
				array[g_index].next = current;
				current->prev = &array[g_index];
			}
			else {
				current->prev->next = &array[g_index];
				array[g_index].prev = current->prev;
				array[g_index].next = current;
				current->prev = &array[g_index];
			}
		} 
		else {
			current->next = &array[g_index];
			array[g_index].prev = current;
		}
		/*
		if (current->next == NULL) { // current의 앞에 아무것도 없는 경우 
			current->next = &array[g_index];
			array[g_index].prev = current;
		}
		else if(current->prev == NULL) {
			init = &array[g_index];
			array[g_index].next = current;
			current->prev = &array[g_index];
		}
		else {
			array[g_index].next = current->next;
			current->next->prev = &array[g_index];
			current->next = &array[g_index];
			array[g_index].prev = current;
			
		}
		*/
	}
	
	//the function 'print' should be called before the end of 'insert' function
	print();

}

void _remove(int v)
{
	//Suppose that there are three nodes A, B (whose value is v), and C, and 'prev' of B is A, and 'next' of B is C.
	//After this function, 'next' of A becomes C, and prev of C is A, meaning that B is logically removed from managed nodes.  
	//If 'next' of B is null (i.e., there are only A and B in managed nodes), A's 'next' becomes null. 
	//If 'prev' of B is null (i.e., there are only B and C in managed nodes), C's 'prev' becomes null. 
	//'init' always indicates the node whose value is minimal among managed nodes. 
	//If there is only B in a set of manage nodes (currently, 'next' and 'prev' of B should be null), 'init' gets to indicates null.
	

	struct node* current = init;
	while (current->value != v)
		current = current->next;

	//there would be three cases
	// the current node is inserted before the first node
	// the current node is inserted after the last node
	// the current node is inserted between two nodes
	if (current->prev == NULL && current->next == NULL) {
		init = NULL;
	}
	else if (current->prev == NULL) {
		init = current->next;
		current->next->prev = NULL;
	}
	else if (current->next == NULL) {
		current->prev->next = NULL;
	}
	else {
		current->prev->next = current->next;
		current->next->prev = current->prev;
		current->next = NULL;
		current->prev = NULL;
	}
	//the function 'print' should be called before the end of '_remove' function
	print();
}

void print()
{
	//(1) Print the value of the node indicated by 'init'.
	//(2) Then, print the value of 'next' node if any.
	//(3) Repeat the step (2) until the value of last node (among manged ones) is printed.
	struct node* current = init;

	if (init != NULL) {
		printf("%d ", current->value);

		while (current->next != NULL) {
			current = current->next;
			printf("%d ", current->value);
		} // null ptr exception occurr
	}
	

	
	printf("\n");

}
