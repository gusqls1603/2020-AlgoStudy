#include <iostream>
#include <string.h>
using namespace std;

int T, M, N, K, res, field[50][50], visit[50][50], list[2500][2];

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

int isinrange(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < M;
}

void search(int row, int col) {
	visit[row][col] = 1;

	int nxt_r, nxt_c;
	for (int i = 0; i < 4; i++) {
		nxt_r = row + dr[i], nxt_c = col + dc[i];
		if (isinrange(nxt_r, nxt_c) && field[nxt_r][nxt_c] && !visit[nxt_r][nxt_c]) {
			search(nxt_r, nxt_c);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int X, Y;

	cin >> T;
	while (T--) {
		memset(field, 0, sizeof(field));
		memset(visit, 0, sizeof(visit));
		memset(list, 0, sizeof(list));
		res = 0;

		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			cin >> X >> Y;
			field[Y][X] = 1;
			list[i][0] = Y, list[i][1] = X;
		}

		for (int i = 0; i < K; i++) {
			if (!visit[list[i][0]][list[i][1]]) {
				search(list[i][0], list[i][1]);
				res++;
			}
		}

		cout << res << "\n";
	}

	return 0;
}