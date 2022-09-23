#include <stdio.h>
int main() {		
	int a, b;
	scasnf("%d %d", &a, &b);
	printf("%d", a + b);
	printf("%d", a - b);
	printf("%d", a * b);
	printf("%d", a / b);
	printf("%d", a % b);
	return 0;
}
