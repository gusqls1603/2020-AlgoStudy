#include <stdio.h>
#define MAX 1000000

int arr[MAX];

int main() {

	int i, N, max = -1000000, min = 1000000;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] < min) min = arr[i];
		if (arr[i] > max) max = arr[i];
	}

	printf("%d %d\n", min, max);

	return 0;
}