#define _CRT_SECURE_NO_WARNINGS    // strtok 에러방지
#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>    // strtok 

typedef struct {
    char* code;
    char* name_of_subway;
} element;

// 
int** matrix;

// 
char list_of_csv[18][20] = {"data/1지선", "data/1호선", "data/2지선", "data/2호선", "data/3호선", "data/4호선", "data/5지선", "data/5호선", "data/6호선", "data/7호선", "data/8호선", "data/9호선", "data/경의선", "data/경춘선", "data/공항철도", "data/분당선",
"data/인천1선","data/중앙선" };
// 
char arr[1024];
char* sArr[1024] = { NULL, };
int row = 0;
char* ptr;
// 
int number_of_name;
// FILE 
FILE* file_of_name;

// 인접행렬 생성
void makeMatrix() {
    // 인접행렬 생성 : matrix(552x552)
    matrix = (int**)malloc(sizeof(int*) * number_of_name);
    for (int i = 0; i < number_of_name; i++) {
        matrix[i] = (int*)malloc(sizeof(int) * number_of_name);
    }
}

int isInList(char* name) {
    file_of_name = fopen("data/역이름.csv", "r");

    fgets(arr, 1024, file_of_name);
    ptr = strtok(arr, ",");
    ptr = strtok(NULL, ",");
    number_of_name = atoi(ptr);

    int index = 0;
    char* pStr;
    int isIn = 0;

    while (file_of_name != NULL) {
        // 한줄 씩 받아옮
        pStr = fgets(arr, 1024, file_of_name);

        if (pStr != NULL) {
            // 역 코드
            ptr = strtok(arr, ",");
            // 역 이름
            ptr = strtok(NULL, ",");
            if (strcmp(ptr, name) == 0) {
                isIn = 1;
            }
        }
        else
            break;  // pStr == NULL 일때 break
        index++;

    }
    if (isIn == 0)
    {
        printf("역이름이 유효하지 않습니다!\n");
    }
    return isIn;
}

int isSame(char* start, char* end) {
    int same = 0;
    if (strcmp(start, end) == 0) {
        printf("출발역과 도착역이 동일합니다.\n");
        same = 1;
    }
    return same;

}

int main() {
    // 역이름
    file_of_name = fopen("data/역이름.csv", "r");

    fgets(arr, 1024, file_of_name);
    ptr = strtok(arr, ",");
    ptr = strtok(NULL, ",");
    number_of_name = atoi(ptr);

    // 인접행렬 생성 함수
    makeMatrix();
    
    char start[20];
    char end[20];
    element* list_of_name = (element*)malloc(sizeof(element*) * number_of_name );
    int index = 0;
    char* pStr;
    do
    {
        do
        {
            printf("출발역을 입력해주세요: ");
            scanf("%s", start);
            strcat(start, "\n");
        } while (isInList(start) == 0);


        do
        {
            printf("도착역을 입력해주세요: ");
            scanf("%s", end);
            strcat(end, "\n");
        } while (isInList(end) == 0);
    } while (isSame(start, end));
    
    
    // 
    while (file_of_name != NULL) {
        // 한줄 씩 받아옮
        pStr = fgets(arr, 1024, file_of_name);

        if (pStr != NULL) {
            // 역 코드
            ptr = strtok(arr, ",");
        //    printf("%s", ptr);
            // 역 이름
            ptr = strtok(NULL, ",");
         //   printf("%s", ptr);
            if (strcmp(ptr, "도봉\n") == 0) {
                printf("동일한 역이름이 탐색");
                break;
            }
        }
        else
            break;  // pStr == NULL 일때 break
        index++;

    }
    fclose(file_of_name);
    return 0;
}