#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

char arr[10][9];
int N;
int cnt[26];

bool desc(int a, int b)
{
	return a > b;
}

int main()
{
	int i, j, len, len_cnt = 0, res = 0;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%s", arr[i]);
	}

	for (i = 0; i < N; i++) {
		len = strlen(arr[i]);

		for (j = 0; j < len; j++) {
			if (cnt[arr[i][j] - 'A'] == 0) len_cnt++;

			cnt[arr[i][j] - 'A'] += pow(10, len - j - 1);
		}
	}

	sort(cnt, cnt + 26, desc);

	j = 9;
	for (i = 0; i < len_cnt; i++) {
		res += j * cnt[i];

		j--;
	}

	printf("%d", res);

	return 0;
}