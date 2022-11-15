
#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node* llink;
	struct node* rlink;
};
struct node* head = NULL;
void init() {
	head->llink = head;
	head->rlink = head;
	
}
void insert(int value) {
	struct node* new = (struct node*)malloc(sizeof(struct node));
	new->data = value;
	new->llink = head;
	new->rlink = head->rlink;
	head->rlink->llink = new;
	head->rlink = new;
}
void delete() {
	struct node* removed;
	if (head == NULL) {
		head->llink = head;
		head->rlink = head;
	}
	removed = head->rlink;
	removed->rlink = head;
	head->rlink = removed->rlink;
	free(removed);
}
void print_list() {
	struct node* new = head->rlink;
	for (; new != head; new = new->rlink) {
		printf("%d", new->data);
	}
}
int main() {
	head = (struct node*)malloc(sizeof(struct node));
	init();
	insert(10);
	print_list();
	delete();
	print_list();
	return 0;
}