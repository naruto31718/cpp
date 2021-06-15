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

void maxTill_ith_element(int arr[],int n){
 int max = arr[0];
 for(int i=0;i<n;i++){
  if(arr[i]>max){
   max  = arr[i];
  }
  cout<<max<<" ";
 }
}

int main(){
 int arr[5];
 for(int i=0;i<5;i++){
  cin>>arr[i];
 }
 maxTill_ith_element(arr,5);
}