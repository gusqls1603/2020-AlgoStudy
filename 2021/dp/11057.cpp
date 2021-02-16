#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int table[1001][10] = {0}, N, i, j, k;
    fill(table[1], table[1]+10, 1);

    cin >> N;

    for(i=2;i<=N;i++){
        for(j=0;j<10;j++){
            for(k=j;k<10;k++){
                table[i][j] = (table[i][j] + table[i-1][k]) % 10007;
            }
        }
    }

    int res = 0;
    for(i=0;i<10;i++) res = (res + table[N][i]) % 10007;

    cout << res;

    return 0;
}