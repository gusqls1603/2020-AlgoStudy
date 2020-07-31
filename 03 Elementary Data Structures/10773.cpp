#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int K, n, sum = 0;
	stack <char> stk;

	cin >> K;

	while (K--) {
		cin >> n;
		if (!n) {
			sum -= stk.top();
			stk.pop();
		}
		else {
			sum += n;
			stk.push(n);
		}
	}

	cout << sum;

	return 0;
}