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

ll arr[1000005];
int main() {
    fastio();
    ll N, M;
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    ll l = 0, r = 1000000000;
    while(l+1<r) {
        ll s = 0;
        ll m = (l+r)>>1;
        for(int i=0; i<N; i++) {
            if(arr[i] > m) {
                s += arr[i]-m;
            }
        }
        if(s >= M) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l;
}