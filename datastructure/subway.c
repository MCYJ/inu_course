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
// 
void makeMatrix() {
    // 역이름
    file_of_name = fopen("data/역이름.csv", "r");

    fgets(arr, 1024, file_of_name);
    ptr = strtok(arr, ",");
    ptr = strtok(NULL, ",");
    number_of_name = atoi(ptr);

    // 인접행렬 생성 : matrix(552x552)
    matrix = (int**)malloc(sizeof(int*) * number_of_name);
    for (int i = 0; i < _msize(matrix) / sizeof(int*); i++) {
        matrix[i] = (int*)malloc(sizeof(int) * number_of_name);
    }
}


int main() {
    
    // 
    makeMatrix();
    

    element* list_of_name = (element*)malloc(sizeof(element*) * number_of_name );
    int index = 0;
    char* pStr;

    // 
    while (file_of_name != NULL) {
        // 한줄 씩 받아옮
        pStr = fgets(arr, 1024, file_of_name);

        if (pStr != NULL) {
            // 역 코드
            ptr = strtok(arr, ",");
            list_of_name[index].code = ptr;
            // 역 이름
            ptr = strtok(NULL, ",");
         //   list_of_name[index].name_of_subway = (char*)malloc(sizeof(char) * 20);
            list_of_name[index].name_of_subway = ptr;
        }
        else
            break;  // pStr == NULL 일때 break
        index++;

    }
    
    for (int i = 0; i < number_of_name; i++) {
        printf("%s ", list_of_name[i].code);
        printf("%s\n", list_of_name[i].name_of_subway);
    }
    

    /*
    while (pFile != NULL) {
        char* pStr = fgets(arr, 1024, pFile);
        char* ptr = strtok(arr, ",");
        int i = 0;

        if (pStr != NULL)
            printf("%s", arr);
        else
            break;  // pStr == NULL @L8i break

        while (ptr != NULL) {
            sArr[i] = ptr;
            i++;
            ptr = strtok(NULL, ",");
        }

        for (int i = 0; i < 100; i++) {
            if (sArr[i] != NULL)
                printf(" %s ", sArr[i]);
        }
    }
    */

    fclose(file_of_name);
    return 0;
}