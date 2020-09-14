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
    int n; cin >> n;
    string c; cin >> c;
    int rCount = 0, wCount = 0;
    rep(i, n) if(c[i] == 'R') ++rCount;
    wCount = n - rCount;
    int l = 0, r = n - 1;
    int ans = 0;
    while(1) {
        bool flg = true;
        if(c[l] == 'R') ++l, flg = false;
        if(c[r] == 'W') --r, flg = false;
        if(flg) {
            if(l < r) {
                ++l;
                --r;
                ++ans;
            } else {
                break;
            }
        }
    }

    cout << ans << endl;
}
