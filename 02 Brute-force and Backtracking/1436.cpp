#include <iostream>

int table[10001];

int main()
{
	int i = 1, num = 666, temp;

	while (1) {
		temp = num;

		while (temp % 1000 != 666) {
			temp /= 10;

			if (temp < 666) break;
		}

		if (temp % 1000 == 666) {
			table[i] = num;

			i++;

			if (i == 10001) break;
		}

		num++;
	}

	int N;

	scanf("%d", &N);

	printf("%d", table[N]);

	return 0;
}