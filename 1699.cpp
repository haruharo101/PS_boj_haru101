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

ll dp[100005];

int main() {
    fastio();
    int N;
    cin >> N;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=N; i++) {
        dp[i] = INF;
    }
    for(int i=3; i<=N; i++) {
        for(int j=1; j*j<=i; j++) {
            dp[i] = min(dp[i], dp[i-j*j]+1);
        }
    }
    cout << dp[N];
}