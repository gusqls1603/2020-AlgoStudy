#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	queue <int> que;

	int N, K, i;
	cin >> N >> K;

	for (i = 1; i <= N; i++)
		que.push(i);

	cout << '<';
	for (i = 1; !que.empty(); i++) {
		if (i % K == 0) {
			if (que.size() != 1)
				cout << que.front() << ", ";
			else
				cout << que.front() << ">\n";
			que.pop();
		}
		else {
			que.push(que.front());
			que.pop();
		}
	}

	return 0;
}