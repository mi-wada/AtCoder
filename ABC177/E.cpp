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
int n;
const int N = pow(10,3) + 10;

vector<bool> isp(N+1, true);

void sieve() {
  isp[0] = false;
  isp[1] = false;
  for (int i=2; pow(i,2)<=N; i++) {
    if (isp[i]) for(int j=2; i*j<=N; j++) isp[i*j] = false;
  }
}

int gcd(int a, int b) {
    if(a % b == 0)return b;
    else return gcd(b, a % b);
}

int main() {
    cin >> n;
    vector<int> a;
    vector<int> b(n);
    map<int, int> m;
    bool pcflg = true, scflg = true;

    rep(i, n) {
        cin >> b[i];
        if(b[i] != 1) a.pb(b[i]);

        m[b[i]]++;
        if(m[b[i]] > 1 && b[i] != 1) pcflg = false;
    }
    sieve();
    vector<int> primes;
    for(int i = 2; i <= N; ++i) if(isp[i]) primes.pb(i);
    if(primes.size() < a.size()) pcflg = false;
    if(pcflg) {
        rep(i, primes.size()) {
            int cnt = 0;
            rep(j, a.size()) {
                if(a[j] % primes[i] == 0) ++cnt;
            }
            if(cnt > 1) {
                pcflg = false;
                break;
            }
        }
    }
    int tmp = b[0];
    rep(i, a.size()) {
        if(a[i] > tmp) tmp = gcd(a[i] , tmp);
        else tmp = gcd(tmp, a[i]);
    }
    if(tmp != 1) scflg = false;
    if(m[1] > 0) scflg = true;
    if(pcflg)cout << "pairwise coprime" << endl;
    else if(scflg) cout << "setwise coprime" << endl;
    else cout << "not coprime" << endl;
}
