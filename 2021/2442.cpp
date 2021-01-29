#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, i, j;

	cin >> N;

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N - i; j++) cout << " ";

		int M = 2 * i - 1;
		for (j = 1; j <= M; j++) cout << "*";

		cout << "\n";
	}

	return 0;
}