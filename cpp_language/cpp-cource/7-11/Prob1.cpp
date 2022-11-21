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
	push������ << ������, pop������ >> ������, ����ִ½������� �˱� ���� !������
*/

int main() {
	Stack stack;
	stack << 3 << 5 << 10; // 3, 5, 10�� ������� Ǫ��

	while (true) {
		if (!stack) break; // ���� empty
		int x;
		stack >> x; // ������ ž�� �ִ� ���� ��
		cout << x << ' ';
	}
	cout << endl;
}
