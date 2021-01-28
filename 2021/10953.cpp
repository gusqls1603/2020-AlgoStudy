#include <iostream>
using namespace std;

#define MAX 100000000

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T, A, B;
	cin >> T;

	while (T--) {
		cin >> A;
		cin.ignore(MAX, ','); cin.clear();
		cin >> B;

		cout << A + B << endl;
	}
	
	return 0;
}