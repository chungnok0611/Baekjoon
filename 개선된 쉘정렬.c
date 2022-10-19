#include <stdio.h>
#include <stdlib.h>
#define max 10 
int n = 10;
int arr[max];
void insertion() {
	int i, j, key;
	printf("( )      (");
	for (int k = 0; k < n; k++) {
		if (k != n - 1) {
			printf("%d,", arr[k]);
		}
		else printf("%d", arr[k]);
	}
	printf(")\n");
	for (i = 1; i < n; i++) {
		key = arr[i];

		printf("( ");
		for (int k = 0; k < i; k++) {
			if (k != i - 1) {
				printf("%d,", arr[k]);
			}
			else printf("%d", arr[k]);
		}
		printf(")");
		printf("       (");
		for (int k = i; k < n; k++) {
			if (k != n - 1) {
				printf("%d,", arr[k]);
			}
			else printf("%d", arr[k]);
		}
		printf(")\n");

		for (j = i - 1; j >= 0 && arr[j] > key; j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
	}
}
int main() {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 100;
	}
	insertion();
	return 0;
}
