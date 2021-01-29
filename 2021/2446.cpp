#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int i, j, N; cin >> N;

	int LC = 2 * N - 1;
	for (i = 1; i <= LC; i++) {
		int SPC = i <= N ? i - 1 : LC - i;
		int STC = LC - 2 * SPC;
		
		for (j = 1; j <= SPC; j++) cout << " ";
		for (j = 1; j <= STC; j++) cout << "*";
		cout << "\n";
	}

	return 0;
}