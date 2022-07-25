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
int main() {
    fastio();
    ll N, K;
    cin >> N >> K;
    ll _max = 0;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
        _max = max(_max, arr[i]);
    }
    ll l = 1;
    ll r = _max;
    ll ans = 0;
    while(l<=r) {
        ll mid = (l+r)>>1;
        ll s = 0;
        for(int i=0; i<N; i++) {
            s += arr[i]/mid;
        }
        if(s>=K) {
            l = mid+1;
            ans = max(ans, mid);
        } else {
            r = mid-1;
        }
    }
    cout << ans;
}