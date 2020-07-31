#include <iostream>

int main()
{
	int N, M, i, j, sz, max_sz;

	scanf("%d %d", &N, &M);

	int** arr = new int* [N];
	for (i = 0; i < N; i++)
		arr[i] = new int[M];

	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			scanf("%1d", &arr[i][j]);

	N > M ? max_sz = M : max_sz = N;

	for (sz = max_sz; sz >= 1; sz--)
		for (i = 0; i < N - sz + 1; i++)
			for (j = 0; j < M - sz + 1; j++)
				if (arr[i][j] == arr[i + sz - 1][j])
					if (arr[i + sz - 1][j] == arr[i + sz - 1][j + sz - 1])
						if (arr[i + sz - 1][j + sz - 1] == arr[i][j + sz - 1]) {
							printf("%d", sz * sz);
							return 0;
						}

	return 0;
}