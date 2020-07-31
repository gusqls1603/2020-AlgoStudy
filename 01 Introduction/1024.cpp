#include <stdio.h>
#include <math.h>

int main()
{
	int N, L, i, j, k, max_i, center;
	long long batch_first;

	scanf("%d %d", &N, &L);

	max_i = (int)((sqrt(1.0 + 8.0 * N) - 1) / 2);

	for (i = L; i <= 100; i++) {

		center = N / i;

		j = center - (i + 1) / 2 + 1;

		if (j < 0)
			continue;

		batch_first = ((1LL * j + (j + i - 1)) * i / 2);

		if (batch_first == N) {
			for (k = j; k <= j + i - 1; k++) {
				printf("%d ", k);
			}
			return 0;
		}

	}

	printf("-1");
	return 0;
}