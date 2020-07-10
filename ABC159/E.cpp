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
    int H, W, K;cin >> H >> W >> K;
    char choco[H][W];
    int count = 0;
    for(int h = 0;h < H;++h){
        for(int w = 0;w < W;++w){
            cin >> choco[h][w];
            if(choco[h][w] == '1')++count;
        }
    }
    int ans = 0;
    while(count > K){
        count /= 2;
        ++ans;
    }
    cout << ans;
}
