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

int N, M;
int ans = 9999;
pair<int, int> coin1, coin2;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char arr[105][105];
bool check(pair<int, int> pos) {
    int X = pos.first;
    int Y = pos.second;
    if(X < 0 || X >= N || Y < 0 || Y >= M) return true;
    return false;
}

void dfs(pair<int, int> cur1, pair<int, int> cur2, int cnt, int dir) {
    if(cnt > ans) return;
    if(cnt > 10) {
        ans = min(ans, cnt);
        return;
    }
    int x1 = cur1.first + dx[dir];
    int x2 = cur2.first + dx[dir];
    int y1 = cur1.second + dy[dir];
    int y2 = cur2.second + dy[dir];
    if(check({x1, y1}) && check({x2, y2})) return;
    if((check({x1, y1}) && check({x2, y2})==false) || (check({x1, y1})==false) && check({x2, y2})) {
        ans = min(ans, cnt);
        return;
    } else {
        if(arr[x1][y1]=='#') {
            x1 = cur1.first;
            y1 = cur1.second;
        }
        if(arr[x2][y2]=='#') {
            x2 = cur2.first;
            y2 = cur2.second;
        }
        for(int i=0; i<4; i++) {
            dfs({x1, y1}, {x2, y2}, cnt+1, i);
        }
    }
}
int main() {
    fastio();
    cin >> N >> M;
    vector<pair<int, int> > tmp;
    for(int i=0; i<N; i++) {
        string s;
        cin >> s;
        for(int j=0; j<M; j++) {
            arr[i][j] = s[j];
            if(arr[i][j]=='o') {
                tmp.push_back({i, j});
            }
        }
    }
    coin1.first = tmp[0].first;
    coin1.second = tmp[0].second;
    coin2.first = tmp[1].first;
    coin2.second = tmp[1].second;
    for(int i=0; i<4; i++) {
        dfs(coin1, coin2, 1, i);
    }
    if(ans <= 10) cout << ans;
    else cout << -1;
}