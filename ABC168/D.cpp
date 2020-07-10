#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<set>
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

int main() {
    int N, M; cin >> N >> M;
    int A[M], B[M];
    vector<vector<int>>G(N);
    rep(i, M) {
        cin >> A[i] >> B[i];
        --A[i], --B[i];
        G[A[i]].pb(B[i]);
        G[B[i]].pb(A[i]);
    }
    queue<int>Q;
    Q.push(0);
    vector<P> dist(N, mp(INF, -1));
    dist[0] = mp(0, -1);
    while(!Q.empty()) {
        int q = Q.front(); Q.pop();
        for(int next : G[q]) {
            if(dist[next].first == INF) Q.push(next);
            if(dist[next].first > dist[q].first + 1) {
                dist[next] = mp(dist[q].first + 1, q + 1);
            }
        }
    }
    cout << "Yes" << endl;
    rep(i, N - 1) {
        cout << dist[i + 1].second << endl;
    }
}
