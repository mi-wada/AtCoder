#include<iostream>
#include<vector>
#include<iomanip>
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


int main(){
    double L;cin >> L;
    cout << fixed<< setprecision(15)<<(L * L * L)/27.0;
}
