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

int main() {
    int N;
    ll K;
    cin >> N >> K;
    int A[N];
    vector<vector<int>>G(N);
    rep(i, N) {
        cin >> A[i];
        G[i].pb(A[i] - 1);
    }
    queue<int>Q;
    Q.push(0);
    vector<ll>dist(N, INF);
    dist[0] = 0;
    bool flg = false;
    int loop = -1;
    while(!Q.empty()) {
        int q = Q.front();Q.pop();
        for(int next : G[q]) {
            if(dist[next] == INF) {
                dist[next] = dist[q] + 1;
                Q.push(next);
            }else if(dist[next] != INF){
                loop = next;
            }
        }
        if(loop != -1) break;
    }

    if(loop == -1) {
        ll maxv = 0;
        int maxv_i = -1;
        rep(i, N) {
            if(maxv <= dist[i]){
                maxv_i = i, maxv = dist[i];
            }
        }
        cout << maxv_i + 1 << endl;
    }else if(dist[loop] >= K) {
        rep(i, N) {
            if(K == dist[i])
                cout << i + 1 << endl;
        }
    }else {
        queue<int> nQ;
        nQ.push(loop);
        vector<ll>ndist(N, INF);
        ndist[loop] = 0;
        bool flg = false;
        while(!nQ.empty()) {
            int q = nQ.front();nQ.pop();
            for(int next : G[q]) {
                if(ndist[next] == INF) {
                    ndist[next] = ndist[q] + 1;
                    nQ.push(next);
                }else if(ndist[next] != INF){
                    ndist[next] = ndist[q] + 1;
                    flg = true;
                }
            }
            if(flg) break;
        }
        ll ans = (K - ll(dist[loop])) % ndist[loop];
        ndist[loop] = 0;
        rep(i, N) {
            if(ans == ndist[i])
                cout << i + 1 << endl;
        }
    }
}
