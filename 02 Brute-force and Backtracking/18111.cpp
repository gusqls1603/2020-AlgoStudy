#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, M, B, i, j, h;

	scanf("%d %d %d", &N, &M, &B);

	int** map = new int* [N];
	for (i = 0; i < N; i++) {
		map[i] = new int[M];
	}

	int min_time = 1000000000, res_height = 0, min_h = -1, max_h = -1;

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			if (min_h == -1) {
				min_h = map[i][j];
				continue;
			}
			if (max_h == -1) {
				max_h = map[i][j];
				if (min_h > max_h)
					swap(min_h, max_h);
				continue;
			}

			if (map[i][j] < min_h) {
				min_h = map[i][j];
				continue;
			}
			if (map[i][j] > max_h) {
				max_h = map[i][j];
				continue;
			}
		}
	}

	int cost_block, cost_time;

	for (h = min_h; h <= max_h; h++) {
		cost_block = cost_time = 0;

		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				cost_block += (h - map[i][j]);

				if (map[i][j] < h)
					cost_time += 1 * (h - map[i][j]);
				else if (map[i][j] > h)
					cost_time -= 2 * (h - map[i][j]);
			}
		}

		if (cost_block > B)
			continue;
		else {
			if (cost_time <= min_time) {
				min_time = cost_time;
				res_height = h;
			}
		}
	}

	printf("%d %d", min_time, res_height);

	return 0;
}