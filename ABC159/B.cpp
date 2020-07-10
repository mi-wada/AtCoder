#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<map>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define vi vector<int>
#define vivi vector<vi>
const int INF = 1<<29;
typedef long long int ll;

bool isKaibun(string S){
    int size = S.size();
    bool ok = true;
    for(int i = 0;i < size/2;++i){
        if(S[i] != S[size - i - 1])ok = false;
    }
    return ok;
}
int main(){
    string S;cin >> S;
    bool flg = true;
    if(!isKaibun(S))flg = false;
    if(!isKaibun(S.substr(0, (S.size()-1)/2)))flg = false;
    if(!isKaibun(S.substr((S.size()+3)/2 - 1)))flg = false;
    cout << ((flg) ? "Yes" : "No");
}
