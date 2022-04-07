#include <stdio.h>
#include <stdlib.h>

// ===== 원형큐 코드 시작 ======
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct { // 큐 타입
	int front, rear, count;
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
}
// 공백 상태 검출 함수
int is_empty(QueueType* q)
{
	// 공백상태는 count를 그대로 return하여, count가 0인경우 false, 그 외의 모든 경우는 true로 판정됨
	// return q->count;
	return (q->front == q->rear);
}
// 포화 상태 검출 함수
int is_full(QueueType* q)
{
	// return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
	return q->count == sizeof(q->data) / sizeof(element);
}

// resize 함수
void resize(QueueType* q) {
	q->data = (element*)realloc(q->data, sizeof(MAX_QUEUE_SIZE) * 2);
}

// 원형큐 출력 함수
void queue_print(QueueType* q)
{
	printf("QUEUE(front=%d rear=%d count=%d) = ", q->front, q->rear, q->count);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			printf("%d | ", q->data[i]);
			i = (i + 1) % (MAX_QUEUE_SIZE);
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
//	while (!is_full(&queue))
	for(int i=0; i=10; i++)
	{
		if (is_full(&queue)) {
			resize(&queue);
		}
		printf("정수를 입력하시오: ");
		scanf("%d", &element);
		enqueue(&queue, element);
		queue_print(&queue);
	}
	printf("큐는 포화상태입니다.\n\n");
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