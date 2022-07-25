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
ll N, S;
ll arr[25], sum;
int cnt=0;

void dfs(ll idx) {
    if(idx==N) return;
    if(sum + arr[idx] == S) cnt++;
    dfs(idx+1);

    sum += arr[idx];
    dfs(idx+1);
    sum -= arr[idx];
}
int main() {
    fastio();
    cin >> N >> S;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    dfs(0);
    cout << cnt;
}