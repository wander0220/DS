#include <stdio.h>
int InterSearch(int a[], int key, int left, int right) {
	int index;
	while (left <= right) {
		if (a[left] == a[right]) index = left;
		else {
			index = left + (right - left) * (key - a[left]) / (a[right] - a[left]);
			if (index < left)index = left;
			if (index > right)index = right; //����ó��
		}
		if (key == a[index]) return index;
		else if (key > a[index])left = index + 1;
		else right = index - 1;
	}
	return -1;
}
int main(void) {
	int a[] = {0,1,2,3,4,5,6,7,8,9,10};
	int n = sizeof(a)/sizeof(int);
	int index, key;
	printf("ã�� �� : ");
	scanf_s("%d", &key);
	index = InterSearch(a, key, 0, n - 1);
	if (index == -1) printf("����~!\n");
	else printf("%d�� %d���� ã��!\n", key, index);

	return 0;
}