#include <stdio.h>
#define SIZE 1000000
//������ 45p
int main(void) {
	/*
	int a[SIZE] = { 10, };
	���� ����� 1mb���� ó�� ������ �� �ȵȴ�
	������ �� �ܼ�â �����ϴ� ������ �Ʒ��Ʒ��Ʒ� ���� ���� ������ ��������
	4mb�� �ٲ��ָ� �ߵȴ�.
	*/

	int *a = (int *)malloc(sizeof(int)*SIZE);
	a[0] = 10;
	a[99999999] = 9;

	printf("%d\n", a[0]);

	return 0;
}