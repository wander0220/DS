#include <stdio.h>
#include <limits.h>
#define SIZE 8
#define M INT_MAX
int minVertex(int D[], int chk[]) {
	int minValue = M;
	int index, i;
	for (i = 0; i < SIZE; i++) {
		if (chk[i] == 0 && D[i] < minValue) {
			minValue = D[i];
			index = i;
		}
	}
	return index;
}
void Dijkstra(int G[][SIZE], int D[], int P[], int i) {
	int chk[SIZE] = { 0 }, cnt = 0, j;

	for (j = 0; j < SIZE; j++) {
		if (G[i][j] > 0 && G[i][j] < M) {
			D[j] = G[i][j];
			P[j] = i;
		}
	}
	chk[i] = 1; cnt++;
	while (cnt<SIZE){
		i = minVertex(D, chk);
		for(j=0;j<SIZE;j++)
			if (G[i][j] > 0 && G[i][j] < M) {
				if (D[j] > D[i] + G[i][j]) {
					D[j] = D[i] + G[i][j];
					P[j] = i;
				}
			}
		chk[i] = 1; cnt++;
	}
}
int main() {
	int G[][SIZE] = { {0,12,15,18,INT_MAX,INT_MAX,INT_MAX,INT_MAX},
						{12,0,INT_MAX,INT_MAX,33,26,INT_MAX,INT_MAX},
						{15,INT_MAX,0,7,INT_MAX,10,INT_MAX,INT_MAX},
						{18,INT_MAX ,7,0,INT_MAX ,INT_MAX ,11,INT_MAX},
						{INT_MAX,33,INT_MAX,INT_MAX,0,17,INT_MAX,15},
						{INT_MAX,26,10,INT_MAX,17,0,INT_MAX,28},
						{INT_MAX,INT_MAX,INT_MAX,11,INT_MAX,INT_MAX,0,20},
						{INT_MAX,INT_MAX,INT_MAX,INT_MAX,15,28,20,0} };
	char V[] = { 'A','B','C','D','E','F' };
	char aV, bV;
	int i;
	int  D[] = { M,M,M,M,M,M,M,M };
	int P[SIZE] = { 0 };

	printf("출발정점 : ");
	scanf_s("%c", &aV,1);	getchar();
	printf("도착정점 : ");
	scanf_s("%c", &bV,1);	getchar();

	for (i = 0; i < SIZE; i++)
		if (bV == V[i])break;

	D[i] = 0; P[i] = i;
	Dijkstra(G, D, P, i);

	for (i = 0; i < SIZE; i++)
		if (aV == V[i])break;

	printf("%c에서 %c까지 최단거리 %d \n", aV, bV, D[i]);

	printf("최단 경로 : %c", aV);
	while (V[i]!=bV)
	{
		i = P[i];
		printf(" -> %c", V[i]);
	}
	printf("\n");

	return 0;
}