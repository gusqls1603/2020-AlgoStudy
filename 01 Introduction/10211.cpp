#include <stdio.h>
#define MAX 1000

int arr[MAX];

int main() {

	int i, j, T, N, max;

	scanf("%d", &T);

	for (i = 0; i < T; i++) {
		scanf("%d", &N);
		for (j = 0; j < N; j++) {
			scanf("%d", &arr[j]);
		}
		max = arr[0];
		for (j = 1; j < N; j++) {
			if (arr[j] < arr[j - 1] + arr[j]) {
				arr[j] = arr[j - 1] + arr[j];
			}
			if (max < arr[j]) max = arr[j];
		}
		printf("%d\n", max);
	}

	return 0;
}