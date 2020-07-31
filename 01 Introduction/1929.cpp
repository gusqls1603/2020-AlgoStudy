#include <iostream>

int num[1000001];

int main()
{
	int M, N, i, j;

	scanf("%d %d", &M, &N);

	for (i = 2; i <= N / 2; i++) {
		for (j = 2; j <= N / i; j++) {
			if (i * j > 1000000)
				break;

			if (num[i * j] == 0) {
				num[i * j] = 1;
			}
		}
	}
	num[1] = 1;

	for (i = M; i <= N; i++) {
		if (num[i] == 0) {
			printf("%d\n", i);
		}
	}

	return 0;
}