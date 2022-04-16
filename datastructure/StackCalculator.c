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
#include <string.h>

// int type을 element라는 이름으로 사용
typedef int element;

// 자기참조구조체 선언
// stack 사용을 위한 node 구조체선언
typedef struct StackNode {
	element data;
	double fdata;
	struct StackNode* link;
} StackNode;

// node의 linked list로써의 사용을 위한 linkedstacktype 구조체선언
typedef struct {
	StackNode* top;
} LinkedStackType;

/*
	함수명 : init
	인 자 : LinkedStackType pointer
	리턴형 : void
	설 명 : Stack의 top을 null로 할당하여, LinkedStackType을 초기화 한다.
*/
void init(LinkedStackType* s) {
	s->top = NULL;
}


/*
	함수명 : isEmpty
	인 자 : LinkedStackType pointer
	리턴형 : element(int)
	설 명 : stack이 비어있는지 확인하는 함수로써, top값과 NULL값의 비교식을 return 한다.
*/
element isEmpty(LinkedStackType* s) {
	return (s->top == NULL);
}

/*
	함수명 : pop
	인 자 : LinkedStackType pointer
	리턴형 : element(int)
	설 명 : stack의 top에 위치하고 있는 값을 return하고, stack에 값이 없을 경우 error 메시지를 출력한다.
*/
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

/*
	함수명 : fpop
	인 자 : LinkedStackType pointer
	리턴형 : double
	설 명 : 실수값의 저장을 위해 만들어진 함수로, type을 제외한 나머지 로직은 pop함수와 동일하다.
*/
double fpop(LinkedStackType* s) {
	if (isEmpty(s)) {
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		StackNode* temp = s->top;
		double fdata = temp->fdata;
		s->top = s->top->link;
		free(temp);
		return fdata;
	}
}

/*
	함수명 : push
	인 자 : 1) LinkedStackType pointer 2) item(element)
	리턴형 : void
	설 명 : stack에 값을 저장하기 위해 고안된 함수로써, StackNode pointer type의 temp로 메모리할당을 받아, node에 data를 저장하고, stack의 top에 node의 주소를 할당시킨다.
*/
void push(LinkedStackType* s, element item) {
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	temp->data = item;
	temp->link = s->top;
	s->top = temp;
}

/*
	함수명 : fpush
	인 자 : 1) LinkedStackType pointer 2) item(double)
	리턴형 : void
	설 명 : double형 data를 저장하기 위해 고안된 함수로써, push와 동일한 로직으로 동작한다.
*/
void fpush(LinkedStackType* s, double item) {
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	temp->fdata = item;
	temp->link = s->top;
	s->top = temp;
}

/*
	함수명 : peek
	인 자 : LinkedStackType pointer
	리턴형 : element(int)
	설 명 : stack의 top에 위치한 data를 return하는 함수로써, stack이 비어있으면, NULL을 return 한다.
*/
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

/*
	함수명 : fpeek
	인 자 : LinkedStackType
	리턴형 : double
	설 명 : stack의 top에 위치한 fdata를 return하는 함수로써, stack이 비어있으면, NULL을 return 한다.
*/
double fpeek(LinkedStackType* s) {
	if (isEmpty(s)) {
		// stack이 비어있는 경우 NULL return
		return 0;
	}
	else {
		// stack의 top에 위치한 data return
		return s->top->fdata;
	}
}

/*
	함수명 : isFull
	인 자 : LinkedStackType pointer
	리턴형 : int
	설 명 : stack이 가득찼는지 여부를 return 한다, 하지만, 이론상 full상태는 발생하지 않으므로, 0을 반환
*/
int isFull(LinkedStackType* s) {
	// linkedlist에서 이론상으로 full상태는 발생하지 않음 (다른 메모리영역을 침범하는 경우 제외)
	return 0;
}

