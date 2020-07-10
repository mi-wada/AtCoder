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
    ll N, A, B, C;
    cin >> N >> A >> B >> C;
    int cntAB = 0, cntAC = 0, cntBC = 0;
    string s[N];
    rep(i, N) {
        cin >> s[i];
        if(s[i] == "AB") {
            --A;
            --B;
            ++cntAB;//ABどちらか選んでプラス2できる
        }else if(s[i] == "AC") {
            --A;
            --C;
            ++cntAC;
        }else {
            --B;
            --C;
            ++cntBC;
        }
    }
    vector<char> AB;
    vector<char> AC;
    vector<char> BC;
    for(int i = N - 1; i >= 0; --i) {
        if(s[i] == "AB") {
            if(A < B) {
                A += 2;
                AB.pb('A');
            }else {
                B += 2;
                AB.pb('B');
            }
        }else if(s[i] == "AC") {
            if(A < C) {
                A += 2;
                AC.pb('A');
            }else {
                C += 2;
                AC.pb('C');
            }
        }else {
            if(B < C) {
                B += 2;
                BC.pb('B');
            }else {
                C += 2;
                BC.pb('C');
            }
        }
    }

    if(A < 0 || B < 0 || C < 0) {
        cout << "No" << endl;
    }else {
        cout << "Yes" << endl;
        int ab = AB.size() - 1, ac = AC.size() - 1, bc = BC.size() - 1;
        rep(i, N) {
            if(s[i] == "AB") {
                cout << AB[ab] << endl;
                --ab;
            }else if(s[i] == "AC") {
                cout << AC[ac] << endl;
                --ac;
            }else {
                cout << BC[bc] << endl;
                --bc;
            }
        }
    }
}
