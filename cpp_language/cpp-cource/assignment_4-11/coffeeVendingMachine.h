#include "container.h"
#ifndef coffeeVendingMachine
#define coffeeVendingMachine


// 커피자판기를 표현하는 class
class CoffeeVendingMachine {
	// tong[0] : 커피
	// tong[1] : 물
	// tong[2] : 설탕통
	Container tong[3];
	// 3개의 통을 모두 10으로 채움
	void fill();
	// 에스프레소 : 커피1 물1
	void selectEspresso();
	// 아메리카노 : 커피1 물2
	void selectAmericano();
	// 설탕커피 : 커피1 물2 설탕1
	void selectSugarCoffee();
	// 현재 커피 물 설탕의 잔량 출력
	void show();
	// 오류처리를 위해 추가한 멤버 함수
	bool checkInputError();
public:
	// 커피 자판기 작동
	void run();
};

#endif // !coffeeVendingMachine