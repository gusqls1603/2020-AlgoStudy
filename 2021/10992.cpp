#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N; cin >> N;
	int i, j, SPC1, SPC2;

	for (i = 1; i < N; i++) {
		SPC1 = N - i; SPC2 = 2 * (i - 1) - 1;

		for (j = 1; j <= SPC1; j++) cout << " ";
		cout << "*";
		for (j = 1; j <= SPC2; j++) cout << " ";
		
		if (i == 1) cout << "\n";
		else cout << "*\n";
	}
	N = 2 * N - 1;
	for (i = 1; i <= N; i++) cout << "*";

	return 0;
}