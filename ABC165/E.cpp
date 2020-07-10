#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<cstring>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define P pair<ll, ll>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()

/* -- template -- */
const int MAX_S = 1e5 + 1;

ll dp[MAX_S][13]; //dp[i][j] : i桁目まで見たとき，j余る通り数
/*
dp[i + 1][0] = dp[i][(S[i] - '0') * 10 % 13]
*/

int main() {
    string S;
    cin >> S;
    dp[0][0] = 1;
    rep(i, S.size()) {
        int num = ((S[i] == '?') ? -1 : S[i] - '0');
        rep(j, 10) {
            if(num != -1 && num != j) continue;//'?'でない場合S[i] - '0'のときだけ
            for(int mod = 0; mod < 13; ++mod) {
                dp[i + 1][(mod * 10 + j)%mod] += dp[i][mod];//あまり5のやつは末尾に3足したらそりゃ(5 * 10 + 3) % 13にかわるわな
            }
        }
        rep(j, 13)
            dp[i + 1][j] = dp[i + 1][j] % MOD;
    }
    cout << dp[S.size()][5] << endl;
}
