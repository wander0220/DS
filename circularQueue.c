#include<stdio.h>
#define SIZE 9
int cqueue[SIZE];
int rear = -1;
int front = 0;
int cnt = 0;
int add(int data) {
	if (cnt == SIZE) {
		printf("Queue is full!\n");
		return -1;
	}
	cnt++;
	cqueue[++rear%SIZE] = data;
	printf("%d\n", rear%SIZE);
	return 0;
}
int delete() {
	if (cnt == 0) {
		printf("CQueue is empty!\n");
		return -1;
	}
	cnt--;
	return cqueue[front++%SIZE];
}
int main(void) {
	add(5);
	add(10);
	add(15);
	add(20);
	add(25);
	add(30);
	add(35);
	add(40);
	add(45);
	add(50);
	printf("%d\n", delete());
	printf("%d\n", delete());
	printf("%d\n", delete());
	printf("%d\n", delete());
	printf("%d\n", delete());
	printf("%d\n", delete());
	printf("%d\n", delete());
	printf("%d\n", delete());
	printf("%d\n", delete());
	printf("%d\n", delete());
	add(55);
	add(60);
	add(65);
	printf("%d\n", delete());
	return 0;
}