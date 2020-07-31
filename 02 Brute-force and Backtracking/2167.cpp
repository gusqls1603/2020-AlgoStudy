#include <iostream>

int main()
{
	int i, j, x, y, N, M, K, sum;

	scanf("%d %d", &N, &M);

	int** arr = new int* [N];

	for (int a = 0; a < N; a++) {
		arr[a] = new int[M];
	}

	for (int a = 0; a < N; a++) {
		for (int b = 0; b < M; b++) {
			scanf("%d", &arr[a][b]);
		}
	}

	scanf("%d", &K);

	int a, b, c, d;

	while (K--) {
		sum = 0;

		scanf("%d %d %d %d", &i, &j, &x, &y);

		for (a = i - 1; a < x; a++) {
			for (b = j - 1; b < y; b++) {
				sum += arr[a][b];
			}
		}

		printf("%d\n", sum);
	}

	return 0;
}