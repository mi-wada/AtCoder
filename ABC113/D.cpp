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
#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

const int MAX_W = 9;
const int MAX_H = 101;

int dp[MAX_H][MAX_W]; // dp[h][w] : 高さhまで見たとき，wに行く通り数

void addMOD(int& a, int b) {
    a = (a + b)%MOD;
}

int main() {
    int H, W, K;
    cin >> H >> W >> K;
    dp[0][0] = 1; //初期条件
    rep(h, H) {
        for(int bit = 0; bit < (1 << (W - 1)); ++bit) {
            bool flg = true;
            rep(w, W - 2) {
                if(((1 << w) & bit) && ((1 << (w + 1)) & bit))
                    flg = false;
            }
            if(!flg)continue;
            rep(w, W) {
                if(((1 << (w - 1)) & bit) && w != 0) {
                    addMOD(dp[h + 1][w - 1], dp[h][w]);
                }else if(((1 << w) & bit) && w != W - 1) {
                    addMOD(dp[h + 1][w + 1], dp[h][w]);
                }else {
                    addMOD(dp[h + 1][w], dp[h][w]);
                }
            }
        }
    }
    cout << dp[H][K - 1] << endl;
}
