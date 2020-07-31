#include <iostream>
#include <algorithm>
using namespace std;

void alphabet(int, int);

char board[21][21];
int R, C, cnt = 0, max_cnt = -1;
int found[26];


int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

int isinrange(int r, int c) {
	return 0 <= r && r < R && 0 <= c && c < C;
}

int main()
{
	int i, j;
	scanf("%d %d", &R, &C);

	for (i = 0; i < R; i++) {
		scanf("%s", board[i]);
	}

	found[board[0][0] - 'A'] = 1;
	cnt++;
	alphabet(0, 0);

	printf("%d", max_cnt);

	return 0;
}

void alphabet(int row, int col)
{
	int i, j, next_row, next_col;

	for (i = 0; i < 4; i++) {
		next_row = row + dr[i];
		next_col = col + dc[i];

		if (isinrange(next_row, next_col) && !found[board[next_row][next_col] - 'A']) {

			found[board[next_row][next_col] - 'A'] = 1;
			cnt++;

			alphabet(next_row, next_col);

			found[board[next_row][next_col] - 'A'] = 0;
			cnt--;
		}
	}

	max_cnt = max(cnt, max_cnt);
}