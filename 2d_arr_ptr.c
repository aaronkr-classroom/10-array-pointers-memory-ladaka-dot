#include <stdio.h>
#include <conio.h>

#define ROWS 3
#define COLS 5

//2D 배열 출력 함수

void printArr(char arr[ROWS][COLS]{
	//printf("배열의 상태:\n");
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			printf("%d", arr[i][j]);
		}
		printf("\n");//다음 행으로 가기
}
	}
	int main(void) {
	//ROWS*COLS 크기의 2D 배열 
	char data[ROWS][COLS] = { 0 };
	char (*p)[COLS];

	p = data;//포인터 p가 data 배열을 가리키도록 설정

	printf("시작 전:\n");
	printArr(data);

	//포인터를 사용하여 배열의 요소에 값을 할당
	(*p)[1] = 3;
	(*(p + 1))[2] = 4;
	(*(p + 2))[4] = 5;
	printf("Press any key to continue");
	getch();
	printf("시작전:\n");
	printArr(data);

	return 0;
}