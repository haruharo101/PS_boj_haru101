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
    int N;
    cin >> N;
    ll mt = 0;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
        mt = max(mt, arr[i]);
    }
    ll M;
    cin >> M;
    ll l = 0, r = mt;
    ll ans = 0;
    while(l <= r) {
        ll mid = (l+r)>>1;
        ll s = 0;
        for(int i=0; i<N; i++) {
            s += min(arr[i], mid);
        }
        if(s <= M) {
            l = mid+1;
            ans = mid;
        } else {
            r = mid-1;
        }
    }
    cout << ans;
}