#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string str;

	while (getline(cin, str)) {
		cout << str << endl;
	}

	return 0;
}