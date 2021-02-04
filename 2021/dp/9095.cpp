#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int table[11], T, n;

	cin >> T;

	table[1] = 1, table[2] = 2, table[3] = 4;

	for (int i = 4; i <= 10; i++)
		table[i] = table[i - 3] + table[i - 2] + table[i - 1];
		

	while (T--) {
		cin >> n;

		cout << table[n] << '\n';
	}

	return 0;
}