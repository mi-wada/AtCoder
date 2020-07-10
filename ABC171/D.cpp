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
    int a[n];
    map<int, int> m;
    rep(i, n) cin >> a[i], m[a[i]]++;
    ll ans = 0;
    for(auto itr = m.begin(); itr != m.end(); ++itr) {
        ans += itr -> first * itr -> second;
    }
    int q; cin >> q;
    vector<ll> anses;
    rep(i, q) {
        int b, c; cin >> b >> c;
        ans -= m[b] * b;
        ans += m[b] * c;
        m[c] += m[b];
        m[b] = 0;
        anses.pb(ans);
    }
    rep(i, q) {
        cout << anses[i] << endl;
    }
}
