#include <stdio.h>
#include <string.h>
#define max 100
struct stack {
	int data[max];
	int top;
};
void init(struct stack* s) {
	s->top = -1;
}
int is_full(struct stack* s) {
	return s->top == max - 1;
}
int is_empty(struct stack* s) {
	return s->top == -1;
}
void push(struct stack* s, int item) {
	if (is_full(s))printf("error");
	else s->data[++s->top] = item;
}
int pop(struct stack* s) {
	if (is_empty(s))return printf("error");
	else return s->data[s->top--];
}
int main() {
	int cnt = 1;
	struct stack s;
	init(&s);
	char arr[max];
	printf("수식: ");
	scanf("%s", arr);
	int a = strlen(arr);
	printf("괄호 수:");
	for (int i = 0; i < a; i++) {
		if (arr[i] == '(') {
			push(&s, cnt);
			printf("%d ", cnt++);
		}
		else {
			printf("%d ", pop(&s));
		}
	}
	return 0;
}