#include <iostream>
#include <string.h>
using namespace std;

enum _pipe { horz, vert, diag };

int table[17][17][3];
int map[18][18];

int isEmpty(int r, int c) {
	return !map[r][c];
}

int isWall(int r, int c) {
	return map[r][c];
}

int Search(int r, int c, _pipe type)
{
	int* result = &table[r][c][type];

	if (*result != -1) /* already filled */
		return *result;
	else {
		switch (type) {
		case horz:
			if (isWall(r, c + 1))
				*result = 0;
			else if (isWall(r + 1, c + 1) || isWall(r + 1, c))
				*result = Search(r, c + 1, horz);
			else
				*result = Search(r, c + 1, horz) + Search(r + 1, c + 1, diag);
			break;

		case vert:
			if (isWall(r + 1, c))
				*result = 0;
			else if (isWall(r, c + 1) || isWall(r + 1, c + 1))
				*result = Search(r + 1, c, vert);
			else
				*result = Search(r + 1, c, vert) + Search(r + 1, c + 1, diag);
			break;

		case diag:
			if (isWall(r + 1, c) && isWall(r, c + 1))
				*result = 0;
			else if (isWall(r + 1, c))
				*result = Search(r, c + 1, horz);
			else if (isWall(r, c + 1))
				*result = Search(r + 1, c, vert);
			else if (isWall(r + 1, c + 1))
				*result = Search(r, c + 1, horz) + Search(r + 1, c, vert);
			else
				*result = Search(r, c + 1, horz) + Search(r + 1, c, vert) + Search(r + 1, c + 1, diag);
			break;
		}
		return *result;
	}
}

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	memset(table, -1, sizeof(table));
	memset(map, 0, sizeof(map));

	int i, j, N;
	cin >> N;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++)
			cin >> map[i][j];
		map[i][j] = 1; /* coating outside the map */
	}
	for (j = 1; j <= N; j++)
		map[i][j] = 1;
	map[i][j] = 1;
	
	table[N][N][horz] = table[N][N][vert] = table[N][N][diag] = 1;
}

int main()
{
	init();

	cout << Search(1, 2, horz);

	return 0;
}