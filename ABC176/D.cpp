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

Pint dir[4] = {mp(0, 1), mp(1, 0), mp(-1, 0), mp(0, -1)};

int main() {
    int h, w; cin >> h >> w;
    int cH, cW, dH, dW;
    cin >> cH >> cW;
    cin >> dH >> dW;
    string s[h];
    rep(i, h) cin >> s[i];
    int dist[h][w];
    rep(i, h) {
        rep(j, w) {
            dist[i][j] = INF;
        }
    }
    vector<vector<Pint>> values(h * w);
    int value = 0;
    queue<Pint> que;
    dist[cH - 1][cW - 1] = 0;
    values[0].pb(mp(cH - 1, cW - 1));
    que.push(mp(cH - 1, cW - 1));
    while(!que.empty()) {
        Pint f = que.front(); que.pop();
        rep(i, 4) {
            int hi = dir[i].first + f.first, wi = dir[i].second + f.second;
            if(hi >= 0 && hi < h && wi >= 0 && wi < w) {
                if(s[hi][wi] == '.') {
                    if(dist[hi][wi] == INF) que.push(mp(hi, wi));
                    if(dist[hi][wi] > dist[f.first][f.second] && dist[f.first][f.second] == value) {
                        values[value].pb(mp(hi, wi));
                    }
                    dist[hi][wi] = min(dist[hi][wi], dist[f.first][f.second]);
                }
            }
        }

        if(que.empty()) {
            for(Pint v: values[value]) {
                rng(i, -2, 3) {
                    rng(j, -2, 3) {
                        int hi = v.first + i, wi = v.second + j;
                        if(hi >= 0 && hi < h && wi >= 0 && wi < w) {
                            if(s[hi][wi] == '.') {
                                if(dist[hi][wi] == INF) que.push(mp(hi, wi)), values[value + 1].pb(mp(hi, wi));
                                dist[hi][wi] = min(dist[hi][wi], 1 + dist[v.first][v.second]);
                            }
                        }
                    }
                }
            }
            ++value;
        }
    }
    cout << ((dist[dH - 1][dW - 1] == INF) ? -1 : dist[dH - 1][dW - 1]) << endl;
}
