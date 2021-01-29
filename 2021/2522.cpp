#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int i, j, N; cin >> N;

	int LC = 2 * N - 1;

	for (i = 1; i <= LC; i++) {
		int SPC = i <= N ? N - i : i - N;
		for (j = 1; j <= SPC; j++) cout << " ";

		int STC = N - SPC;
		for (j = 1; j <= STC; j++) cout << "*";

		cout << "\n";
	}

	return 0;
}