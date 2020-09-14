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
    #define int ll
    int n; cin >> n;
    int a[n]; rep(i, n) cin >> a[i];
    vector<int> sum(n + 3, 0);
    for(int i = n - 1; i >= 0; --i) {
        sum[i] = (sum[i + 1] + a[i]) % MOD;
    }
    ll ans = 0;
    rep(i, n - 1) {
        ans = (ans + a[i] * sum[i + 1]) % MOD;
    }
    cout << ans << endl;
}
