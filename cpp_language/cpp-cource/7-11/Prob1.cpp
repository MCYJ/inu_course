#include <iostream>

using namespace std;

class Stack {
	
	int top = -1;
public:
	int arr[3];
	void push(int num);
	int pop();
	Stack& operator<<(int num);
	void operator>>(int& num);
	bool operator!();
};

void Stack::push(int num) {
	top++;
	arr[top] = num;
}

int Stack::pop() {
	return arr[top--];
}

Stack& Stack::operator<<(int num) {
	push(num);
	return *this;
}

void Stack::operator>>(int& num) {
	num = pop();
}

bool Stack::operator!() {
	return top == -1;
}

/*
	push용으로 << 연산자, pop용으로 >> 연산자, 비어있는스택인지 알기 위해 !연산자
*/

int main() {
	Stack stack;
	stack << 3 << 5 << 10; // 3, 5, 10을 순서대로 푸시

	while (true) {
		if (!stack) break; // 스택 empty
		int x;
		stack >> x; // 스택의 탑에 있는 정수 팝
		cout << x << ' ';
	}
	cout << endl;
}
