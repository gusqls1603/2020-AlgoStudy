#include <iostream>

int board[100][100];

int main()
{
	int N, a, b, i, j, size = 0;

	scanf("%d", &N);

	while (N--) {
		scanf("%d %d", &a, &b);

		for (i = a; i < a + 10; i++) {
			for (j = b; j < b + 10; j++) {
				board[i][j] = 1;
			}
		}

	}

	for (i = 0; i < 100; i++)
		for (j = 0; j < 100; j++)
			if (board[i][j] == 1)
				size++;

	printf("%d", size);

	return 0;
}