#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int N, M, dist[101], start;
vector <int> v[101];

void search(int num) {
	int len = v[num].size(), next_num;
	for (int i = 0; i < len; i++) {
		next_num = v[num][i];
		if (next_num == start) continue;

		if (dist[next_num] == 0 || dist[next_num] > dist[num] + 1) {
			dist[next_num] = dist[num] + 1;
			
			search(next_num);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int A, B, bacon, min_bacon = 1000000000, res = 1;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> A >> B;

		v[A].push_back(B);
		v[B].push_back(A);
	}

	for (int i = 1; i <= N; i++) {
		bacon = 0;
		memset(dist, 0, sizeof(dist));

		start = i;
		dist[i] = 0;
		search(i);

		for (int j = 1; j <= N; j++) {
			if (j == i) continue;
			bacon += dist[j];
		}
		if (bacon < min_bacon) {
			min_bacon = bacon;
			res = i;
		}
	}

	cout << res;

	return 0;
}