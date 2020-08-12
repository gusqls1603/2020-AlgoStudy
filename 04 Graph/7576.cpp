#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <vector <int> > field;
queue <pair <int, int> > wave;
int remain = 0, day = 0, M, N; // 가로, 세로;

int dr[] = { 1, 0, -1, 0 };
int dc[] = { 0, -1, 0, 1 };
int isinrange(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < M;
}

void spread() {
	int num = wave.size();
	int cur_r, cur_c, next_r, next_c;

	for (int i = 0; i < num; i++) {
		cur_r = wave.front().first;
		cur_c = wave.front().second;

		for (int k = 0; k < 4; k++) {
			next_r = cur_r + dr[k];
			next_c = cur_c + dc[k];

			if (isinrange(next_r, next_c)) {
				if (field[next_r][next_c] == 0) {
					field[next_r][next_c] = 1;
					remain--;
					wave.push(make_pair(next_r, next_c));
				}
			}
		}
		wave.pop();
	}
	day++;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> M >> N;

	field.resize(N);
	for (int i = 0; i < N; i++) {
		field[i].resize(M);

		for (int j = 0; j < M; j++) {
			cin >> field[i][j];

			switch (field[i][j]) {
			case 0: remain++; break;
			case 1: wave.push(make_pair(i, j)); break;
			default: break;
			}
		}
	}

	while (!wave.empty() && remain)
		spread();

	if (remain)
		cout << -1;
	else
		cout << day;

	return 0;
}