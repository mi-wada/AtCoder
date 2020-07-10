#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<iomanip>
#include<map>
#include<cstring>

using namespace std;

typedef long long int ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define vi vector<int>
#define vivi vector<vi>
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
/* -- template -- */
ll dp[6][4001][3];
int N;
string S;

void ff(char r, char b, int patern) {
    for(int i = 0;i < N;++i){
        rep(j, 3)
            dp[patern][i + 1][j] = dp[patern][i][j];
        if(S[i] == r)
            dp[patern][i + 1][0] += 1;
        else if(S[i] == b)
            dp[patern][i + 1][1] += dp[patern][i][0];
        else
            dp[patern][i + 1][2] += dp[patern][i][1];
    }
}

int main() {
    cin >> N;
    cin >> S;
    ll ans = 0;
    ff('R', 'G', 0);
    ff('R', 'B', 1);
    ff('B', 'R', 2);
    ff('B', 'G', 3);
    ff('G', 'R', 4);
    ff('G', 'B', 5);
    rep(i, 6)
        ans += dp[i][N][2];
    for(int i = 0;i < N;++i) {
        for(int j = 0;i + 2 * j < N;++j) {
            if((S[i] != S[i + j]) && (S[i + j] != S[i + 2 * j]) && (S[i] != S[i + 2 * j]))
                --ans;
        }
    }
    cout << ans << endl;
}
