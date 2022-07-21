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

ll dp[1005][1005];
ll arr[1005][1005];
queue<pair<ll, pair<ll, ll> > > q;

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
    q.push({0, {0, 0}});
    dp[0][0]=0;
    while(!q.empty()) {
        auto now = q.front();
        q.pop();
        for(int i=0; i<4; i++) {
            ll nextX = now.second.first + dx[i];
            ll nextY = now.second.second + dy[i];
            if(0 <= nextX && nextX < N && 0 <= nextY && nextY < M) {
                if(dp[nextX][nextY] == INF) {
                    if(now.first==0 && arr[nextX][nextY]==1) {
                        if(dp[now.second.first][now.second.second]+1 < dp[nextX][nextY]) {
                            dp[nextX][nextY] = min(dp[nextX][nextY], dp[now.second.first][now.second.second]+1);
                            q.push({1, {nextX, nextY}});
                        }
                    }
                    else if(arr[nextX][nextY]==0) {
                        dp[nextX][nextY] = min(dp[nextX][nextY], dp[now.second.first][now.second.second]+1);
                        q.push({now.first, {nextX, nextY}});
                    } 
                }
            }
        }        
    }
    if(dp[N-1][M-1]!=INF) cout << dp[N-1][M-1] + 1;
    else cout << -1;
}
