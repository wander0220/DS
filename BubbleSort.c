#include <stdio.h>

void BubbleSort(int a[], int n) {
	int chk = 1, i = 1, j, temp;

	while (chk == 1) {
		chk = 0;
		for (j = 0; j < n - i; j++) {
			if (a[j] > a[j + 1]) {
				//if를 구하는 횟수만 구해도 시간 복잡도 구해진뎅
				temp = a[j];
				a[j] = a[j +5t 1];
				a[j + 1] = temp;

				chk = 1;
			}
		}
		i++;
	}
}
int main(void) {
	int a[] = { 8,11,5,12,15,7 };
	int n = sizeof(a) / sizeof(int);

	printf("버블 정렬 전 : ");
	for (int i = 0; i < n; i++)
		printf("%5d", a[i]);
	printf("\n");

	BubbleSort(a, n);

	printf("버블 정렬 :  ");
	for (int i = 0; i < n; i++)
		printf("%5d", a[i]);
	printf("\n");

	return 0;
}