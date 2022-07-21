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

ll dp[1000005];
int main() {
    fastio();
    int N;
    cin >> N;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for(int i=4; i<=N; i++) {
        dp[i] = INF;
        if(i%3==0) dp[i] = min(dp[i], dp[i/3]+1);
        if(i%2==0) dp[i] = min(dp[i], dp[i/2]+1);
        dp[i] = min(dp[i], dp[i-1]+1);
    }
    cout << dp[N] << '\n';
    // -----------------------
    int k = N;
    while(k!=1) {
        cout << k << ' ';
        if(dp[k] == dp[k-1] + 1) k = k-1;
        else if(k%2==0 && dp[k] == dp[k/2] + 1) {
            k = k/2;
        }
        else if(k%3==0 && dp[k] == dp[k/3] + 1) {
            k = k/3;
        }
    }
    cout << 1;
}