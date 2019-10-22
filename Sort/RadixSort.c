#include <stdio.h>
#include <stdlib.h>

void RadixSort(int *a,int n) {
	int* bucket = (int*)malloc(sizeof(int) * n);
	int digit_cnt[10] = { 0 }, digit_base = 1, i, max=a[0];

	for (i = 1; i < n; i++) {
		if (max < a[i]) max = a[i];
		while (digit_base<=max)
		{
			for (i = 0; i < n; i++) digit_cnt[a[i]/digit_base%10]++;
			for (i = 1; i < 10; i++) digit_cnt[i] += digit_cnt[i - 1];
			for (i = n - 1; i >= 0; i--) {
				bucket[--digit_cnt[a[i] / digit_base % 10]] = a[i];
			}
			for (i = 0; i < n; i++)a[i] = bucket[i];
			for (i = 0; i < 10; i++)digit_cnt[i] = 0;
			digit_base *= 10;
		}
	}
	free(bucket);
}
int main() {
	int a[] = { 10,623,30,137,25,26,16,13,2002,1994,304,404 };
	int n = sizeof(a) / sizeof(int);
	RadixSort(a, n);

	printf("\n기수 정렬 후 : ");
	for (int i = 0; i < n; i++) {
		printf("	%d", a[i]);
	}
	printf("\n");

	return 0;
}