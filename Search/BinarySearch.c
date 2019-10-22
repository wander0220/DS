#include <stdio.h>
int BinarySearch(int a[], int key, int n) {
	int mid, left = 0, right=n-1;

	while (left <= right) {
		mid = (left + right) / 2;
		if (key == a[mid])return mid;
		else if (key > a[mid]) left = mid + 1;
		else right = mid - 1;
	}

	return -1; 
}
int main() {
	int a[] = { 2,6,7,13,16,20,21,35,55,61,88,93 };
	int n = sizeof(a) / sizeof(int);
	int key, index;

	printf("찾을 값 : ");
	scanf_s("%d", &key);
	index = BinarySearch(a, key, n);

	if (index < 0)printf("\n찾는 값이 없다\n");
	else printf("\n %d을 %d에서 찾았다.\n", key, index);

	return 0;
}