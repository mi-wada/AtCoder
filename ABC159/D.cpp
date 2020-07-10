#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define vi vector<int>
#define vivi vector<vi>
const int INF = 1<<29;
typedef long long int ll;

bool searched[200000];

int main(){
    int N;cin >> N;
    ll A[N], B[N];
    rep(i, N)B[i] = 0;
    rep(i, N){
        cin >> A[i];
        --A[i];
        B[A[i]] += 1;
    }
    ll ans = 0, tmpans = 0;
    rep(i, N){
        if(!searched[A[i]]){
            searched[A[i]] = true;
            tmpans += (B[A[i]] *(B[A[i]] - 1))/2;
        }
    }
    rep(i, N){
        cout << tmpans - (B[A[i]] *(B[A[i]] - 1))/2 + ((B[A[i]]-1) *(B[A[i]] - 2))/2<<endl;
    }
}
