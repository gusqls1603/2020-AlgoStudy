#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	char c;

	for (int i = 1; cin >> c; i++) {
		cout << c;
		
		if (i == 10) {
			cout << endl;

			i = 0;
		}
	}

	return 0;
}