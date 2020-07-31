#include <iostream>

int main()
{
	int N, M;;

	int a, b, c, d, e, f, g, h;

	scanf("%d %d", &N, &M);

	for (a = 1; a <= N; a++) {
		if (M == 1) {
			printf("%d\n", a);
			continue;
		}
		for (b = a + 1; b <= N; b++) {
			if (M == 2) {
				printf("%d %d\n", a, b);
				continue;
			}
			for (c = b + 1; c <= N; c++) {
				if (M == 3) {
					printf("%d %d %d\n", a, b, c);
					continue;
				}
				for (d = c + 1; d <= N; d++) {
					if (M == 4) {
						printf("%d %d %d %d\n", a, b, c, d);
						continue;
					}
					for (e = d + 1; e <= N; e++) {
						if (M == 5) {
							printf("%d %d %d %d %d\n", a, b, c, d, e);
							continue;
						}
						for (f = e + 1; f <= N; f++) {
							if (M == 6) {
								printf("%d %d %d %d %d %d\n", a, b, c, d, e, f);
								continue;
							}
							for (g = f + 1; g <= N; g++) {
								if (M == 7) {
									printf("%d %d %d %d %d %d %d\n", a, b, c, d, e, f, g);
									continue;
								}
								for (h = g + 1; h <= N; h++) {
									if (M == 8) {
										printf("%d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h);
										continue;
									}
								}
							}
						}
					}
				}
			}
		}
	}

	return 0;
}