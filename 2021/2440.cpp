#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N;

	cin >> N;

	do {
		for (int i = 1; i <= N; i++) {
			cout << "*";
		}
		cout << "\n";
	} while (N--);

	return 0;
}