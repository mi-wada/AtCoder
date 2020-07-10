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
    string S;cin >> S;
    if(S[2] == S[3] && S[4] == S[5])
        cout << "Yes";
    else
        cout << "No";
}