/*
	함수명 : bracketCheck
	인 자 : char pointer ch
	리턴형 : int
	설 명 : 주어진 문자열에서 괄호검사를 진행하여 문제가 없을시 1 return, 문제발생시 0 return
*/
int bracketCheck(char* ch) {
	// stack 선언
	LinkedStackType s;
	// stack 초기화
	init(&s);
	// 문자열 순회를 위한 index 선언
	int i = 0;
	// 주어진 문자열을 순회하며 괄호검사를 진행한다
	// 문자열의 마지막값은 NULL이므로, NULL이 아닌 이상 순회를 지속한다.
	while (ch[i] != NULL) {
		// ch 문자열의 각 값을 활용하여 분기별로 판단하기 위해 switch문을 사용
		switch (ch[i])
		{
		// 여는 괄호인 경우, 괄호를 그대로 stack에 push한다.
		case '(': case '[': case '{':
			push(&s, ch[i]);
			break;
		// 닫는 괄호인 경우, 추가적인 로직을 사용하여 검사를 진행한다.
		case ')': case ']': case '}':
			// 닫는 괄호를 만났을 때 stack이 비어있는 경우, 이는 닫는 괄호 한개가 남는 상황이므로 실패인 0을 return 한다.
			if (isEmpty(&s)) {
				return 0;
			}
			// stack에 값이 존재하는 경우 이 값을 pop하여 검사를 진행한다.
			else {
				// pop한 값 data변수에 할당
				element data = pop(&s);
				// switch문을 사용하여, stack의 값을 판단
				switch (data)
				{
				// 동일한 짝의 괄호가 아닌 경우 실패인 0을 return
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
			// 동일한 괄호인 경우 별도의 할당없이 break
			break;
		}
		// index를 증가시키며 ch문자열을 순회한다.
		i++;
	}
	// 괄호 검사 후, stack에 남아있는 data가 없는 경우 성공인 1을 return
	if (isEmpty(&s)) {
		return 1;
	}
	// 괄호 검사 후, stack에 값이 남아있는 경우, 괄호의 짝이 맞지않는 것이므로 실패인 0을 return
	else {
		return 0;
	}
}

/*
	함수명 : prec
	인 자 : char op
	리턴형 : int
	설 명 : 연산자의 우선순위를 반환하기 위한 함수
*/
int prec(char op) {
	switch (op) {
	// 괄호의 경우, 0의 우선순위를 반환
	case '(': case ')': return 0;
	// +-의 경우, 1의 우선순위를 반환
	case '+': case '-': return 1;
	// */의 경우, 2의 우선순위를 반환
	case '*': case '/': return 2;
	}
	// 이외 연산자의 경우 -1의 우선순위를 반환
	return -1;
}

/*
	함수명 : infix_to_postfix
	인 자 : char pointer ch
	리턴형 : char pointer
	설 명 : 중위식 문자열을 입력받아서 후위식 문자열을 return 하는 함수
*/
char* infix_to_postfix(char* ch) {
	// 후위식 문자열을 저장한 char pointer를 선언함
	char* str = (char*)malloc(sizeof(char) * 100);
	// strcpy를 활용하여 str 초기화
	strcpy(str, "");
	// 중위식의 후위식 변환을 위한 stack선언
	LinkedStackType* s;
	// stack 초기화
	init(&s);
	// 중위식 값을 받을 element(int) type 변수 선언
	element e;
	// 중위식 문자열의 순회를 위한 index 변수 선언
	int i = 0;
	// 중위식 문자열을 순회하는데, 문자열은 마지막 문자가 NULL이므로, 값이 NULL이 아닌동안 순회를 한다.
	while (ch[i] != NULL) {
		// index에 따라 중위식 문자열의 값을 switch문을 활용하여 판단
		switch (ch[i])
		{
		// ch[i]가 연산자인 경우
		case '+': case '-': case '/': case '*':
			// stack이 비어있는지 여부를 확인하고, 연산자의 우선순위를 prec함수를 통해 비교하여 peek을 통해 확인한 stack의 top에 존재하는 연산자의 우선순위가 큰 경우, stack에 존재하는 연산자를 pop하여, 후위식문자열에 추가한다.
			while (!isEmpty(&s) && (prec(ch[i]) <= prec(peek(&s)))) {
				// stack의 top에 위치한 data pop
				e = pop(&s);
				// 후위식 문자열에 추가
				strncat(str, &e, 1);
				// 추후 구분을 위해 공백도 추가
				strcat(str, " ");
			}
			// ch[i]는 stack으로 push
			push(&s, ch[i]);
			break;
		// 여는 괄호일 경우, stack으로 push
		case '(': case '[': case '{':
			push(&s, ch[i]);
			break;
		// 닫는 괄호일 경우, stack에서 값이 여는 괄호가 나올때까지 pop을 반복한다.
		case ')': case ']': case '}':
			e = pop(&s);
			// 여는 괄호가 아닌동안에는 pop한 값을 모두 후위식문자열에 붙여넣는다.
			while (e != '(' && e != '[' && e != '{') {
				strncat(str, &e, 1);
				strcat(str, " ");
				e = pop(&s);
			}
			break;
		// 연산자와 괄호가 아닌경우의 값은 default로직을 통해 처리한다.
		default:
			// 만약 data의 뒤에 소수점의 존재를 의미하는 '.'가 있는 경우, 
			if (ch[i + 1] == '.') {
				strncat(str, &ch[i], 1);
				i++;
				strncat(str, &ch[i], 1);
				while (ch[i+1] != NULL && ch[i+1] >= 48 && ch[i+1] <= 57) {	
					i++;
					strncat(str, &ch[i], 1);
				}
				strcat(str, " ");
			}
			else {
				strncat(str, &ch[i], 1);
				strcat(str, " ");
			}
			
			break;
		}
		i++;
	}
	while (!isEmpty(&s)) {
		e = pop(&s);
	//	printf("%c", e);
		if (!isEmpty(&s)) {
			strncat(str, &e, 1);
			strcat(str, " ");
		}
		else {
			strncat(str, &e, 1);
		}
		
	}
	return str;
}

char* infix_to_prefix(char* ch) {
	LinkedStackType* s;
	LinkedStackType* op;
	LinkedStackType* dt;

	init(&s);
	init(&op);
	init(&dt);
	char* pre_str = (char*)malloc(sizeof(char) * 100);
	strcpy(pre_str, "");
	element data, oper;
	int i = 0;

	// 값 뒤집는 용도로 stack 하나 선언할것
	while (ch[i] != NULL) {
		if (ch[i+1] == '.') {
			push(&s, ch[i]);
			i++;
			push(&s, ch[i]);
			while (ch[i+1] != NULL && ch[i+1] >= 48 && ch[i+1] <= 57) {
				i++;
				push(&s, ch[i]);
			}
			push(&s, NULL);
		}
		else {
			push(&s, ch[i]);
		}
		i++;
	}
	while (!isEmpty(&s)) {
		data = pop(&s);
		switch (data)
		{
		// 연산자/괄호인경우
		case '+': case '-': case '/': case '*':
			// 연산자 스택의 최상위 값과 우선순위 비교
			while (!isEmpty(&op) && (prec(data) <= prec(peek(&op)))) {
				oper = pop(&op);
				push(&dt, oper);
			}
			push(&op, data);
			break;
		case ')': case ']': case '}':
			push(&op, data);
			break;
		case '(': case '[': case '{':
			oper = pop(&op);
			push(&dt, oper);
			while (oper != ')' && oper != ']' && oper != '}') {
				oper = pop(&op);
				push(&dt, oper);
			}
			break;
		// 숫자인 경우
		default:
			push(&dt, data);
			break;
		}
	}
	while (!isEmpty(&op)) {
		oper = pop(&op);
		push(&dt, oper);
	}

	while (!isEmpty(&dt)) {
		data = pop(&dt); 
		if (data != '(' && data != '[' && data != '{' && data != ')' && data != ']' && data != '}') {
			if (peek(&dt) == '.') {
				strncat(pre_str, &data, 1);
				// '.' pop으로 data에 할당
				data = pop(&dt);
				strncat(pre_str, &data, 1);
				// 숫자 스택의 peek값이 숫자인 경우, space없이 pre_str에 추가
				while (!isEmpty(&dt) && peek(&dt) >= 48 && peek(&dt) <= 57) {
					data = pop(&dt);
					strncat(pre_str, &data, 1);
				}
			//	strcat(pre_str, " ");
			}
			else {
				strncat(pre_str, &data, 1);
				strcat(pre_str, " ");
			}
		}
	}

	return pre_str;
}

double postfix_calculate(char* ch) {
	LinkedStackType* s;
	init(&s);
	double op1, op2, value;
	int i = 0;
	while (ch[i] != NULL) {
		// 항목이 피연산자
		if (ch[i] != '+' && ch[i] != '-' && ch[i] != '*' && ch[i] != '/' && ch[i] != ' ') {
			value = ch[i] - '0';
			if (ch[i + 1] == '.') {
				// i를 증가시켜서 '.'으로 index 이동
				i++;
				int decimal = 1;
				double d_value;
				while (ch[i+1] != NULL && ch[i+1] >= '0' && ch[i+1] <= '9') {
					i++;
					d_value = ch[i] - '0';
					for (int j = 1; j <= decimal; j++) {
						d_value *= 0.1;
					}
					value += d_value;
					decimal++;
				}
				fpush(&s, value);
			}
			else {
				fpush(&s, value);
			}
			
		}
		else if (ch[i] == ' ') {

		}
		// 항목이 연산자
		else {
			op2 = fpop(&s);
			op1 = fpop(&s);
			switch (ch[i])
			{
			case '+': fpush(&s, op1 + op2); break;
			case '-': fpush(&s, op1 - op2); break;
			case '*': fpush(&s, op1 * op2); break;
			case '/': fpush(&s, op1 / op2); break;
			}
		}
		i++;
	}

	return fpop(&s);
}

int main(void) {
	char *ch = (char *)malloc(sizeof(char)*100);

	
	printf("중위식을 입력하세요: ");
	scanf("%s", ch);
//	strcpy(ch, "(123+b)*c");
//	strcpy(ch, "5*(3.5-2)+4.68/3");

	// 괄호 검사
	if (bracketCheck(ch)) {
		printf("괄호에 오류없음\n");
	}
	else {
		fprintf(stderr, "괄호에 오류있음\n");
		exit(1);
	}

	// 중위식->전위식
	// 후위식이랑 반대개념
	printf("전위식: ");
	printf("%s", infix_to_prefix(ch));
	printf("\n");

	// 중위식->후위식
	// ch4 37page
	printf("후위식: ");
	printf("%s", infix_to_postfix(ch));
	printf("\n");
	
	// 후위식 계산
	// ch4 31page
	printf("계산결과: ");
	printf("%lf", postfix_calculate(infix_to_postfix(ch)));
//	postfix_calculate("5 3.5 2 - * 4.68 3 / +");
	printf("\n");
	// 1. 부호검사/문자열검사 
	// 2. 소수점처리
	// 3. 결과값 띄어쓰기
	// 4. 두자리수 처리

	return 0;
}

/*
	함수명 : 
	인 자 : 
	리턴형 : 
	설 명 : 
*/