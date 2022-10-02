#ifndef Container1
#define Container1

// 통하나를 사용하는 class
class Container {
	// 현재 저장량 / 최대 저장 가능 : 10
	int size;
public:
	// 생성자
	Container() {
		size = 10;
	}
	// n 만큼 채우기
	void fill(int n);
	// n 만큼 소모
	bool consume(int n);
	// 현재 크기 return
	int getSize();
};

#endif