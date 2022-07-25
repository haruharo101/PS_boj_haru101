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
int N, K;
int ans = 0;
bool visited[105];
string arr[105];

int check() {
    int T = 0;
    for(int i=0; i<N; i++) {
        bool f = false;
        for(int j=0; j<arr[i].size(); j++) {
            if(!visited[arr[i][j]-'a']) {
                f = true;
                break;
            }
        }
        if(!f) T++;
    }
    return T;
}

void dfs(int cur, int cnt) {
    if(cnt == K) {
        ans = max(ans, check());
        return;
    }
    for(int j=cur; j<26; j++) {
        if(!visited[j]) {
            visited[j]=true;
            dfs(j, cnt+1);
            visited[j]=false;
        }
    }
}
int main() {
    fastio();
    cin >> N >> K;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    if(K<5) {
        cout << 0;
        return 0;
    } else {
        K -= 5;
        visited['a'-'a'] = true; visited['n'-'a'] = true; visited['t'-'a']=true; visited['i'-'a']=true; visited['c'-'a'] = true;
        dfs(0, 0);
        cout << ans;
    }
}