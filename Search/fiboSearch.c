#include <stdio.h>
int fiboSearch(int a[], int n, int key) {
	int fibo[] = { 0,1,1,2,3,5, 8,13,21,34,55 };
	int pos, index = 0, k = 0;

	while (fibo[k]<n)k++;
	while (k > 0) {
		pos = index + fibo[--k];
		if (pos >= n || key < a[pos]);
		else if (key > a[pos]) {
			index = pos;
			k--;
		}
		else return pos;
	}
	return -1;
}
int main() {
	int a[] = { 0,6,7,13,16 };//정렬된 데이터
	int n = sizeof(a) / sizeof(int);
	int index, key,pos;
	printf("찾고자 하는 값 : ");
	scanf_s("%d", &key);
	pos = fiboSearch(a, n, key);

	return 0;
}