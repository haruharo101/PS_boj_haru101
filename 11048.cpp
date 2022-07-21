/* Code By Haru_101
GitHub : haruharo101 */


#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 999999999999


void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

ll dp[1005][1005];
ll arr[1005][1005];
int main() {
    fastio();
    int N, M;
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(i==0 && j==0) dp[i][j] = arr[0][0];
            else {
                if(i-1>=0) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j] + arr[i][j]);
                }
                if(j-1>=0) {
                    dp[i][j] = max(dp[i][j], dp[i][j-1] + arr[i][j]);
                }
                if(i-1>=0 && j-1>=0) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + arr[i][j]);
                }
            }
        }
    }
    cout << dp[N-1][M-1];
}