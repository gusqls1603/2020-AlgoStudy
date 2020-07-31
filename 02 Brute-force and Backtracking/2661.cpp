#include <iostream>

void goodarray(int);

int arr[81];
int N;

int main()
{
	scanf("%d", &N);

	goodarray(1);

	return 0;
}

void goodarray(int len)
{
	int cand, flag = 0, i, j, k;

	if (len == N + 1) {
		for (i = 1; i <= N; i++) {
			printf("%d", arr[i]);
		}
		printf("\n");
		exit(0);
	}

	for (cand = 1; cand <= 3; cand++) {
		arr[len] = cand;

		flag = 0;
		for (j = 1; j <= len / 2; j++) {

			for (k = 0; k < j; k++) {
				if (arr[len - k] != arr[len - j - k]) {
					break;
				}
			}
			if (k == j) {
				flag = 1;
				break;
			}

		}
		if (flag) {
			continue;
		}

		goodarray(len + 1);

	}

}