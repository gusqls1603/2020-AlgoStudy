#include <iostream>
#include <queue>
#include <string>
using namespace std;

int win[21];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, K;
	string name;
	queue <int> que;

	cin >> N >> K;
	cin.get();

	int* arr = new int[N];
	int len;
	long long res = 0;

	for (int i = 0; i < K; i++) {
		getline(cin, name);
		len = name.size();

		res += win[len];

		win[len]++;
		que.push(len);
	}

	for (int i = 0; i < N - K; i++) {
		getline(cin, name);
		len = name.size();

		res += win[len];

		que.push(len);

		win[len]++;
		win[que.front()]--;

		que.pop();
	}
	cout << res;

	return 0;
}