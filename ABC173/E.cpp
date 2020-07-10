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
    int n, k; cin >> n >> k;
    ll a[n]; rep(i, n) cin >> a[i];
    vector<ll> minus;
    vector<ll> plus;
    sort(a, a + n);
    ll num = 1;
    int zeroCount = 0;
    rep(i, n) {
        if(a[i] < 0) {
            num = num * a[i] % MOD;
            if(num > 0) {
                minus.pb(num);
                num = 1;
            }
        }else if(a[i] > 0){
            plus.pb(a[i]);
        }else {
            ++zeroCount;
        }
    }
    reverse(all(plus));
    ll multMinus[minus.size() + 1], multPlus[plus.size() + 1];
    multMinus[0] = 1, multPlus[0] = 1;
    rep(i, minus.size()) {
        multMinus[i + 1] = multMinus[i] * minus[i] % MOD;
    }
    rep(i, plus.size()) {
        multPlus[i + 1] = multPlus[i] * plus[i] % MOD;
    }
    ll ans = -INF;
    for(int i = 0; i < (k / 2) + 1; ++i) {
        if(i > minus.size() || k - 2 * i > plus.size()) continue;
        ans = max(ans, multMinus[i] * multPlus[k - 2 * i] % MOD);
    }
    if(k % 2 == 1 && plus.size() == 0) {
        rep(i, k) {
            ans = ans * a[n - 1 - i] % MOD;
        }
    }
    if(zeroCount > k / 2) {
        ans = 0;
    }
    cout << ans << endl;
}
