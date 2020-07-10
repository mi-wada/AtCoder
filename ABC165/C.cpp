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
#define print(x) cout << (x) << endl

class mint {
    long long x;
public:
    mint(long long x=0) : x((x%MOD+MOD)%MOD) {}
    mint operator-() const {
      return mint(-x);
    }
    mint& operator+=(const mint& a) {
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator-=(const mint& a) {
        if ((x += MOD-a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator*=(const  mint& a) {
        (x *= a.x) %= MOD;
        return *this;
    }
    mint operator+(const mint& a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint& a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint& a) const {
        mint res(*this);
        return res*=a;
    }
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
    // for prime MOD
    mint inv() const {
        return pow(MOD-2);
    }
    mint& operator/=(const mint& a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint& a) const {
        mint res(*this);
        return res/=a;
    }

    friend ostream& operator<<(ostream& os, const mint& m){
        os << m.x;
        return os;
    }
};

/* -- template -- */
int ansArray[11];
int d[11][11];
bool visited[11][11];
int main() {
    int N, M, Q; cin >> N >> M >> Q;
    pair<int, pair<int, pair<int, int> > > dabc[Q];
    rep(i, Q) cin >> (dabc[i].second).first >> ((dabc[i].second).second).first >> ((dabc[i].second).second).second >> dabc[i].first, d[(dabc[i].second).first][((dabc[i].second).second).first] = max(dabc[i].first, d[(dabc[i].second).first][((dabc[i].second).second).first]);
    /*
    rep(i, Q) {
        if(visited[(dabc[i].second).first][((dabc[i].second).second).first] == false){
            dabc[i].first = d[(dabc[i].second).first][((dabc[i].second).second).first];
            visited[(dabc[i].second).first][((dabc[i].second).second).first] = true;
        }else {
            dabc[i].first = 0;
        }
    }*/
    sort(dabc, dabc + Q);
    rep(i, 11)ansArray[i] = -1;
    int ans = 0;
    cout << endl;

    for(int i = Q - 1; i >= 0; --i) {
        int a = (dabc[i].second).first, b = ((dabc[i].second).second).first, c = ((dabc[i].second).second).second, d = dabc[i].first;
        if(ansArray[b - 1] == -1 && ansArray[a - 1] == -1) {
            ansArray[b - 1] = a + c;
            ansArray[a - 1] = a;
            ans += d;
        }else if(ansArray[b - 1] == -1 && ansArray[a - 1] != -1) {
            ansArray[b - 1] = ansArray[a - 1] + c;
            ans += d;
        }else if(ansArray[b - 1] != -1 && ansArray[a - 1] == -1) {
            ansArray[a - 1] = ansArray[b - 1] - c;
            ans += d;
        }else {
            if(ansArray[b - 1] - ansArray[a - 1] == c)
                ans += d;
        }
    }
    rep(i, Q){
        int a = (dabc[i].second).first, b = ((dabc[i].second).second).first, c = ((dabc[i].second).second).second, d = dabc[i].first;
        cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
    }

    cout << ans << endl;
}
