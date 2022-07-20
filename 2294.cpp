/* Code By Haru_101
GitHub : haruharo101 */


#include <bits/stdc++.h>
using namespace std;
#define ll long long int


void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

int coin[105];
ll dp[10005];

int main() {
    fastio();
    int N, K;
    cin >> N >> K;
    for(int i=0; i<N; i++) {
        cin >> coin[i];
    }
    for(int i=1; i<=K; i++) {
        dp[i] = 9999999999;
    }
    // select all coins
    for(int i=0; i<=K; i++) {
        for(int j=0; j<N; j++) {
            if(i>=coin[j]) {
                dp[i] = min(dp[i-coin[j]] + 1, dp[i]);
            }
        }
    }
    if(dp[K]!=9999999999) cout << dp[K];
    else cout << -1;
}