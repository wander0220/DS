#include <stdio.h>
#include <stdlib.h>
int main(void) {
	struct node {
		char data;
		struct node *link;
	};
	struct node *p;
	struct node *del;

	p = (struct node *)malloc(sizeof(struct node));
	p->data = 'A';
	p ->link = (struct node *)malloc(sizeof(struct node));
	p->link->data = 'B';
	p->link->link = (struct node *)malloc(sizeof(struct node));
	p->link->link->data = 'C';
	p->link->link->link = NULL;

	del = p;
	while (p != NULL) {
		p = p->link;
		//포인터에 다음 주소값을 넣어주는 것
		free(del);
		del = p;
	}

	return 0;

}