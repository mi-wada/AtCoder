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

using ipair = pair<int,int>;
bool operator>(const ipair a,const ipair b){return a.first > b.first;};//演算子オーバーロード
const int ARRLEN = 2 * 1e5 + 10;
int main() {
    int N, Q; cin >> N >> Q;
     priority_queue<ipair,vector<ipair>> indergarten[ARRLEN];

    vector<int> student(N); //student[i] : 生徒iが今どこにいるか？
    rep(i, N) {
        int a, b; cin >> a >> b;
        student[i] = b;
        indergarten[a].push(mp(b, i));
    }
    vector<int> ans;
    /*
    rep(i, Q) {
        int c, d; cin >> c >> d;
        //幼児cが幼稚園dに移動
        //各幼児がどこにいるかをかくべき？
        ans.pb();
    }
    */

}
