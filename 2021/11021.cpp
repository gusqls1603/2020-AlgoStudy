#include <iostream>
using namespace std;

#define MAX 100000000

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T, A, B;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> A >> B;

		printf("Case #%d: %d\n", i + 1, A + B);
	}
	
	return 0;
}