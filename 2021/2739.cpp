#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N;

	cin >> N;

	for (int i = 1; i <= 9; i++) {
		printf("%d * %d = %d\n", N, i, N * i);
	}
	
	return 0;
}