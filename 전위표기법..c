#include <stdio.h>
#include <string.h>
#define max 100
int n = 0;
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
void push(struct stack* s, int n) {
	if (is_full(s)) {
		printf("error");
	}
	s->data[++s->top] = n;
}
int pop(struct stack* s) {
	if (is_empty(s)) {
		return printf("error");
	}
	return s->data[s->top--];
}
int rank(int a) {
	if (a == '+' || a == '-') {
		return 1;
	}
	else if (a == '*' || a == '/') {
		return 2;
	}
	else if (a == ')') {
		return 0;
	}
	else return 0;
}
int peek(struct stack* s) {
	return s->data[s->top];
}
void func(char* p) {
	int save[max];
	struct stack s;
	init(&s);
	int len = strlen(p);
	for (int i = len - 1; i >= 0; i--) {
		switch (p[i]) {
		case '+':
		case '-':
		case '*':
		case '/':
			while (!is_empty(&s)&& rank(p[i]) < rank(peek(&s))) {
					save[n++] = pop(&s);
			}
			push(&s, p[i]);
			break;
		case ')':
			push(&s, p[i]);
			break;
		case '(':
			while (peek(&s) != ')') {
				save[n++] = pop(&s);
			}
			pop(&s);
			break;
		default:
			save[n++] = p[i];
		}
	}
	while(!is_empty(&s)) {
		if (is_empty(&s) != 1) {
			save[n++] = pop(&s);
		}
	}
	for (int i = n-1; i >= 0; i--) {
		printf("%c", save[i]);
	}
}
int main() {
	char arr[max];
	scanf("%s", arr);
	func(arr);
	return 0;
}