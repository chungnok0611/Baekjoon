#include <stdio.h>
int main() {
	int n, arr[1000], tmp, j, least;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf(" %d", &arr[i]);
	}

	for (int i = 0; i < n - 1; i++) {
		least = i;
		for (j = i; j < n; j++) {
			if (arr[j] < arr[least]) {
				least = j;
			}
		}
		tmp = arr[i];
		arr[i] = arr[least];
		arr[least] = tmp;
	}

	for (int a = 0; a < n; a++) {
		printf("%d\n", arr[a]);
	}
	return 0;
}