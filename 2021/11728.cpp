#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M, i, j;
	cin >> N >> M;

	int* A = new int[N];
	int* B = new int[M];

	for (i = 0; i < N; i++)
		cin >> A[i];

	for (j = 0; j < M; j++)
		cin >> B[j];

	i = 0; j = 0;

	while (i < N && j < M) {
		if (A[i] <= B[j]) {
			cout << A[i] << ' ';
			i++;
		}
		else {
			cout << B[j] << ' ';
			j++;
		}

		if (i == N) {
			while (j < M) {
				cout << B[j] << ' ';
				j++;
			}
			break;
		}

		if (j == M) {
			while (i < N) {
				cout << A[i] << ' ';
				i++;
			}
			break;
		}
	}
	return 0;
}