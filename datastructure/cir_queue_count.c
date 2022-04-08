#include <stdio.h>
#include <stdlib.h>

// ===== 원형큐 코드 시작 ======
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct { // 큐 타입
	int front, rear, count, capacity;
	element* data;
} QueueType;
// 오류 함수
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 공백 상태 검출 함수
void init_queue(QueueType* q)
{
	q->count = q->front = q->rear = 0;
	q->data = (element*)malloc(sizeof(element)*MAX_QUEUE_SIZE);
	// capacity에 MAX_QUEUE_SIZE를 할당
	q->capacity = MAX_QUEUE_SIZE;
}
// 공백 상태 검출 함수
int is_empty(QueueType* q)
{
	// q의 count와 0의 비교식을 그대로 return하여 evaluation 되었을 경우 count가 0일때 true, 이외의 경우는 false로 return
	return q->count == 0;
}
// 포화 상태 검출 함수
int is_full(QueueType* q)
{
	// count와 capacity를 비교하는 구문을 그대로 return하여 같을 경우, full 상태로 인식
	return q->count == q->capacity;
}

// resize 함수
// realloc을 활용하여 기존에 할당했던 크기의 2배를 재할당
void resize(QueueType* q) {
	// 기존할당크기의 2배를 data에 재할당
	q->data = (element*)realloc(q->data, sizeof(element) * q->capacity * 2);
	q->capacity *= 2;
}

// 원형큐 출력 함수
void queue_print(QueueType* q)
{
	printf("QUEUE(front=%d rear=%d count=%d) = ", q->front, q->rear, q->count);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			printf("%d | ", q->data[i]);
			i++;
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

// 삽입 함수
void enqueue(QueueType* q, element item)
{

	if (is_full(q)) {
		// queue가 포화상태인 경우, resize 함수 호출
		resize(q);
	}

	q->count++;
	q->data[q->rear] = item;
	q->rear = (q->rear + 1) ;
}

// 삭제 함수
element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->count--;

	int deq = q->data[q->front];
	q->front = q->front + 1;
	
	return deq;
}


int main(void)
{
	QueueType queue;
	int element;
	init_queue(&queue);
	printf("--데이터 추가 단계--\n");

	// for문을 활용하여 queue에 데이터 100개를 삽입
	for(int i=1; i<=100; i++)
	{
		if (is_full(&queue)) {
			resize(&queue);
		}
		enqueue(&queue, i);
		queue_print(&queue);
	}
	
	printf("--데이터 삭제 단계--\n");
	while (!is_empty(&queue))
	{
		element = dequeue(&queue);
		printf("꺼내진 정수: %d \n", element);
		queue_print(&queue);
	}
	printf("큐는 공백상태입니다.\n");
	return 0;
}
