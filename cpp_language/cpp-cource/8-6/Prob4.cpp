#include <iostream>

using namespace std;

class BaseArray {
private:
	int capacity; // �迭�� ũ�� 
	int* mem; // ���� �迭�� ����� ���� �޸��� ������ 
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
	cout << "���ÿ� ������ 5���� ������ �Է��϶�>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mStack.push(n); // ���ÿ� Ǫ��
	}
	cout << "���� �뷮:" << mStack.capacity() << ", ���� ũ��:" << mStack.length() << endl;
	cout << "������ ��� ���Ҹ� ���Ͽ� ����Ѵ�>> ";
	while (mStack.length() != 0) {
		cout << mStack.pop() << ' '; // ���ÿ��� ��
	}
	cout << endl << "������ ���� ũ�� : " << mStack.length() << endl;
}