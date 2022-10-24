#include <stdio.h>
#define max 100000
int arr[max], sum = 0, top = -1;
int is_full() {
	return top == max - 1;
}
int is_empty() {
	return top == -1;
}
void push(int n) {
	if (is_full()) printf("error");
	else arr[++top] = n;
}
int pop() {
	return arr[top--];
}
int main() {
	int a, b, n = 0;
	scanf("%d", &b);
	for (int i = 0; i < b; i++) {
		scanf("%d", &a);
		if (a == 0) {
			pop();
			n--;
		}
		else {
			push(a);
			n++;
		}
	}
	for (int i = 0; i < n; i++) {
		sum += pop();
	}
	printf("%d", sum);
	return 0;
}