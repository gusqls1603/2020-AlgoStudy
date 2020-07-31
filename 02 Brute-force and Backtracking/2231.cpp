#include <iostream>

int table[1000001];

int main()
{
	int i, p, temp;

	for (i = 1; i <= 1000000; i++) {
		p = 0;

		temp = i;
		do {
			p += temp % 10;
			temp /= 10;
		} while (temp > 0);
		p += i;

		if (p <= 1000000 && !table[p]) table[p] = i;
	}

	int N;

	scanf("%d", &N);

	printf("%d", table[N]);

	return 0;
}