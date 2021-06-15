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


void insertionSort(int arr[],int n){
   for(int i =1;i<n;i++){
    int curr = arr[i];
    int j=i-1;
    while(arr[j]>curr&&j>=0){
     arr[j+1]=arr[j];
     j--;
    }
    arr[j+1]=curr;
   }
}

int main(){
 int arr[10];
 for(int i=0;i<10;i++){
  cin>>arr[i];
 }
 insertionSort(arr,10);
 for(int i=0;i<10;i++){
  cout<<arr[i]<<" ";
 }
}