#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<iomanip>
#include<map>
#include<cstring>

using namespace std;

typedef long long int ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define vi vector<int>
#define vivi vector<vi>
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
/* -- template -- */

ll gcd(ll a, ll b) {
    if(b > a){
        swap(a, b);
    }
    if(b == 0)return a;
    return gcd(b, a % b);
}

int main() {
    int K; cin >> K;
    ll sum = 0;
    for(int i = 1;i <= K; ++i) {
        for(int j = 1;j <= K;++j) {
            for(int k = 1;k <= K;++k) {
                sum += gcd(gcd(i, j), k);
            }
        }
    }
    cout << sum << endl;
}
