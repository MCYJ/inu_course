#include <iostream>

using namespace std;

int main(void) {
	char c[100];
	// count의 갯수
	int count = 0;
	cout << "문자들을 입력하라(100개 미만)." << endl;
	cin.getline(c, 100, '\n');

	int i = 0;
	while (true)
	{

		if (c[i] == '\0') break;
		if (c[i] == 'x') count++;
		i++;
	}
	cout << "x의 개수는 " << count << endl;

	system("pause");
	return 0;
}