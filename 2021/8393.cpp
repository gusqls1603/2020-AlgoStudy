#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;

	cin >> n;

	cout << (1 + n) * n / 2;

	return 0;
}