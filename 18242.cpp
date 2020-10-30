#include <stdio.h>

int N, M, r = 0, c, len = 0; char arr[101][102];

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
		scanf("%s", arr[i] + 1);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] == '#') {
				r = i;
				c = j;
				break;				
			}
		}
		if (r) break;
	}

	while (1) {
		len += 2;
		if (arr[r + len][c + len] == '#')
			break;
	}

	if (arr[r][c + len / 2] == '.')
		printf("UP");
	else if (arr[r + len / 2][c] == '.')
		printf("LEFT");
	else if (arr[r + len / 2][c + len] == '.')
		printf("RIGHT");
	else if (arr[r + len][c + len / 2] == '.')
		printf("DOWN");

	return 0;
}