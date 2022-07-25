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

ll arr[200005];

int main() {
    fastio();
    ll N, C;
    cin >> N >> C;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+N);
    
}