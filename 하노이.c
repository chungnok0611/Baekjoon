#include <stdio.h>
void hanoi(int n, char start, char mid, char end) {
	if (n == 0) return ;//종료하기
	hanoi(n - 1, start, end, mid);
	printf("%d : %c -> %c\n", n, start, end);
	hanoi(n - 1, mid, start, end);
}
int main() {
	int n;
	scanf("%d", &n);
	hanoi(n, 'A', 'B', 'C');//함수호출시 매개변수는 n, 'A', 'B', 'C'을 활용한다.
	
}