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

class MyQueue : public BaseArray {
	int left, right;
public:
	MyQueue(int capacity);
	
	void enqueue(int num);
	int dequeue();

	int capacity();
	int length();
};

MyQueue::MyQueue(int capacity) : BaseArray(capacity) {
	left = 0;
	right = 0;
}

void MyQueue::enqueue(int num) {
	put(right++, num);
}

int MyQueue::dequeue() {
	return get(left++);
}

int MyQueue::capacity() {
	return getCapacity();
}

int MyQueue::length() {
	return right - left;
}


int main() {
	MyQueue mQ(100);
	int n;
	cout << "ť�� ������ 5���� ������ �Է��϶�>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mQ.enqueue(n); // ť�� ����
	}
	cout << "ť�� �뷮:" << mQ.capacity() << ", ť�� ũ��:" << mQ.length() << endl;
	cout << "ť�� ���Ҹ� ������� �����Ͽ� ����Ѵ�>> ";
	while (mQ.length() != 0) {
		cout << mQ.dequeue() << ' '; // ť���� �����Ͽ� ���
	}
	cout << endl << "ť�� ���� ũ�� : " << mQ.length() << endl;
}
