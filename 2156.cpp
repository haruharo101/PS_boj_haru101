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

ll arr[10005];
ll dp[10005][2]; 
/* j=0 -> no drink 
    j=1 -> drint it 
    j=2 -> drint i-1th, ith
*/
int main() {
    fastio();
    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    dp[0][1] = arr[0];
    ll ans=0;
    for(int i=1; i<N; i++) {
        if(i==1) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = arr[i];
            dp[i][2] = dp[i-1][1] + arr[i];
        } else {
            dp[i][0] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});
            dp[i][1] = max({dp[i-1][0] + arr[i], dp[i-2][2] + arr[i]});
            dp[i][2] = dp[i-1][1] + arr[i];
        }
        ans = max({dp[i][0], dp[i][1], dp[i][2]});
    }
    ans = max(arr[0], ans);
    cout << ans;
}