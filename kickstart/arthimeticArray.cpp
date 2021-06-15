#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main(){
 int t;
 cin>>t;
 while(t-- >0){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
   cin>>arr[i];
  }
  int pd = arr[1]-arr[0];
  int ans = 0;
  int curr = 2;
  int j = 2;
  while(j<n){
   if(pd == arr[j]-arr[j-1]){
    curr++;
   }else{
    pd = arr[j]-arr[j-1];
    curr = 2;
   }
   j++;
   if(curr>ans){
    ans = curr;
   }
  }
  cout<<ans<<endl;
 }
}