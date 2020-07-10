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

int main() {
    int N; cin >> N;
    while(N > 0){
        if(N % 10 == 7){
            cout << "Yes" << endl;
            return 0;
        }
        N /= 10;
    }
    cout << "No" << endl;
}
//python3 makeDirectoryABC 160
