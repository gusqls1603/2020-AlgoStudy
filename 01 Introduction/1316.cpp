#include <stdio.h>
#include <string.h>

int main()
{
	int N, i, j, len, count = 0;
	int alphabet[26] = { 0 };
	char word[100][101] = { 0 }, prev, cur;

	scanf("%d\n", &N);
	for (i = 0; i < N; i++)
		scanf("%s", word[i]);


	for (i = 0; i < N; i++) {
		memset(alphabet, 0, sizeof(alphabet));

		len = strlen(word[i]);
		word[i][len] = '\n';

		for (j = 0; j <= len; j++) {
			if (j == 0) {
				alphabet[word[i][j] - 'a'] = 1;
				continue;
			}

			cur = word[i][j];
			prev = word[i][j - 1];
			if (cur == '\n') {
				count++;
				break;
			}
			if (cur == prev) {
				continue;
			}
			else { // if cur != prev
				if (alphabet[cur - 'a'] == 1) {
					break;
				}
				else {
					alphabet[cur - 'a'] = 1;
					continue;
				}
			}
		}

	}


	printf("%d", count);

	return 0;
}