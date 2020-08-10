#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

vector <pair <string, string> > v;
bool visit[2][100][100];
int res[2], N;

int dr[] = { 1, 0, -1, 0 };
int dc[] = { 0, 1, 0 , -1};

int isinrange(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < N;
}

void search(int row, int col, int mode) {
	if (visit[mode][row][col]) return;
	visit[mode][row][col] = true;
	
	int next_r, next_c;
	for (int k = 0; k < 4; k++) {
		next_r = row + dr[k], next_c = col + dc[k];

		if (isinrange(next_r, next_c) && !visit[mode][next_r][next_c]) {
			if (mode == 0) { // 정상
				if (v[row].first[col] != v[next_r].first[next_c]) {
					continue;
				}
			}
			else { // 색약
				if (v[row].second[col] != v[next_r].second[next_c]) {
					continue;
				}
			}
			search(next_r, next_c, mode);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N; cin.get();
	v.resize(N);
	
	for (int i = 0; i < N; i++) {
		getline(cin, v[i].first);
		v[i].second.assign(v[i].first);

		for (int j = 0; j < N; j++) {
			if (v[i].second[j] == 'G') v[i].second[j] = 'R';
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit[0][i][j]) {
				search(i, j, 0);
				res[0]++;
			}
			if (!visit[1][i][j]) {
				search(i, j, 1);
				res[1]++;
			}
		}
	}

	cout << res[0] << " " << res[1];

	return 0;
}