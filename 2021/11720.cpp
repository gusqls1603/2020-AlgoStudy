#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, num, sum = 0;

	scanf("%d", &N);

	while (N--) {
		scanf("%1d", &num);
		
		sum += num;
	}

	printf("%d", sum);

	return 0;
}