#include <iostream>
using namespace std;

int _count[3];
int** map;

void func(int size, int x, int y) {
	int init = map[x][y]; bool flag = false;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (map[x + i][y + j] != init) {
				flag = true; break;
			}
		}
		if (flag) break;
	}

	if (!flag) {
		_count[init + 1]++;
		return;
	}
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (size == 3) {
					_count[map[x + i][y + j] + 1]++;
				}
				else {
					func(size / 3, x + i * size / 3, y + j * size / 3);
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	map = new int* [N];
	for (int i = 0; i < N; i++) {
		map[i] = new int[N];
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	func(N, 0, 0);

	cout << _count[0] << endl << _count[1] << endl << _count[2];

	return 0;
}