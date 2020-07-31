#include <iostream>

int main()
{
	int N, i, j, max3, max5, min = 3000;

	scanf("%d", &N);

	max3 = N / 3;
	max5 = N / 5;

	for (i = 0; i <= max3; i++) {
		for (j = 0; j <= max5; j++) {
			if (i * 3 + j * 5 == N)
				if (i + j < min)
					min = i + j;
		}
	}

	if (min == 3000)
		printf("-1");
	else
		printf("%d", min);

	return 0;
}