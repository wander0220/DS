#include <stdio.h>
#define SIZE 1000000
//교과서 45p
int main(void) {
	/*
	int a[SIZE] = { 10, };
	스택 사이즈가 1mb여서 처음 실행할 땐 안된다
	하지만 그 콘솔창 설정하는 곳에서 아래아래아래 가면 스택 사이즈 설정에서
	4mb로 바꿔주면 잘된다.
	*/

	int *a = (int *)malloc(sizeof(int)*SIZE);
	a[0] = 10;
	a[99999999] = 9;

	printf("%d\n", a[0]);

	return 0;
}