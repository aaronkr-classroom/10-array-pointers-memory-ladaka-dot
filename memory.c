#include <stdio.h>

int *BP, *SP;
int stack[1024];
int stackindex = 0;

void show() {
    printf("---------------------------------------------------------------\n");
    printf("현재 스택 상태\n");
    for (int i = stackindex - 1; i >= 0; i--) {
        int *addr = (int*)stack[i];
        int value = *addr;
        printf("스택[%d]: %p(주소), %d(값)\n", i, (void*)addr, value);
    }
    printf("Base Pointer (BP): %p\n", (void*)BP);
    printf("Stack Pointer (SP): %p\n", (void*)SP);
    printf("---------------------------------------------------------------\n");
}

void push(int value) {
    stack[stackindex++] = value;
    SP = &stack[stackindex];
}

int pop() {
    if (stackindex > 0) {
        SP = &stack[--stackindex];
        return stack[stackindex];
    }
    return -1;
}

void Test(int a, int b, int c) {
    int x = a + b;
    int y = b + c;
    int z = c + a;

    printf("Test() 함수 진입 - 스택 프레임 생성\n");

    push((int)BP);
    push((int)&x);
    push((int)&y);
    push((int)&z);

    show();

    printf("Test() 함수 반환 - 스택 프레임 해제\n");

    pop();
    pop();
    pop();

    BP = (int*)pop();

    show();
}

int main() {
    int a = 10;
    int b = 20;
    int c = 30;

    printf("Main() 함수 시작 초기 스택 상태\n");

    push((int)&a);
    push((int)&b);
    push((int)&c);

    BP = &stack[0];

    show();

    printf("Test() 함수 호출\n");
    Test(a, b, c);

    printf("Main() 함수 종료 - 스택 상태 복구\n");

    pop();
    pop();
    pop();

    show();

    return 0;
}
