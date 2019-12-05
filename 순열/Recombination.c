#include <stdio.h>
#define R 3
int b[R] = { 0, };
void Recom(void) {
	int i;
	for (i = 0; i < R; i++)
		printf("%d", b[i]);
	printf("\n");
}
void ReCombination(int a[], int r, int n, int ii) {
	int i;
	if (r == R) Recom();
	else for (i = ii; i < n; i++) {
		b[r] = a[i];
		ReCombination(a, r + 1, n, i);
	}
}
int main() {
	int a[] = { 1,2,3,4,5 };
	int n = sizeof(a) / sizeof(int);

	ReCombination(a, 0, n, 0);
	return 0;
}