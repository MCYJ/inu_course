#include "coffeeVendingMachine.h"
#include <iostream>
#pragma warning(disable: 4819)

using namespace std;

void CoffeeVendingMachine::fill() {
	for (int i = 0; i < 3; i++)
	{
		tong[i].fill(10);
	}
	show();
}

void CoffeeVendingMachine::selectEspresso() {
	// 잔량확인
	if (tong[0].getSize() < 1 || tong[1].getSize() < 1) {
		checkInputError();
		return;
	}
	// tong 잔량 차감
	tong[0].consume(1);
	tong[1].consume(1);

	cout <<"에스프레소 드세요" << endl;

}

void CoffeeVendingMachine::selectAmericano() {
	// 잔량확인
	if (tong[0].getSize() < 1 || tong[1].getSize() < 2) {
		checkInputError();
		return;
	}
	// tong 잔량 차감
	tong[0].consume(1);
	tong[1].consume(2);

	cout << "아메리카노 드세요" << endl;
}

void CoffeeVendingMachine::selectSugarCoffee() {
	// 잔량확인
	if (tong[0].getSize() < 1 || tong[1].getSize() < 2 || tong[2].getSize() < 1) {
		checkInputError();
		return;
	}
	// tong 잔량 차감
	tong[0].consume(1);
	tong[1].consume(2);
	tong[2].consume(1);

	cout << "설탕커피 드세요" << endl;
}

void CoffeeVendingMachine::show() {
	cout << "커피 " << tong[0].getSize() << ", 물 " << tong[1].getSize() << ", 설탕 " << tong[2].getSize() << endl;
}

bool CoffeeVendingMachine::checkInputError() {
	cout << "재료가 부족합니다." << endl;
	return false;
}

void CoffeeVendingMachine::run() {
	for (int i = 0; i < 3; i++)
	{
		tong[i].fill(10);
	}
	int menuNum = 0;
	cout << "***** 커피자판기를 작동합니다. *****" << endl;
	while (true) {
		cout << "메뉴를 눌러주세요(1:에스프레소, 2:아메리카노, 3:설탕커피, 4:잔량보기, 5:채우기)>>";
		cin >> menuNum;

		switch (menuNum)
		{
		case 1:
			selectEspresso();
			break;
		case 2:
			selectAmericano();
			break;
		case 3:
			selectSugarCoffee();
			break;
		case 4:
			show();
			break;
		case 5:
			fill();
			break;
		}

	}
}