#include <iostream>

void Queen(int);
int Check(int, int);
void Update(int, int, bool);

int board[14][14];

// 0 for no queens, 1 for queen on the way
int Queen_on_row[14];
int Queen_on_diag1[27];
int Queen_on_diag2[27];

int N, res = 0;

int main()
{
	scanf("%d", &N);

	Queen(0);

	printf("%d", res);

	return 0;
}

void Queen(int Queen_idx)
{
	int row;

	for (row = 0; row < N; row++) {

		if (Check(Queen_idx, row) == 0) // check if available location
			continue;

		if (Queen_idx == N - 1) { // promising case
			res++;
			continue;
		}

		Update(Queen_idx, row, true); // update map (locate queen)

		Queen(Queen_idx + 1); // locate next queen

		Update(Queen_idx, row, false); // update map (delete queen)
	}

	return;
}

int Check(int Queen_idx, int row)
{
	int col = Queen_idx;

	if (!Queen_on_row[row] && !Queen_on_diag1[N - row + col - 1] && !Queen_on_diag2[2 * N - 1 - row - col - 1])
		return 1;
	else
		return 0;
}

void Update(int Queen_idx, int row, bool flag)
{
	int col = Queen_idx;

	if (flag) {
		Queen_on_row[row] = 1;
		Queen_on_diag1[N - row + col - 1] = 1;
		Queen_on_diag2[2 * N - 1 - row - col - 1] = 1;
	}
	else {
		Queen_on_row[row] = 0;
		Queen_on_diag1[N - row + col - 1] = 0;
		Queen_on_diag2[2 * N - 1 - row - col - 1] = 0;
	}

	return;
}