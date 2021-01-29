#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, i, j;

	cin >> N;

	int M = 2 * N - 1;
	for (i = 1; i <= M; i++) {
		int ST = i > N ? 2 * N - i : i;
		for (j = 1; j <= ST; j++) cout << "*";

		int SP = 2 * (N - ST);
		for (j = 1; j <= SP; j++) cout << " ";

		for (j = 1; j <= ST; j++) cout << "*";

		cout << "\n";
	}

	return 0;
}