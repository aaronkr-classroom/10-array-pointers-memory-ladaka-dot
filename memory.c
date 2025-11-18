#include <stdio.h>

// 전역 변수
int* BP, * SP;//base pointer, stack pointer
int stack[1024];//4byte*1024 stack
int stackindex = 0;

void Show() {
	printf("-------------------------------------\n");
	printf("present stack state(top->bottom)\n");
	for (int i = stackindex - 1; i >= 0; i--) {
		//address and realistc address print
		int* addr = (int*)&stack[i];
		int value = *addr;
		printf("stack[%d]:%p(address),%d[value]\n", i, addr, value);
	}
	printf("Base Pointer(BP):%p\n", (void*)BP);
	printf("Stack Pointer(SP):%p\n", (void*)SP);
	printf("----------------------------\n");
}

void push(int value) {
	stack[stackindex++] = value;//stack[0]=value:0++
	SP = &stack[stackindex];//SP=stack[1]
}

int* pop() {
	if (stackindex > 0) {
		SP = &stack[--stackindex];//1--;stack[0]
		return stack[stackindex];
	}
	return -1;//no value in stack
}

void Test(int a, int b, int c) {
	int x = a + b;
	int y = b + c;
	int z = c + a;

	printf("Test() 함수 진입 - 스택 프레임 생성\n");
	push((int)BP);//store previous BP

	//present stack frame push 

	push((int)&x);
	push((int)&y);
	push((int)&z);

	Show();

	printf("Test() 함수변환 - 스택 프레임 해제\n");
	pop(); //z
	pop();	//y
	pop();//x

	BP = (int*)pop();

	Show();
}

int main(void) {
	int a = 10,
		b = 20,
		c = 30;

	printf("main() function start - stack first state\n");

	push((int)&a);
	push((int)&b);
	push((int)&c);

	BP = (int*) & stack[0];

	Show();

	printf("call Test() function\n");
	Test(a, b, c);
	printf("main() function finished repair - stack state\n");

	pop();
	pop();
	pop();

		Show();



	return 0;
}