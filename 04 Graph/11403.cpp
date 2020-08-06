#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector <vector <int> > v;
int target, found, visit[100];

void search(int num) {
	if (found) return;

	visit[num] = 1;

	int next, len = v[num].size();
	for (int i = 0; i < len; i++) {
		if (found) return;

		next = v[num][i];
		if (next == target) {
			found = 1;
			return;
		}

		if (visit[next] == 0) search(next);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, input, res = 0;
	cin >> N;
	v.resize(N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> input;

			if (input == 1) v[i].push_back(j);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			memset(visit, 0, sizeof(visit));
			target = j; found = 0;
			search(i);

			if (found) cout << "1 ";
			else cout << "0 ";
		}
		cout << "\n";
	}

	return 0;
}