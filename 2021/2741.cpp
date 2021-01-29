#include <stdio.h>

int main()
{
	int N, T;

	scanf("%d", &N);

	T = N;

	while (T--) {
		printf("%d\n", N - T);
	}

	return 0;
}