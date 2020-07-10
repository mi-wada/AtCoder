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
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const ll LLINF = 1LL<<60;

ll digit(ll K) {
    ll ret = 0;
    while(K > 0) {
        K /= 2LL;
        ++ret;
    }
    return ret;
}

int main() {
    ll N;ll K; cin >> N >> K;
    ll A[N];
    ll ans = 0;
    ll ans2 = 0, ans3 = 0;
    rep(i, N){
        cin >> A[i];
        ans += A[i];
        ans2 += A[i];
        ans3 += A[i];
    }
    ll digitK = digit(K);
    for(ll i = 0; i < digitK - 1;++i) {
        ll sum = 0;
        rep(j, N) {
            ll mask = (1LL << i);
            if(mask & A[j]) {
                sum -= mask;
            }else {
                sum += mask;
            }
        }
        if(sum > 0){
            ans += sum;
        }
    }
    ll ssuumm = 0;
    for(ll i = digitK - 1; i >= 0;--i) {
        ll sum = 0;
        ssuumm += (1LL << i);
        if(ssuumm > K){
            ssuumm -= (1LL << i);
        }else{
            rep(j, N) {
                ll mask = (1LL << i);
                if(mask & A[j]) {
                    sum -= mask;
                }else {
                    sum += mask;
                }
            }
            if(sum > 0){
                ans2 += sum;
            }
        }
    }
    int k = -2;
    for(ll i = digitK - 3; i >= 0;--i) {
        if(!(K &(1LL << i))){
            k = i;
            break;
        }
    }
    for(ll i = digitK - 1; i >= 0;--i) {
        ll sum = 0;
        if(i > k + 1 && !((1 << i) & K)){
            continue;
        }
        else if(i != k + 1){
            rep(j, N) {
                ll mask = (1LL << i);
                if(mask & A[j]) {
                    sum -= mask;
                }else {
                    sum += mask;
                }
            }
            if(sum > 0){
                ans3 += sum;
            }
        }
    }

    cout << max(max(ans, ans2), ans3) << endl;
}
