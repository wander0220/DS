#include <stdio.h>
//�ؼ��������
int main() {
	struct Student {
		char hakbun[5];
		char name[11];
		int age;
	};
	struct Student a[10];

	int i;
	for (i = 0; i < 3;i++) {
		printf("�й� : ");
		scanf_s("%s",a[i].hakbun,5);
		printf("�̸� : ");
		getchar();
		//scanf_s("%s", a[i].name,11);
		//scanf�� %s�� �����ϸ� �״�� ��
		gets_s(a[i].name, 11);
		getchar();
		//fgets(_s��� ����)�� �� �� �ִ�. ��� 
		fgets(a[i].name,11,stdin); //(���Ĵٵ� ��ǲ)
		//���Ͱ� ������ �� ���� �Է��� �ްڴ�. 
		//����: ��ĵ��������� ������ �����̽��� ���� �����ٿ����� ���� ����

		printf("���� : ");
		scanf_s("%d", &a[i].age);
	}

	for (i = 0; i < 3; i++) {
		printf("�й� : %s, �̸� : %s, ���� : %d\n", a[i].hakbun, a[i].name, a[i].age);
	}

	return 0;
}