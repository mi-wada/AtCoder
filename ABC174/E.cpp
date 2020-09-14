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

ll n, k;
vector<ll> a;
bool isCut(ll x) {
    //k回カットして，aの全ての要素をx以下にできるか？
    ll cnt = 0;
    for(int i = n - 1; i >= 0; --i) {
        if(a[i] <= x) continue;
        else if(a[i] % x == 0) cnt += a[i]/x - 1;
        else cnt += a[i] / x;
    }
    return (k >= cnt);
}

int main() {
    cin >> n >> k;
    a.resize(n);
    rep(i, n) cin >> a[i];
    sort(all(a));
    ll ng = 0, ok = a[n - 1] + 1;

    while(ng + 1 < ok) {
        ll mid = (ok + ng) / 2;
        if(isCut(mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << ok << endl;
}
