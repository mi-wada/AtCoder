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
int arrayMax(int a[], const int N){
    int maxv = 0;
    rep(i, N)maxv = max(a[i], maxv);
    return maxv;
}
/* -- template -- */

int main(){
    int N;
    double M;cin >> N >> M;
    double sum = 0.0;
    double A[N];rep(i, N){cin >> A[i];sum += A[i];}
    int count = 0;
    rep(i, N)if(A[i] >= sum /(4.0 * M))++count;
    if(count >= M) cout << "Yes" << endl;
    else cout << "No" << endl;
}
