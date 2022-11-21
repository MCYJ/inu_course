#include <iostream>

using namespace std;

class SortedArray {
	int size; // 현재 배열의 크기
	int* p; // 정수 배열에 대한 포인터
	void sort(); // 정수 배열을 오름차순으로 정렬
public:
	SortedArray(); // p는 NULL로 size는 0으로 초기화
	SortedArray(SortedArray& src); // 복사 생성자
	SortedArray(int p[], int size); // 생성자. 정수 배열과 크기를 전달받음
	~SortedArray(); // 소멸자
	SortedArray operator + (SortedArray& op2);
	SortedArray& operator = (const SortedArray& op2); // 현재 배열에 op2 배열을 복사
	void show(); // 배열의 원소 출력
};

SortedArray::SortedArray() {
	p = NULL;
	size = 0;
}

SortedArray::SortedArray(SortedArray& src) {
	this -> size = src.size;
	this -> p = new int[src.size];

	for (int i = 0; i < src.size; i++)
	{
		this -> p[i] = src.p[i];
	}
}

SortedArray::SortedArray(int p[], int size) {
	this->size = size;
	this->p = new int[size];
	for (int i = 0; i < size; i++)
	{
		this->p[i] = p[i];
	}
	sort();
}

SortedArray::~SortedArray() {
	delete[] p;
}

SortedArray SortedArray::operator + (SortedArray& op2) {
	SortedArray s;

	s.size = this->size + op2.size;
	s.p = new int[this->size + op2.size];

	for (int i = 0; i < this->size; i++)
	{
		s.p[i] = this->p[i];
	}
	for (int i = 0; i < op2.size; i++)
	{
		s.p[this->size + i] = op2.p[i];
	}

	s.sort();
	
	return s;
}

SortedArray& SortedArray::operator = (const SortedArray& op2) {
	delete[] this->p;
	this->size = op2.size;
	this->p = new int[op2.size];

	for (int i = 0; i < op2.size; i++)
	{
		this->p[i] = op2.p[i];
	}

	return *this;
}

void SortedArray::show() {
	cout << "배열 출력 : ";
	for (int i = 0; i < size; i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;
}

void SortedArray::sort() {
	for(int i = 0; i < size; i++)
	{
		for (int j = 0; j < size -1 - i; j++)
		{
			if (p[j] > p[j+1]) {
				int tmp = p[j+1];
				p[j+1] = p[j];
				p[j] = tmp;
			} 
		}
	}
}

int main() {
	int n[] = { 2, 20, 6 };
	int m[] = { 10, 7, 8, 30 };
	SortedArray a(n, 3), b(m, 4), c;

	c = a + b; // +, = 연산자 작성 필요
	// + 연산자가 SortedArray 객체를 리턴하므로 복사 생성자 필요

	a.show();
	b.show();
	c.show();
}