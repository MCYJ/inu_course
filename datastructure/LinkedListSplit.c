#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[100];
} element;
typedef struct ListNode { // 노드 타입
	element data;
	struct ListNode* link;
} ListNode;

void print_list(ListNode* head)
{
	printf("head->");
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%s->", p->data.name);
	printf("NULL \n");
}

// 오류 처리 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode* head, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); // (1)
	p->data = value; // (2) à why? 배열 = 배열
	p->link = head; // (3) 헤드 포인터의 값을 복사
	head = p; // (4) 헤드 포인터 변경
	return head;
}

// search 함수 구현
ListNode* search(ListNode* head, char* data)
{
	ListNode* p = head;

	while (p != NULL) {
		if (strcmp(p->data.name, data) == 0) {
			// 탐색 단어 찾은 경우, 단어의 주소와 함께 return
			return p;
		}
		p = p->link;
	}
	// 탐색하려는 단어를 찾지 못했을 경우, NULL 반환
	return NULL;
}
// delete 함수 구현
void delete(ListNode* n) 
{
	free(n);
}
// split_list 구현
void split_list(ListNode* head, ListNode* n)
{
	ListNode* head1;
	ListNode* head2;

	head1 = head;
	while (head->link != n) {
		head = head->link;
	}
	head2 = head->link->link;
	head->link = NULL;

	delete(n);

	printf("list 1: ");
	print_list(head1);
	printf("list 2: ");
	print_list(head2);
}

// 테스트 프로그램
int main(void)
{
	ListNode* head = NULL;
	element data;

	// 제시 단어 저장
	strcpy(data.name, "PEACH");
	head = insert_first(head, data);

	strcpy(data.name, "MELON");
	head = insert_first(head, data);

	strcpy(data.name, "MANGO");
	head = insert_first(head, data);

	strcpy(data.name, "LEMON");
	head = insert_first(head, data);

	strcpy(data.name, "BANANA");
	head = insert_first(head, data);

	strcpy(data.name, "KIWI");
	head = insert_first(head, data);

	strcpy(data.name, "APPLE");
	head = insert_first(head, data);

	print_list(head);
	printf("삭제 단어 : LEMON\n");

	// split_list에 head와 삭제할 단어를 찾는 search 함수 입력
	split_list(head, search(head, "LEMON"));

	return 0;
}
