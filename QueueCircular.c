#include <stdio.h>
#define SIZE 9

int cqueue[SIZE], rear = -1, front = 0;
int cnt = 0;

int add(int data) {
	if (cnt==SIZE) {
		printf("CQueue is full!!\n");
		return -1;
	}
	cnt++;
	cqueue[++rear%SIZE] = data;
	printf("++rear%SIZE== %d", ++rear%SIZE);
	return 0;
}
int delete(void) {
	if (cnt==0) {
		printf("CQueue is empty!\n");
		return -1;
	}
	cnt--;
	printf("front++%SIZE== %d", front++%SIZE);
	return cqueue[front++%SIZE];
}
int main(void) {
	int max=3000;
	add(5); add(10); add(15);

	printf("%d\n", delete());
	printf("%d\n", delete());
	printf("%d\n", delete());


	add(55); add(60); add(65);
	printf("\n%d\n", delete());

	printf("%d\n", max);
	return 0;
}