#include <iostream>
using namespace std;
#define MOD 1000000000;

int table[101][10], N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for(int i=1;i<=9;i++) table[1][i] = 1;

    cin >> N;
    for(int i=2;i<=N;i++){
        for(int j=0;j<=9;j++){
            if(j==0) table[i][j] = table[i-1][1];
            else if (j==9) table[i][j] = table[i-1][8];
            else table[i][j] = (table[i-1][j-1] + table[i-1][j+1]) % MOD;
        }
    }
    int res = 0;
    for(int i=0;i<=9;i++) res = (res + table[N][i]) % MOD;
    
    cout << res;

    return 0;
}