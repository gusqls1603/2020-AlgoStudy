#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int N, M, map[10][10], E = 0;
queue <pair <int, int>> oq;

int count(queue<pair<int, int>> q, int a, int b, int c)
{
	int cmap[10][10], cE = E - 3, x, y;
	memcpy(cmap, map, sizeof(map));

	cmap[a / M + 1][a % M + 1] = 1;
	cmap[b / M + 1][b % M + 1] = 1;
	cmap[c / M + 1][c % M + 1] = 1;

	while (q.size() && cE) {
		x = q.front().first;
		y = q.front().second;

		if (cmap[x - 1][y] == 0) {
			cmap[x - 1][y] = 2; cE--;
			q.push(make_pair(x - 1, y));
		}
		if (cmap[x][y + 1] == 0) {
			cmap[x][y + 1] = 2; cE--;
			q.push(make_pair(x, y + 1));
		}
		if (cmap[x + 1][y] == 0) {
			cmap[x + 1][y] = 2; cE--;
			q.push(make_pair(x + 1, y));
		}
		if (cmap[x][y - 1] == 0) {
			cmap[x][y - 1] = 2; cE--;
			q.push(make_pair(x, y - 1));
		}
		
		q.pop();
	}

	return cE;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	int i, j;
	for (i = 0; i <= N + 1; i++) {
		map[i][0] = 1;
		for (j = 1; j <= M; j++) {
			if (i == 0 || i == N + 1) {
				map[i][j] = 1; continue;
			}

			cin >> map[i][j];
			
			switch (map[i][j]) {
			case 0: E++; break;
			case 2: oq.push(make_pair(i, j)); break;
			default: break;
			}
		}
		map[i][j] = 1;
	}

	int a, b, c, max_idx = N * M, cur, max = 0;

	for (a = 0; a < max_idx - 2; a++) {
		for (b = a + 1; b < max_idx - 1; b++) {
			for (c = b + 1; c < max_idx; c++) {
				if (map[a / M + 1][a % M + 1] || map[b / M + 1][b % M + 1] || map[c / M + 1][c % M + 1]) continue;

				cur = count(oq, a, b, c);

				if (cur > max) max = cur;
			}
		}
	}

	cout << max;

	return 0;
}