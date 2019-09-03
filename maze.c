#include <stdio.h>
#define M 20
#define N 30
#define MAX M*N

enum boolean { false, true };

int top = -1;
int stack[MAX][3] = { 0, };

enum boolean push(int r, int c, int d) {
	if (top == M * N - 1) {
		//top==M*N-1; top >= MAX - 1
		printf("stack overflow\n");
		return false;
	}
	top = top + 1;
	stack[top][0] = r;
	stack[top][1] = c;
	stack[top][2] = d;
	return true;
}

enum boolean pop(int *r, int *c, int *d) {
	if (top == -1) {
		printf("stack underflow\n");
		return false;
	}
	*r = stack[top][0];
	*c = stack[top][1];
	*d = stack[top][2];
	top = top - 1;
	return true;
}

enum boolean mazeSearch(int maze[M][N]) {
	int current_r, current_c, out_r, out_c;
	int view_r, view_c;
	int d = 0; // d�� �̵��� �� �ִ� 0~8 ���� �� �ϳ��� 0���� ���
			   //0������ ��, 1������ ����, 2������ ��, 3������ ����, 4������ ��, 5������ �»�, 6������ ��, 7������ ���
	int move[8][2] = { { 0,1 },{ 1,1 },{ 1,0 },{ 1,-1 },{ 0,-1 },{ -1,-1 },{ -1,0 },{ -1,1 } };

	printf("��� ��: "); scanf_s("%d", &current_r);
	printf("��� ��: "); scanf_s("%d", &current_c);
	printf("���� ��: "); scanf_s("%d", &out_r);
	printf("���� ��: "); scanf_s("%d", &out_c);

	while (1) {
		while (d < 8) {
			view_r = current_r + move[d][0];
			view_c = current_c + move[d][1];
			if (view_r >= 0 && view_r < M && view_c >= 0 && view_c < N && maze[view_r][view_c] == 1) {
				maze[current_r][current_c] = 9; // �̷� ǥ��
				if (!push(current_r, current_c, d + 1)) return false; //�̷� ���� ��
				current_r = view_r;
				current_c = view_c;
				if (current_r == out_r && current_c == out_c) {
					maze[current_r][current_c] = 9;
					//maze[view_r][view_c]
					return true; 
				}
				d = 0;
			}
			else d++;
		}
		maze[current_r][current_c] = 2; // ���ƿ� ��� ǥ��
		if (!pop(&current_r, &current_c, &d)) return false;//�ǵ��� �� ������ ���Լ�, �̷ΰ� ���� ��
	}
}

int main(void) {
	// 0�� ��, 1�� �� �� �ִ� ���
	int maze[M][N] = { { 1,1,0,0,1,0,0,1,0,0,1,0,0,0,1,0,1,0,0,0,0,1,0,1,1,0,1,0,1,0 },
	{ 0,0,1,0,1,0,0,1,0,0,1,0,1,1,0,0,1,0,0,0,0,1,0,0,0,1,0,1,0,1 },
	{ 0,1,0,0,0,1,1,0,1,1,0,0,0,0,1,1,0,1,1,1,1,0,1,1,1,0,0,1,0,0 },
	{ 1,0,0,1,1,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0 },
	{ 0,1,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,1,1,0,1,0,1,0,0,1,0,1 },
	{ 0,0,1,0,0,1,0,1,0,0,0,0,1,0,0,0,1,1,1,0,0,1,0,0,0,1,0,0,0,1 },
	{ 1,0,0,1,0,0,1,0,0,0,1,0,0,0,1,1,1,0,0,0,1,0,1,0,0,1,0,0,1,0 },
	{ 1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,0,0,1,0,1,0,1,0 },
	{ 1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,1,0,1,0,0,1,0,1,0,0,1,0,0,1 },
	{ 0,1,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0,1,0,0,0,0,0,1 },
	{ 1,0,0,1,0,1,0,1,0,1,0,1,0,0,1,1,1,0,0,1,0,0,1,0,0,0,1,0,1,0 },
	{ 1,0,0,1,0,1,0,0,1,0,0,1,0,1,0,0,0,1,1,0,0,1,0,0,0,1,0,1,0,1 },
	{ 0,1,0,1,0,1,0,0,0,0,1,0,1,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,1 },
	{ 1,0,1,0,0,1,0,1,1,0,1,0,0,0,0,1,0,1,0,1,0,0,1,0,0,1,0,1,1,0 },
	{ 1,0,1,0,1,0,0,0,0,1,0,1,0,0,1,0,1,0,1,0,1,0,0,0,0,1,0,0,0,1 },
	{ 1,0,1,0,0,1,0,1,1,0,0,1,0,1,0,0,0,0,0,0,0,1,0,0,1,0,0,1,1,0 },
	{ 1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,1,1,1,0,1,0,0,1,0,0,0,1 },
	{ 0,1,0,1,0,0,0,1,1,1,0,1,0,0,1,1,1,0,0,0,0,0,0,1,0,1,0,0,1,0 },
	{ 0,1,0,1,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0,0,0,1,0,1,0,0,1,0,1 },
	{ 1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0,0,1,0,1,0,1,0,0,1 } };
	int i, j;

	if (mazeSearch(maze) == false) printf("�ⱸ���� �̷� ����!!\n\n");
	//if(!mazeSearch(maze)) printf("�ⱸ����");
	else {
		printf("\n�̷� ã�� �Ϸ�\n");
		for (i = 0; i < M; i++) {
			for (j = 0; j < N; j++) 
				if (maze[i][j] == 9) printf("��"); // �̷��̸�  * ���
				else printf("%d ", maze[i][j] == 0 ? 0 : 1); //�̷� �ƴϸ� �ʱ� ������ ���
				printf("\n");
		}
	}
	printf("\n");

	return 0;
}