#include <iostream>

using namespace std;

class BaseArray {
private:
	int capacity; // 배열의 크기 
	int* mem; // 정수 배열을 만들기 위한 메모리의 포인터 
protected:
	BaseArray(int capacity = 100) {
		this->capacity = capacity;
		mem = new int[capacity];
	}
	~BaseArray() { delete[] mem; }
	void put(int index, int val) { mem[index] = val; }
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
};

class MyStack : public BaseArray {
	int top;
public:
	MyStack(int capacity);
	void push(int num);
	int pop();
	int length();
	int capacity();
};

MyStack::MyStack(int capacity) : BaseArray(capacity) {
	top = 0;
}

void MyStack::push(int num) {
	put(top++, num);
}

int MyStack::pop() {
	return get(--top);
}

int MyStack::length() {
	return top;
}

int MyStack::capacity() {
	return getCapacity();
}


int main() {
	MyStack mStack(100);
	int n;
	cout << "스택에 삽입할 5개의 정수를 입력하라>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mStack.push(n); // 스택에 푸시
	}
	cout << "스택 용량:" << mStack.capacity() << ", 스택 크기:" << mStack.length() << endl;
	cout << "스택의 모든 원소를 팝하여 출력한다>> ";
	while (mStack.length() != 0) {
		cout << mStack.pop() << ' '; // 스택에서 팝
	}
	cout << endl << "스택의 현재 크기 : " << mStack.length() << endl;
}