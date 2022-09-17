#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main(void) {
	char name[100];
	char longest[100];
	int length = 0;
	cout << "5 명의 이름을 ':'으로 구분하여 입력하세요" << endl;
	cout << ">>";

	for (int i = 0; i < 5; i++)
	{
		cin.getline(name, 100, ';');
		cout << i + 1 << " : " << name << endl;
		if (length < strlen(name))
		{
			length = strlen(name);
			strcpy(longest, name);
		}
	}
	cout << "가장 긴 이름은 " << longest << " 님" << endl;

	system("pause");
	return 0;
}