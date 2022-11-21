#include <iostream>

using namespace std;

class Animal {
public:
	virtual void speak() {};
};

class Dog : public Animal {
	void speak() {
		cout << "�۸�" << endl;
	}
};

class Cat : public Animal {
	void speak() {
		cout << "�߿�" << endl;
	}
};

int main() {
	Animal* a1 = new Dog();
	a1->speak();

	Animal* a2 = new Cat();
	a2->speak();

	return 0;
}
