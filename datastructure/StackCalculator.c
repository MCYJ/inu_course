// 202101544 마영준
// stack calculator

/*
	중위식 입력
	1
	괄호 검증
	식 검증
	2
	중위식을 후위식으로
	중위식을 전위식으로
	3
	후위식을 계산

	* 소수점처리
*/

#include <stdio.h>
#include <stdlib.h>


typedef char element;

// 자기참조구조체 선언
typedef struct StackNode {
	element data;
	struct StackNode* link;
} StackNode;

typedef struct {
	StackNode* top;
} LinkedStackType;

// init 초기화 함수
void init(LinkedStackType* s) {
	s->top = NULL;
}

// isEmpty
int isEmpty(LinkedStackType* s) {
	return (s->top == NULL);
}

// pop
element pop(LinkedStackType* s) {
	if (isEmpty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		StackNode* temp = s->top;
		int data = temp->data;
		s->top = s->top->link;
		free(temp);
		return data;
	}
}

// push
void push(LinkedStackType* s, element item) {
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	temp->data = item;
	temp->link = s->top;
	s->top = temp;
}

// peek
element peek(LinkedStackType* s) {
	if (isEmpty(s)) {
		// stack이 비어있는 경우 NULL return
		return NULL;
	}
	else {
		// stack의 top에 위치한 data return
		return s->top->data;
	}
}

// isFull
int isFull(LinkedStackType* s) {
	// linkedlist에서 이론상으로 full상태는 발생하지 않음 (다른 메모리영역을 침범하는 경우 제외)
	return 0;
}

// 괄호검사함수
int bracketCheck(char* ch) {
	LinkedStackType s;
	init(&s);

	int i = 0;
	while (ch[i] != NULL) {
		//	printf("%d %c\n", i, ch[i]);
		switch (ch[i])
		{
		case '(': case '[': case '{':
			push(&s, ch[i]);
			break;
		case ')': case ']': case '}':
			if (isEmpty(&s)) {
				return 0;
			}
			else {
				element data = pop(&s);
				switch (data)
				{
				case '(':
					if (ch[i] != ')') {
						return 0;
					}
					break;
				case '[':
					if (ch[i] != ']') {
						return 0;
					}
					break;
				case '{':
					if (ch[i] != '}') {
						return 0;
					}
				}
			}
			break;
		}
		i++;
	}
	if (isEmpty(&s)) {
		return 1;
	}
	else {
		return 0;
	}
}

int main(void) {
	char *ch = (char *)malloc(sizeof(char)*100);

	
	printf("중위식을 입력하세요: ");
	scanf("%s", ch);
	
	

	// 괄호 검사
	if (bracketCheck(ch)) {
		printf("괄호에 오류없음\n");
	}
	else {
		fprintf(stderr, "괄호에 오류있음\n");
		exit(1);
	}

	// 중위식->후위식
	// ch4 37page
	
	// 중위식->전위식
	// 후위식이랑 반대개념

	// 후위식 계산
	// ch4 31page

	// *** 1. 부호검사/문자열검사 2. 소수점처리

	return 0;
}