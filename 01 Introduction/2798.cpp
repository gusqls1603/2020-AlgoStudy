#include <iostream>

int main()
{
	int N, M, i, j, k, sum, ans = 0;

	scanf("%d %d", &N, &M);

	int* arr = new int[N];

	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	for (i = 0; i < N - 2; i++)
		for (j = i + 1; j < N - 1; j++)
			for (k = j + 1; k < N; k++) {
				sum = arr[i] + arr[j] + arr[k];
				if (sum > M)
					continue;

				if (M - ans > M - sum)
					ans = sum;
			}

	printf("%d", ans);

	return 0;
}