#include <iostream>
#include <cstring>

using namespace std;

int main(void) {
	char str[100];
	cout << "���ڿ� �Է�>>";
	cin.getline(str, 100);

	int len = strlen(str);

	for (int i = 1; i <= len; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << str[j];
		}
		cout << endl;
	}
}