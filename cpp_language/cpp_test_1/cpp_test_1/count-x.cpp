#include <iostream>

using namespace std;

int main(void) {
	char c[100];
	// count�� ����
	int count = 0;
	cout << "���ڵ��� �Է��϶�(100�� �̸�)." << endl;
	cin.getline(c, 100, '\n');

	int i = 0;
	while (true)
	{

		if (c[i] == '\0') break;
		if (c[i] == 'x') count++;
		i++;
	}
	cout << "x�� ������ " << count << endl;

	system("pause");
	return 0;
}