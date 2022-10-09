#include <iostream>

using namespace std;

// class ¼±¾ð
class Person {
	int id;
public:
	Person() {}
	Person(int id) { this->id = id; }

	int getId() { return id; }
	void setId(int id) { this->id = id; }
	
};
Person& getReference(Person &p) {
	return p;
}
int main(void) {
	

	Person p1(1);
	cout << p1.getId() << endl;
	Person p2 = p1;
	cout << p2.getId() << endl;

	p2.setId(2);

	cout << p1.getId() << endl;
}