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

pair<int, int> bag[105];
ll dp[105][100005];

int main() {
    fastio();
    int N, K;
    cin >> N >> K;
    for(int i=1; i<=N; i++) {
        cin >> bag[i].first >> bag[i].second;
    }
    ll ans = 0;
    for(int i=1; i<=N; i++) {
        for(int j=0; j<=K; j++) {
            auto now = bag[i];
            if(now.first <= j) { // if wi < j
                dp[i][j] = max(dp[i-1][j - now.first] + now.second, dp[i-1][j]); 
            } else {
                dp[i][j] = dp[i-1][j];
            }
            ans = max(dp[i][j], ans);
        }
    }
    cout << ans;
}