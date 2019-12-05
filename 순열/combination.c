//중복조합을 구하는 선생님만의 코드.....
#include <stdio.h>
#define R 3
int b[R] = { 0, };
void com(void) {
	int i;
	for (i = 0; i < R; i++) 
		printf("%d", b[i]);
	printf("\n");
}
void Combination(int a[], int r, int n, int ii) {
	int i;
	if (r == R)com();
	else for (i = ii + 1; i < n; i++) {
		b[r] = a[i];
		Combination(a,r+1,n,i);
	}
}
int main() {
	int a[] = { 1,2,3,4,5 };
	int n = sizeof(a)/sizeof(int);

	Combination(a, 0, n, -1);
	return 0;
}