#include <iostream>

using	namespace std;

class Circle {
	int radius;
	string name;
public:
	void setCircle(string name, int radius);
	double getArea();
	string getName();
};

void Circle::setCircle(string name, int radius) {
	this->name = name;
	this->radius = radius;
}

double Circle::getArea() {
	return 3.14 * radius * radius;
}

string Circle::getName() {
	return name;
}

class CircleManager {
	
	int size;
public:
	Circle* p;
	CircleManager(int size);
	~CircleManager();
	void searchByName();
	void searchByArea();
};

CircleManager::CircleManager(int size) {
	this->size = size;
	p = new Circle[size];
}

CircleManager::~CircleManager() {
//	delete[] p;
}

void CircleManager::searchByName() {
	string name;
	cin >> name;
	for (int i = 0; i < size; i++)
	{
		if (p[i].getName() == name) {
			cout << p[i].getName() << "의 면적은 " << p[i].getArea() << endl;
			break;
		}
	}
}

void CircleManager::searchByArea() {
	int area;
	cin >> area;

	for (int  i= 0;  i < size; i++)
	{
		if (p[i].getArea() > area) {
			cout << p[i].getName() << "의 면적은 " << p[i].getArea() << ",";
		}
	}
	cout << endl;
}

int main(void) {
	cout << "원의 개수 >> ";
	int num;
	cin >> num;
	CircleManager c(num);
	for (int i = 0; i < num; i++)
	{
		string name;
		int radius;
		cout << "원 " << i + 1 << "의 이름과 반지름 >> ";
		cin >> name;
		cin >> radius;
		c.p[i].setCircle(name+"\0", radius);
	}
	cout << "검색하고자 하는 원의 이름 >> ";
	c.searchByName();
	cout << "최소 면적을 정수로 입력하세요 >> ";
	c.searchByArea();
}