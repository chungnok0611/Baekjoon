#include <stdio.h>
void sab(int arr[], int n) {
	int key, j;
	for (int i = 1; i < n; i++) {
		key = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > key; j--) {
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
	}
	for (int k = 0; k < n; k++) {
		printf("%d ", arr[k]);
	}
}
int main() {
	int arr[5] = { 75,34,65,43,64 };
	sab(arr, 5);
	return 0;
}