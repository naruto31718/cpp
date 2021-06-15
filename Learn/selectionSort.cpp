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

void selctionSort(int arr [],int n){
  for(int i=0;i<n;i++){  
   for(int j=i+1;j<n;j++){
    if(arr[j]<arr[i]){
       int temp=arr[i];
       arr[i]=arr[j];
       arr[j]=temp;
    }
   }
  }
}

int main(){
 int arr[10];
 for(int i=0;i<10;i++){
  cin>>arr[i];
 }
 selctionSort(arr,10);
 for(int i=0;i<10;i++){
  cout<<arr[i]<<" ";
 }
}