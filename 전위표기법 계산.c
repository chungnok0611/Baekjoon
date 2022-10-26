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
	if (is_full(s)) {
		printf("error");
	}
	else s->data[++s->top] = item;
}
int pop(struct stack* s) {
	if (is_empty(s)) {
		return printf("error");
	}
	else return s->data[s->top--];
}
void change(char* n) {
	struct stack s;
	init(&s);
	int len = strlen(n), second, first;
	char ch;
	for (int i = len; i >=0; i--) {
		ch = n[i];
		if (ch == '+') {
			first = pop(&s);
			second = pop(&s);
			push(&s, first + second);
		}
		else if (ch == '-') {
			first = pop(&s);
			second = pop(&s);
			push(&s, first - second);
		}
		else if (ch == '*') {
			first = pop(&s);
			second = pop(&s);
			push(&s, first * second);
		}
		else if (ch == '/') {
			first = pop(&s);
			second = pop(&s);
			push(&s, first / second);
		}
		else {
			push(&s, ch - '0');
		}
	}
	printf("%d", pop(&s));
}
int main() {
	char arr[max];
	scanf("%s", arr);
	change(arr);
	return 0;
}