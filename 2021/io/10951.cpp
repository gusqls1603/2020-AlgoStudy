#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int A, B;

	while (scanf("%d %d", &A, &B) != EOF) {
		cout << A + B << endl;
	}

	return 0;
}