#include<iostream>
#include<vector>
#include<set>
#include<cmath>

using namespace  std;

#define ll long long

void prime(ll n){
 int flag = 1;
 for(int i=2;i<=sqrt(n);i++){
  if(n%i==0){
   flag=0;
   break;
  }
 }
  if(flag){
   cout<<"Prime"<<endl;
  }else{
   cout<<"NotPrime"<<endl;
  }
}


int main(){
 ll n;
 cin>>n;
 prime(n);
}

