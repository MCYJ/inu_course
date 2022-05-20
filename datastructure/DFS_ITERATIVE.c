#include <stdio.h>

#define MAX_STACK_SIZE 100
#define MAX_VERTICES 50

typedef int element;

int visited[MAX_VERTICES];


typedef struct GraphNode
{
	int vertex;
	struct GraphNode* link;
} GraphNode;
typedef struct GraphType
{
	int n; // 정점의 개수
	GraphNode* adj_list[MAX_VERTICES];
} GraphType;



typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// stack type 변수 선언
StackType* s;

// 그래프 초기화
void init(GraphType* g)
{
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
}
// 정점 삽입 연산
void insert_vertex(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES)
	{
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g->n++;
}
void print_adj_list(GraphType* g)
{
	for (int i = 0; i < g->n; i++)
	{
		GraphNode* p = g->adj_list[i];
		printf("정점 %d의 인접 리스트 ", i);
		while (p != NULL)
		{
			printf("-> %d ", p->vertex);
			p = p->link;
		}
		printf("\n");
	}
}
// 간선 삽입 연산, v를 u의 인접 리스트에 삽입한다.
void insert_edge(GraphType* g, int u, int v)
{
	GraphNode* node;
	if (u >= g->n || v >= g->n)
	{
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}

// 스택 초기화 함수
void init_stack(StackType* s)
{
	s->top = -1;
}
// 공백 상태 검출 함수
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// 삭제함수
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

void dfs_iterate(GraphType* g, int v) {
	// stack s 초기화
	init_stack(&s);

	GraphNode* w;

	push(&s, v);

	while (!is_empty(&s)) {
		v = pop(&s);
		if (visited[v] != 1) {
			visited[v] = 1;
			printf("정점 %d -> ", v);
			for (w = g->adj_list[v]; w; w = w->link) {
				if (!visited[w->vertex])
					push(&s, w->vertex);
			}
			
		}
	}


}

int main(void) {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);
	for (int i = 0; i < 4; i++)
		insert_vertex(g, i);
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);
	printf("깊이 우선 탐색\n");

	dfs_iterate(g, 0);

	printf("\n");
	free(g);
	return 0;

}