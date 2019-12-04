#include <stdio.h>
#define SIZE 8
typedef enum { false, true } bool;
int rear = -1; front = 0;
int queue[SIZE];
void push(int item) {
	if (rear >= SIZE) {
		printf("Queue is Full!\n");
		return;
	}
	queue[++rear] = item;
}
int pop() {
	if (front > rear) return -1;
	return queue[front++];
}
void BreadthFirstSearch(bool G[][SIZE], char V[]) {
	bool chk[SIZE] = { false };
	int i, j;
	char startV;
	printf("출발 정점 :");
	scanf_s("%c", &startV);
	for (i = 0; i < SIZE; i++) if (startV == V[i])break;
	printf("너비 우선 탐색 : %c", startV);
	chk[i] = true;
	do {
		for (j = 0; j < SIZE; j++) {
			if (G[i][j] == 1 && chk[j] == 0) {
				printf("->%c", V[j]);
				chk[j] = 1; //1==ture
				push(i);
				i = j;
				break;
			}
		}
		if (j == SIZE)i = pop();
	} while (i >= 0);

}
int main() {
	bool G[SIZE][SIZE] = {
		{0,1,0,1,0,0,0,0},
		{1,0,0,0,1,0,1,0},
		{0,0,0,0,1,1,0,0},
		{1,0,0,0,0,1,0,0},
		{0,1,1,0,0,0,1,0},
		{0,0,1,1,0,0,0,1},
		{0,1,0,0,1,0,0,1},
		{0,0,0,0,0,1,1,0}
	};
	char V[] = { 'A','B','C','D','E','F','G','H' };
	int i, j;
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			printf("%5d", G[i][j]);
		}
		printf("\n");
	}
	BreadthFirstSearch(G, V);
	printf("\n");
	return 0;
}