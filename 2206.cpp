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

bool visited[1005][1005][2];
ll dp[1005][1005];
ll arr[1005][1005];
queue<pair<pair<ll, ll>, pair<ll, ll> > > q;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int main() {
    fastio();
    int N, M;
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        string s;
        cin >> s;
        for(int j=0; j<M; j++) {
            arr[i][j] = int(s[j] - '0');
            dp[i][j] = INF;
        }
    }
    q.push({{0, 1}, {0, 0}});
    visited[0][0][0]=true;
    while(!q.empty()) {
        auto now = q.front();
        q.pop();
        if(now.second.first == N-1 && now.second.second == M-1) {
            cout << now.first.second;
            return 0;
        }
        for(int i=0; i<4; i++) {
            ll nextX = now.second.first + dx[i];
            ll nextY = now.second.second + dy[i];
            if(0 <= nextX && nextX < N && 0 <= nextY && nextY < M && !visited[nextX][nextY][now.first.first]) {
                if(arr[nextX][nextY]==0) {
                    visited[nextX][nextY][now.first.first]=true;
                    q.push({{now.first.first, now.first.second+1}, {nextX, nextY}});
                } else if(now.first.first==0) {
                    visited[nextX][nextY][1]=true;
                    q.push({{1, now.first.second+1}, {nextX, nextY}});
                }
            }
        }        
    }
    cout << -1;
}
