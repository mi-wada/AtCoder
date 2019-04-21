#include<iostream>
using namespace std;


int a[100];

int count1=0;

void sub(int r,int l){
  for(int i=r;i<l;i++)
    a[i]--;
}

int search(int l,int r){
  for(int i=l;i<r;i++){
    if(a[i]==0)return i;
  }
  return r;
}


void solve(int l,int r){
  if(l==r)return;
  if(search(l,r)==r){
    sub(l,r);
    count1++;
  }
  solve(l,search(l,r));
  solve(search(l,r)+1,r);
}

int main(){
  int N;
  cin>>N;
  for(int i=0;i<N;i++)cin>>a[i];

  solve(0,N);

  cout<<count1;
}
