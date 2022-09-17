#include <iostream>

using namespace std;

bool checkInputError() {
	if (cin.fail()) {
		// 내부상태 플러그 초기화
		cin.clear();
		// buffer clear
		cin.ignore(100, '\n');
		cout << "입력 오류" << endl;
		return true;
	}
	
	return false;
}

int main(void) {
	// 현재 총 판매액
	int totalSale = 0;
	// 현재 주문한 금액
	int order;
	// 주문한 커피 종류
	char coffee[100];
	// 잔수
	int num;

	while (true)
	{
		cout << "주문 >>";
		cin >> coffee >> num;

		// input check
		if (checkInputError()) continue;

		// 잔수는 양수를 입력
		if (num < 0) {
			cout << "잔 수는 양수를 입력하세요" << endl;
			continue;
		}

		if (strcmp(coffee, "에스프레소") == 0) {
			order = 2000 * num;
			continue;
		}


		// totalSale > 20000 인 경우 break
		if (totalSale >= 20000) {
			break;
		}

	}
}