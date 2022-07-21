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

int arr[1005];
int dp[1005];
int main() {
    fastio();
    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    dp[0] = 1;
    int ans = 0;
    for(int i=1; i<N; i++) {
        if(arr[i] > arr[i-1]) dp[i] = dp[i-1] + 1;
        else dp[i] = 1;
        ans = max(ans, dp[i]);
    }
    cout << ans;
}