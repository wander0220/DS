#include <stdio.h>
//※수정요망※
int main() {
	struct Student {
		char hakbun[5];
		char name[11];
		int age;
	};
	struct Student a[10];

	int i;
	for (i = 0; i < 3;i++) {
		printf("학번 : ");
		scanf_s("%s",a[i].hakbun,5);
		printf("이름 : ");
		getchar();
		//scanf_s("%s", a[i].name,11);
		//scanf의 %s는 띄어쓰기하면 그대로 끝
		gets_s(a[i].name, 11);
		getchar();
		//fgets(_s없어도 괜찮)도 쓸 수 있다. 얘는 
		fgets(a[i].name,11,stdin); //(스탠다드 인풋)
		//엔터가 눌러질 때 까지 입력을 받겠다. 
		//정리: 스캔에프언더바 에스는 스페이스바 까지 에프겟에스는 엔터 까지

		printf("나이 : ");
		scanf_s("%d", &a[i].age);
	}

	for (i = 0; i < 3; i++) {
		printf("학번 : %s, 이름 : %s, 나이 : %d\n", a[i].hakbun, a[i].name, a[i].age);
	}

	return 0;
}