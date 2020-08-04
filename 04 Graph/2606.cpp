#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector < vector <int> > v;
vector <int> arr;
int res = 0;

void virus(int x) {
	if (v[x].empty()) return;

	while (!v[x].empty()) {
		if (arr[v[x].back()] == 0) {
			arr[v[x].back()] = 1;
			virus(v[x].back());
			res++;
		}
		v[x].pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, C, i, j;

	cin >> N >> C;

	v.resize(N + 1);
	arr.resize(N + 1, 0);

	while (C--) {
		cin >> i >> j;
		// if (i > j) swap(i, j);
		v[j].push_back(i);
		v[i].push_back(j);
	}

	arr[1] = 1;
	virus(1);
	cout << res;

	return 0;
}