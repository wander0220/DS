#include <stdio.h>
#include <malloc.h>
#define SIZE 5

struct  node
{
	char data;
	struct node *next;
};
struct node *G[SIZE];

int main() {
	int i, n;
	char dd;
	struct node *t;

	printf("\n 정점의 개수 입력 : ");
	scanf_s("%d", &n);

	for (i = 0; i < n; i++) {
		getchar();
		printf("\n\n 시작 정점 데이터 : ");
		scanf_s("%c", &dd, 1);
		G[i] = (struct node *)malloc(sizeof(struct node));
		t = G[i]; t->data = dd; t->next = NULL;
		getchar();
		printf("\n 인접 정점 데이터 : ");

		scanf_s("%c", &dd, 1);
		while (dd != '0') {
			t->next = (struct node *)malloc(sizeof(struct node));
			t = t->next; t->data = dd; t->next = NULL;
			getchar();
			printf("\n 다음 인접 데이터(없으면 0 입력) : ");
			scanf_s("%c", &dd, 1);
		}
	}

	for (i = 0; i < n; i++) {
		printf("\n 정점 %d : ", i);
		t = G[i];
		while (t != NULL) {
			if (t != NULL) printf("%c -> ", t->data);
			else printf("%c", t->data);
			t = t->next;
		}
	}

	return 0;
}