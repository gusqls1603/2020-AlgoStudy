#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	stack <char> stk;
	string str;
	int T, len;

	cin >> T;
	cin.get();

	while (T--) {
		getline(cin, str);
		len = str.size();

		for (int i = 0; i < len; i++) {
			if (str[i] == '(') stk.push('(');
			else {
				if (stk.empty()) {
					cout << "NO\n";
					break;
				}
				else stk.pop();
			}

			if (i == len - 1) {
				if (stk.empty()) cout << "YES\n";
				else {
					cout << "NO\n";
					while (!stk.empty()) stk.pop();
				}
			}
		}
	}

	return 0;
}