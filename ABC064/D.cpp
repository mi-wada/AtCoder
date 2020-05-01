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
#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl
/* -- template -- */

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int cntL = 0, cntR = 0;
    rep(i, N) {
        if(S[i] == ')') {
            if(cntR > 0)
                --cntR;
            else
                ++cntL;
        }else if(S[i]== '(') {
            ++cntR;
        }
    }
    rep(i, cntL) {
        S = '(' + S;
    }
    rep(i, cntR) {
        S = S + ')';
    }
    cout << S << endl;
}
