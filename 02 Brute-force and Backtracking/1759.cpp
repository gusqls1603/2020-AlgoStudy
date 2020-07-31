#include <iostream>
#include <algorithm>
using namespace std;

void pick(int);
int check(void);

int L, C;
char arr[15];
int selected[15], cnt = 0;

int main()
{
	int i = 0;
	scanf("%d %d\n", &L, &C);

	while (i != C)
	{
		scanf("%c", &arr[i]);

		if (arr[i] == ' ') continue;
		else i++;
	}

	sort(arr, arr + C);

	pick(0);

	return 0;
}

void pick(int idx)
{
	int i, j;

	if (cnt == L) {
		if (check() == 1) {
			for (j = 0; j < C; j++) {
				if (selected[j]) {
					printf("%c", arr[j]);
				}
			}
			printf("\n");
		}
		return;
	}

	for (i = idx; i < C; i++) {

		selected[i] = 1; cnt++;

		pick(i + 1);

		selected[i] = 0; cnt--;

	}

	return;
}

int check()
{
	int i, n_consonant = 0, n_vowel = 0;

	for (i = 0; i < C; i++) {
		if (selected[i]) {
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') {
				n_vowel++;
			}
			else
				n_consonant++;
		}
	}

	if (n_consonant < 2 || n_vowel < 1) return 0;
	else return 1;
}