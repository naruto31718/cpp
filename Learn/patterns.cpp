#include<iostream>
#include<vector>
using namespace std;
#define ll long long

void rectangle(ll l,ll b){
 for(ll i=0;i<l;i++){
  for(ll j=0;j<b;j++){
   cout<<'*'<<" ";
  }
  cout<<"\n";
 }
}

void hollowRectangle(ll l,ll b){
 for(int i=1;i<=l;i++){
  for(int j=1;j<=b;j++){
   if(i==1||i==l||j==1||j==b){
    cout<<'*'<<" ";
   }else{
    cout<<" ";
   }
  }
  cout<<"\n";
 }
}

void invertedHalfPyramid(ll n){
 for(int i=1;i<=n;i++){
   for(int j=1;j<=n;j++){
    if(j<=n-i){
     cout<<" ";
    }else{
     cout<<"*";
    }
 }
 cout<<"\n";
}
}

void invertedNumberPattern(ll n){
 ll count=1;
   for(int i=1;i<=n;i++){
    for(int j=1;j<=i;j++){
      if((i+j)%2 == 0){
       cout<<1;
      }else{
       cout<<0;
      }
    }
    cout<<endl;
   }
}

void rhombus(ll n){
 for(int i=1;i<=n;i++){
  for(int j=1;j<=n-i;j++){
   cout<<" ";
  }
  for(int j=1;j<=n;j++){
   cout<<"* ";
  }
  cout<<endl;
 }
}

void pallindrome(ll n){
    for(int i=1;i<=n;i++){
     for(int j=1;j<=n-i;j++){
      cout<<" ";
     }
     int k=i;
     for(int j=1;j<=i;j++){
      cout<<k--;
     }
     k = 2;
     for(int j=1;j<=i-1;j++){
      cout<<k++;
     }
     cout<<endl;
    }
}

void star(ll n){
  for(int i=1;i<=n;i++){
   for(int j=1;j<=n-i;j++){
    cout<<" ";
   }
   for(int j=1;j<=2*i-1;j++){
    cout<<"*";
   }
   cout<<endl;
  }
  for(int i=n;i>0;i--){
   for(int j=1;j<=n-i;j++){
    cout<<" ";
   }
   for(int j=1;j<=2*i-1;j++){
    cout<<"*";
   }
   cout<<endl;
  }
}

int main(){
 ll n;
 cin>>n;
star(n);
}