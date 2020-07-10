#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<iomanip>
#include<map>
#include<cstring>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;dependencies
using P = pair<int, int>;
const int INF = 1e9;
const ll LLINF = 4 * 1e18;
/* -- template -- */
int N, M;
int main() {
    scanf("%d %d", &N, &M);
    int ans = N * (N - 1) / 2 + M * (M - 1);
    printf("%d\n", ans);
    return 0;
}
