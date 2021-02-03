#include <iostream>
using namespace std;

int table[1000001];


int func(int n) {
	if (table[n]) return table[n];
	if (n == 3 || n == 2) { table[n] = 1; return 1; }
	if (n == 1) return 0;

	int c1, c2, c3; c1 = c2 = c3 = 1000000;

	if (n % 3 == 0) {
		if (table[n / 3]) c1 = table[n / 3] + 1;
		else c1 = func(n / 3) + 1;
	}
	if (n % 2 == 0) {
		if (table[n / 2]) c2 = table[n / 2] + 1;
		else c2 = func(n / 2) + 1;
	}
	if (table[n - 1]) c3 = table[n - 1] + 1;
	else c3 = func(n - 1) + 1;

	int min;
	if (c1 <= c2 && c1 <= c3) min = c1;
	else if (c2 <= c1 && c2 <= c3) min = c2;
	else min = c3;

	table[n] = min;
	return min;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N; cin >> N;

	cout << func(N);

	return 0;
}