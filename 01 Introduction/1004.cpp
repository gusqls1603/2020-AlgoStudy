#include <stdio.h>
#include <math.h>

int main()
{
	int T, x1, y1, x2, y2, n, cx, cy, r, count;

	double d1, d2;

	scanf("%d", &T);

	while (T--) {
		count = 0;

		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		scanf("%d", &n);

		while (n--) {
			scanf("%d %d %d", &cx, &cy, &r);

			d1 = sqrt((x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy));
			d2 = sqrt((x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy));

			if ((d1 < r && d2 > r) || (d1 > r && d2 < r))
				count++;

		}
		printf("%d\n", count);
	}

	return 0;
}