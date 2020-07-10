#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<iomanip>
#include<map>
#include<cstring>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define vi vector<int>
#define vivi vector<vi>
const int INF = int(1e9);
typedef long long int ll;

int main(){
    int X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;
    ll p[A + 1], q[B + 1], r[C + 1];
    p[A] = INF;
    q[B] = INF;
    rep(i, A)cin >> p[i];
    rep(i, B)cin >> q[i];
    rep(i, C)cin >> r[i];
    sort(p, p + A, greater<ll>());
    sort(q, q + B, greater<ll>());
    sort(r, r + C, greater<ll>());
    ll ans[X + Y + C];
    for(int i = 0;i < X;++i)
        ans[i] = p[i];
    for(int i = 0;i < Y;++i)
        ans[X + i] = q[i];
    for(int i = 0;i < C;++i){
        ans[X + Y + i] = r[i];
    }
    sort(ans, ans + X + Y + C, greater<ll>());
    ll sum = 0;
    for(int i = 0;i < X + Y;++i){
        sum += ans[i];
    }
    cout << sum << endl;
}
