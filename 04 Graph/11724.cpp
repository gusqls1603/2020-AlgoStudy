#include <iostream>
#include <vector>
using namespace std;

int visit[1001];
vector <int> v[1001];

void search(int num) {
	visit[num] = 1;

	int next, len = v[num].size();
	for (int i = 0; i < len; i++) {
		next = v[num][i];
		if (visit[next] == 0) {
			search(next);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M, A, B, res = 0;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> A >> B;

		v[A].push_back(B);
		v[B].push_back(A);
	}
	
	for (int i = 1; i <= N; i++) {
		if (visit[i] == 0) {
			search(i);
			res++;
		}
	}

	cout << res;
	return 0;
}