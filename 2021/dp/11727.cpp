#include <iostream>
using namespace std;

int table[1001], N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	table[1] = 1, table[2] = 3;

	for (int i = 3; i <= N; i++)
		table[i] = (table[i - 1] + 2 * table[i - 2]) % 10007;
	
	cout << table[N];

	return 0;
}