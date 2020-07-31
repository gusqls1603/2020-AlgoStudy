#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, i, lp, rp, temp, min_val, res1, res2;
	scanf("%d", &N);

	int* arr = new int[N];

	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr + i);

	lp = 0; rp = i - 1; min_val = 2100000000;

	while (lp != rp) {
		/*
		if (arr[lp] > 0 || arr[rp] < 0) {
			break;
		}
		*/

		temp = arr[lp] + arr[rp];

		if (abs(temp) < min_val) {
			min_val = abs(temp);
			res1 = lp;
			res2 = rp;
		}

		if (temp > 0) {
			rp--;
		}
		else if (temp < 0) {
			lp++;
		}
		else {
			printf("%d %d", arr[lp], arr[rp]);
			return 0;
		}
	}

	printf("%d %d", arr[res1], arr[res2]);

	return 0;
}