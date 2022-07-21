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

ll arr[1005];
ll dp[10005];
int main() {
    fastio();
    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(j <= i) {
                dp[i] = max(dp[i], dp[i-j-1]+arr[j]);
            }
        }
    }
    cout << dp[N-1];
}