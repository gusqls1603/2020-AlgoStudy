#include <iostream>

void fill_blank(int);

int horz(int, int, int);
int vert(int, int, int);
int square(int, int, int);

int board[9][9];
int blank[81][2], blank_num = 0;
int exit_flag = 0;

int main()
{
	int i, j, k = 0;

	for (i = 0; i < 9; i++)
		for (j = 0; j < 9; j++) {
			scanf("%d", &board[i][j]);

			if (board[i][j] == 0) {
				blank[k][0] = i;
				blank[k][1] = j;
				k++;
			}
		}
	blank_num = k;

	fill_blank(0);

	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++)
			printf("%d ", board[i][j]);
		printf("\n");
	}

	return 0;
}

void fill_blank(int blank_idx)
{
	int row = blank[blank_idx][0], col = blank[blank_idx][1], cand;

	for (cand = 1; cand <= 9; cand++) {
		if (horz(row, col, cand) && vert(row, col, cand) && square(row, col, cand)) {
			board[row][col] = cand;

			if (blank_idx == blank_num - 1) {
				exit_flag = 1;
				return;
			}

			fill_blank(blank_idx + 1);
			if (exit_flag == 1)
				return;

			board[row][col] = 0;
		}
	}

	return;
}

int horz(int row, int col, int cand)
{
	for (int i = 0; i < 9; i++)
		if (board[row][i] == cand)
			return 0;

	return 1;
}

int vert(int row, int col, int cand)
{
	for (int i = 0; i < 9; i++)
		if (board[i][col] == cand)
			return 0;

	return 1;
}

int square(int row, int col, int cand)
{
	int x = (row / 3) * 3;
	int y = (col / 3) * 3;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (board[x + i][y + j] == cand)
				return 0;

	return 1;
}