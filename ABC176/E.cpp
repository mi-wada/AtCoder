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
    int H, W, M; cin >> H >> W >> M;
    int h[M], w[M];
    vector<int> bomH(H, 0);
    vector<int> bomW(W, 0);
    map<Pint, bool> bomExist;
    rep(i, M) {
        cin >> h[i] >> w[i];
        --h[i];--w[i];
        bomExist[mp(h[i], w[i])] = true;
        bomH[h[i]]++;
        bomW[w[i]]++;
    }
    int maxH = 0, maxW = 0;
    int maxH_h = 0, maxW_w = 0;
    rep(i, H) {
        if(bomH[i] >= maxH) {
            maxH = max(bomH[i], maxH);
            maxH_h = i;
        }
    }
    vector<int> hs, ws;
    rep(i, H) {
        if(bomH[i] == maxH) {
            hs.pb(i);
        }
    }
    rep(i, W) {
        if(bomW[i] >= maxW) {
            maxW = max(bomW[i], maxW);
            maxW_w = i;
        }
    }
    rep(i, W) {
        if(bomW[i] == maxW) {
            ws.pb(i);
        }
    }

    for(int h : hs) {
        for(int w : ws) {
            if(!bomExist[{h, w}]) {
                cout << maxW + maxH << endl;
                return 0;
            }
        }
    }
    cout << maxH + maxW - 1 << endl;
}
