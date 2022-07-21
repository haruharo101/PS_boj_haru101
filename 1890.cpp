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

int arr[105][105];
ll dp[105][105];
bool canvisit[105][105];
int main() {
    fastio();
    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> arr[i][j];
        }
    }
    canvisit[0][0]=true;
    dp[0][0] = 1;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(i==N-1 && j==N-1) {
                cout << dp[N-1][N-1];
                return 0;
            }
            if(i+arr[i][j] < N && canvisit[i][j]) {
                dp[i+arr[i][j]][j] += (dp[i][j]);
                canvisit[i+arr[i][j]][j]=true;
            }
            if(j+arr[i][j] < N && canvisit[i][j]) {
                dp[i][j+arr[i][j]] += (dp[i][j]);
                canvisit[i][j+arr[i][j]]=true;
            }
        }
    }
}