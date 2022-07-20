/* Code By Haru_101
GitHub : haruharo101 */


#include <bits/stdc++.h>
using namespace std;
#define ll long long int


void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}

ll dp[1000005];

int main() {
    fastio();
    dp[1] = 0;
    int N;
    cin >> N;
    for(int i=2; i<=N; i++) {
        dp[i] = 999999999999;
    }
    for(int i=2; i<=N; i++) {
        if(i%3==0) dp[i] = min(dp[i], dp[i/3]+1);
        if(i%2==0) dp[i] = min(dp[i], dp[i/2]+1);
        dp[i] = min(dp[i], dp[i-1]+1);
    }
    cout << dp[N];
}