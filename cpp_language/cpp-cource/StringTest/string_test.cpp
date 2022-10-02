#include <iostream>

using namespace std;

int main(void) {
	string *name = new string[3];

	for (int i = 0; i < 3; i++)
	{
		cin >> name[i];
	}
	for(int i = 0; i < (*name).length(); i++)
	{
		cout << name[i];
	}
}