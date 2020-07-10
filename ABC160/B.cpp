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
    ll X;cin >> X;
    ll ans = 0;
    ans += ll(X/500) * 1000;
    ans += ll((X % 500) / 5) * 5;
    cout << ans;
}
