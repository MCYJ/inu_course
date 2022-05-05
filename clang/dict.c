#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define MAX_name_SIZE 100
#define MAX_phone_SIZE 200

// 데이터 형식
// 구조체에 이름과 전화번호를 문자열로 저장
typedef struct {
	char name[MAX_name_SIZE];
	char phone[MAX_phone_SIZE];
} element;

// 노드의 구조
typedef struct TreeNode {
	element key;
	struct TreeNode* left, *right;
} TreeNode;

// 만약 e1 < e2 이면 -1 반환
// 만약 e1 == e2 이면 0 반환
// 만약 e1 > e2 이면 1 반환
int compare(element e1, element e2) {
	return strcmp(e1.name, e2.name);
}

// 이진 탐색 트리 목록 출력함수
void display(TreeNode *p) {
	if (p != NULL)
	{
		printf("(");
		display(p->left);
		printf("%s:%s", p->key.name, p->key.phone);
		display(p->right);
		printf(")");
	}
}

// 이진 탐색 트리 탐색 함수
TreeNode* search(TreeNode* root, element key) {
	TreeNode* p = root;

	while (p != NULL)
	{
		if (compare(key, p->key) == 0)

			return p;
		else if (compare(key, p->key) < 0)
			p = p->left;
		else if (compare(key, p->key) > 0)
			p = p->right;
	}
	return p; // 탐색에 실패했을 경우 NULL 반환
}
TreeNode* new_node(element item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}
TreeNode* insert_node(TreeNode* node, element key) {
	// 트리가 공백이면 새로운 노드를 반환한다.
	if (node == NULL) return new_node(key);

	// 그렇지 않으면 순환적으로 트리를 내려간다.
	if (compare(key, node->key) < 0)
		node->left = insert_node(node->left, key);
	else if (compare(key, node->key) > 0)
		node->right = insert_node(node->right, key);
	// key.name값과 node의 key.name값이 동일한 경우
	else {
		node->key = key;
	}
	
	// 루트 포인터를 반환한다.
	return node;
}

TreeNode* max_value_node(TreeNode* node) {
	TreeNode* current = node;
	// 맨 오른쪽 단말 노드를 찾으러 내려감
	while (current->right != NULL)
		current = current->right;
	return current;
}
// 이진 탐색 트리와 키가 주어지면 키가 저장도니 노드를 삭제하고 새로운 루트 노드를 반환한다.
TreeNode* delete_node(TreeNode* root, element key) {
	if (root == NULL) return root;
	// 만약 키가 루트보다 작으면 왼쪽 서브 트리에 있는 것임
	if (compare(key, root->key) < 0)
		root->left = delete_node(root->left, key);
	// 만약 키가 루트보다 크면 오른쪽 서브 트리에 있는 것임
	else if (compare(key, root->key) > 0)
		root->right = delete_node(root->right, key);
	// 키가 루트와 같으면 이 노드를 삭제하면 됨
	else {
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		// 세 번째 경우
		// TreeNode* temp = min_value_node(root->right);
		TreeNode* temp = max_value_node(root->left);

		// 중외 순회시 후계 노드를 복사한다.
		root->key = temp->key;
		// 중외 순회시 후계 노드를 삭제한다.
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}

//
void help() {
	printf("\n**** i: 입력, d: 삭제, s: 탐색, p: 출력, q: 종료 ****: ");
}

// 노드 개수 계산
int get_node_count(TreeNode* node) {
	int count = 0;
	if (node != NULL) {
		count = 1 + get_node_count(node->left) + get_node_count(node->right);
	}
	return count;
}

// 출력 함수
void print(TreeNode* root) {
	printf("(1) 전체노드의 개수(전화번호부 개수) : %d\n", get_node_count(root));
	printf("(2) 전체 노드 정보 (중위순회사용) : ");
	display(root);
}

// 이진 탐색 트리를 사용하는 영어 사전 프로그램
int main(void) {
	char command;
	element e;
	TreeNode* root = NULL;
	TreeNode* tmp;

	do {
		help();
		command = getchar();
		getchar();
		switch (command)
		{
		case 'i':
			printf("이름: ");
			gets(e.name);
			printf("전화번호: ");
			gets(e.phone);
			root = insert_node(root, e);
			break;
		case 'd':
			printf("이름: ");
			gets(e.name);
			root = delete_node(root, e);
			break;
		case 'p':
			print(root);
			printf("\n");
			
			break;
		case 's':
			printf("검색 이름: ");
			gets(e.name);
			tmp = search(root, e);
			if (tmp != NULL)
				printf("'%s'의 전화번호: %s\n", e.name,tmp->key.phone);
			break;

		}
	} while (command != 'q');
	return 0;
}





















