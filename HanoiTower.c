#include <stdio.h>
int cnt = 0;
void HanoiTower(int n, char a, char b, char c) {
	//a=����� b=������ c=������
	cnt++;
	if (n==1) printf("%d�� ����, %c -> %c\n", n, a, b);
	else {
		HanoiTower(n - 1, a, c, b);
		printf("%d�� ����, %c -> %c\n", n, a, c);
		HanoiTower(n - 1, b,a,c);
	}
}
int main(void) {
	int n = 5;

	HanoiTower(n, 'A', 'B', 'C');
	printf("\n %dȸ �̵�\n", cnt);
	//2��10��-1
	return 0;
}