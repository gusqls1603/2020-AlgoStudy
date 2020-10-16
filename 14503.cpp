#include <iostream>
#include <vector>
using namespace std;

enum _type { Empty, Wall };
enum _state { Dirty, Clean };
enum _direction { North, East, South, West };
int step_r[] = { -1, 0, 1, 0 };
int step_c[] = { 0, 1, 0, -1 };

void init(), Working(), Cleaning(), Checking(), Stop();
bool isEmpty(int, int), isWall(int, int), isDirty(int, int), isClean(int, int);
bool conditionA(int, int), conditionB(int, int), conditionC(int, int);
_direction turnLeft(_direction);

struct _map {
	_type type;
	_state state;
};

struct _cleaner {
	int Row;
	int Col;
	int count;
	_direction direction;
};

int N, M, r, c;
_cleaner cleaner;
vector <vector <_map> > map;

void init()
{
	cleaner.count = 0;

	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &cleaner.Row, &cleaner.Col, &cleaner.direction);

	map.resize(N);

	for (int i = 0; i < N; i++) {
		map[i].resize(M);

		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j].type);
			map[i][j].state = Dirty;
		}
	}
}

void Working()
{
	Cleaning();

	Checking();
}

void Cleaning ()
{
	if (map[cleaner.Row][cleaner.Col].state == Dirty) {
		map[cleaner.Row][cleaner.Col].state = Clean;
		cleaner.count++;
	}
}

void Checking()
{
	_direction Left = turnLeft(cleaner.direction);
	int Left_r = cleaner.Row + step_r[Left];
	int Left_c = cleaner.Col + step_c[Left];

	if (conditionC(cleaner.Row, cleaner.Col)) {
		_direction Back = turnLeft(Left);
		int Back_r = cleaner.Row + step_r[Back];
		int Back_c = cleaner.Col + step_c[Back];
		if (!isWall(Back_r, Back_c)) {
			cleaner.Row = Back_r;
			cleaner.Col = Back_c;

			Checking();
		}
		else
			return;
	}
	else if (conditionB(Left_r, Left_c)) {
		cleaner.direction = Left;

		Checking();
	}
	else if (conditionA(Left_r, Left_c)) {
		cleaner.direction = Left;
		cleaner.Row = Left_r;
		cleaner.Col = Left_c;

		Working();
	}
}

int main()
{
	init();

	Working();

	printf("%d", cleaner.count);

	return 0;
}

_direction turnLeft(_direction d)
{
	switch (d) {
	case North: return West;
	case East: return North;
	case South: return East;
	case West: return South;
	}
}

bool isEmpty(int row, int col) {
	return map[row][col].type == Empty;
}

bool isWall(int row, int col) {
	return map[row][col].type == Wall;
}

bool isDirty(int row, int col) {
	return map[row][col].state == Dirty;
}

bool isClean(int row, int col) {
	return map[row][col].state == Clean;
}

bool conditionA(int row, int col) {
	return isEmpty(row, col) && isDirty(row, col);
}

bool conditionB(int row, int col) {
	return isWall(row, col) || (isEmpty(row, col) && isClean(row, col));
}

bool conditionC(int row, int col) {
	bool condNorth, condEast, condSouth, condWest;

	condNorth = (isEmpty(row + step_r[North], col + step_c[North]) && isClean(row + step_r[North], col + step_c[North]))
		|| isWall(row + step_r[North], col + step_c[North]);
	condEast = (isEmpty(row + step_r[East], col + step_c[East]) && isClean(row + step_r[East], col + step_c[East]))
		|| isWall(row + step_r[East], col + step_c[East]);
	condSouth = (isEmpty(row + step_r[South], col + step_c[South]) && isClean(row + step_r[South], col + step_c[South]))
		|| isWall(row + step_r[South], col + step_c[South]);
	condWest = (isEmpty(row + step_r[West], col + step_c[West]) && isClean(row + step_r[West], col + step_c[West]))
		|| isWall(row + step_r[West], col + step_c[West]);

	return condNorth && condEast && condSouth && condWest;
}

/*
void printmap();
void printmap()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j].type == Wall) {
				printf("1 ");
			}
			else {
				if (i == cleaner.Row && j == cleaner.Col) {
					printf("5 ");
				}
				else {
					if (map[i][j].state == Dirty) printf("3 ");
					else printf("0 ");
				}
			}
		}
		printf("\n");
	}
	printf("direction : %d\n", cleaner.direction);
	printf("clean count : %d\n", cleaner.count);
}
*/