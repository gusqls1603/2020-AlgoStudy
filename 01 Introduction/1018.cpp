#include <iostream>

int main()
{
	char W[8][8] = {
	'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
	'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
	'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
	'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
	'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
	'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
	'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
	'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'
	};

	char B[8][8] = {
	'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
	'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
	'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
	'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
	'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
	'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B',
	'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W',
	'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'
	};

	int N, M, i, j, a, b, countW, countB, min = 70;

	scanf("%d %d", &N, &M);

	char** arr = new char* [N];
	for (i = 0; i < N; i++)
		arr[i] = new char[M];

	for (i = 0; i < N; i++)
		scanf("%s", arr[i]);

	for (i = 0; i <= N - 8; i++)
		for (j = 0; j <= M - 8; j++) {
			countW = 0;
			countB = 0;

			for (a = 0; a < 8; a++)
				for (b = 0; b < 8; b++)
					if (arr[i + a][j + b] != W[a][b])
						countW++;

			for (a = 0; a < 8; a++)
				for (b = 0; b < 8; b++)
					if (arr[i + a][j + b] != B[a][b])
						countB++;

			if (countW < min)
				min = countW;

			if (countB < min)
				min = countB;
		}

	printf("%d", min);

	return 0;
}