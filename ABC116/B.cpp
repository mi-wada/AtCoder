#include<iostream>
#include<vector>
using namespace std;

int func(int x){
  if(x%2==1)
    return 3*x+1;
  else
    return x/2;
}

int issearch(int x){
}

int main(){
  int s;
  cin>>s;

  int a=s;

  int i=1;
  while(a!=4&&a!=2&&a!=1){
    a=func(a);
    i++;
  }

  cout<<i+3;
}
