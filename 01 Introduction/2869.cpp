#include <stdio.h>

int main()
{
	int A, B, V;

	double day;

	scanf("%d %d %d", &A, &B, &V);

	day = (V - B) / (double)(A - B);

	if (day - (int)day == 0)
		printf("%d", (int)day);
	else
		printf("%d", (int)day + 1);

	return 0;
}