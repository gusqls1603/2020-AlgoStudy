#include <iostream>

void lotto(int);

int S[13], k;
int selected[13], count = 0;

int main()
{
	int i;

	while (1)
	{
		scanf("%d", &k);
		if (k == 0) exit(0);

		for (i = 0; i < k; i++)
			scanf("%d", &S[i]);

		lotto(0);

		printf("\n");
	}

	return 0;
}

void lotto(int idx)
{
	int i, j;

	if (count == 6) {
		for (j = 0; j < k; j++) {
			if (selected[j]) {
				printf("%d ", S[j]);
			}
		}
		printf("\n");
		return;
	}

	for (i = idx; i < k; i++) {
		selected[i] = 1; count++;

		lotto(i + 1);

		selected[i] = 0; count--;

	}

}