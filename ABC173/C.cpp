#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<unordered_map>
#include<set>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1e18;
#define Pint pair<int, int>
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rnr(i,a,b) for(int i=int(a);i>=int(b);i--)
#define rep(i,b) rng(i,0,b)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    int h, w, k; cin >> h >> w >> k;
    string c[h];
    rep(i, h) {
        cin >> c[i];
    }
    int ans = 0;
    for(int wbit = 0; wbit < (1 << w); ++wbit) {
        for(int hbit = 0; hbit < (1 << h); ++hbit) {
            vector<bool>www(w, false);
            vector<bool>hhh(h, false);
            rep(i, w) {
                if(wbit & (1 << i)) {
                    www[i] = true;
                }
            }
            rep(i, h) {
                if(hbit & (1 << i)) {
                    hhh[i] = true;
                }
            }
            string tmp[h];
            rep(i, h) tmp[i] = c[i];
            rep(i, h) {
                rep(j, w) {
                    if(www[j] || hhh[i]) {
                        tmp[i][j] = '.';
                    }
                }
            }
            int cnt = 0;
            rep(i, h) {
                rep(j, w) {
                    if(tmp[i][j] == '#') ++cnt;
                }
            }
            if(cnt == k) ++ans;
        }
    }
    cout << ans << endl;
}
