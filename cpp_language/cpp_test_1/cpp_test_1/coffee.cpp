#include <iostream>

using namespace std;

bool checkInputError() {
	if (cin.fail()) {
		// ���λ��� �÷��� �ʱ�ȭ
		cin.clear();
		// buffer clear
		cin.ignore(100, '\n');
		cout << "�Է� ����" << endl;
		return true;
	}
	
	return false;
}

int main(void) {
	// ���� �� �Ǹž�
	int totalSale = 0;
	// ���� �ֹ��� �ݾ�
	int order;
	// �ֹ��� Ŀ�� ����
	char coffee[100];
	// �ܼ�
	int num;

	while (true)
	{
		cout << "�ֹ� >>";
		cin >> coffee >> num;

		// input check
		if (checkInputError()) continue;

		// �ܼ��� ����� �Է�
		if (num < 0) {
			cout << "�� ���� ����� �Է��ϼ���" << endl;
			continue;
		}

		if (strcmp(coffee, "����������") == 0) {
			order = 2000 * num;
			continue;
		}


		// totalSale > 20000 �� ��� break
		if (totalSale >= 20000) {
			break;
		}

	}
}