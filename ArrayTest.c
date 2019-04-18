#include<stdio.h>

int main() {
	int i, j, b[5][4], c[4][5];
	int a[4][5] = { { 5, 41,24, 6,10 },{50,33 ,20 ,15 ,11 }, {7, 17, 35, 21, 16},{ 4,16,61,90,1} };

	for (i = 0; i < 4; i++) {
		int u = 3-i;
		for (j = 0; j < 5; j++) {
			b[j][u] = a[i][j];
		}
		//u--;
	}

	for (i = 0; i < 5; i++) {
		int k = 4-i;
		for (j = 0; j < 4; j++) {
			c[j][k] = b[i][j];
		}
	}
	
	printf("\n배열 a: \n");

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 5; j++)
			printf("%2d ", a[i][j]);
		printf("\n");
	}

	printf("\n배열 b:\n"); 

	for (i = 0; i < 5; i++) {
		for (j = 0; j  < 4; j++)
			printf("%2d ", b[i][j]);
		printf("\n");
	}

	printf("\n배열 c:\n");
	for (i = 0; i < 4;i++) {
		for (j = 0; j < 5; j++)
			printf("%2d ", c[i][j]);
		printf("\n");
	}
	
	printf("\n");

	return 0;

}