#include <stdio.h>

int main()
{
	long long int A, B, temp, ans;

	scanf("%lld %lld", &A, &B);

	if (A > B) {
		temp = A;
		A = B;
		B = temp;
	}

	ans = (A + B) * (B - A + 1) * 0.5;

	printf("%lld\n", ans);

	return 0;
}