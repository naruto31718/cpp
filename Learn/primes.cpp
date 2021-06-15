
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
 ll n;
 vector<ll> x;
 cin>>n;
 ll num=2;
 while(n>=num){
    ll div=2;
    bool flag=true;
    while(num>=div){
       if(num!=div&&num%div==0){
        flag=false;
        break;
       }else{
        div+=1;
       }
    }
    if(flag){
     x.push_back(num);
    }
    num++;
 }
 for(ll i:x){
  cout<<i<<" ";
 }
}