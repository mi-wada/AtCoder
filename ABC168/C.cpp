#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<cstring>
#include<iomanip>

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

int main() {
    double A, B, H, M;
    cin >> A >> B >> H >> M;
    double t1 = 360 * (H + M / 60) / 12, t2 = 360 * M / 60;
    if(t1 < t2) swap(t1, t2);
    double theta = (t1 - t2) * M_PI / 180.0;
    double ans = A * A + B * B - 2.0 * A * B * cos(theta);
    ans = sqrt(ans);
    cout << fixed << setprecision(18) << ans << endl;
}
