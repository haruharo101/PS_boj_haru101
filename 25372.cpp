/* Code By Haru_101
GitHub : haruharo101 */


#include <bits/stdc++.h>
using namespace std;
#define ll long long int


void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(0);
}


int main() {
    fastio();
    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        string q;
        cin >> q;
        if(int(q.size())>=6 && int(q.size())<=9) cout << "yes\n";
        else cout << "no\n";
    }
}
