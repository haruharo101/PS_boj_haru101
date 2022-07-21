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

ll dp[260];
int main() {
    fastio();
    int N;
    cin >> N;
    dp[0] = 0;
    dp[1] = 1; 
    dp[2] = 3; 
    dp[3] = 5; 
    dp[4] = 11;
    for(int i=5; i<=N; i++) {
        dp[i] = dp[i-1] + dp[i-2]*2;
    }
    cout << dp[N];
}