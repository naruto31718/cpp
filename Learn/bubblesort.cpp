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

void bubblesort(int arr[],int n){
 for(int i=0;i<n;i++){
   for(int j=0;j<n-1;j++){
    if(arr[j]>arr[j+1]){
     int temp = arr[j];
     arr[j] = arr[j+1];
     arr[j+1] = temp;
    }
   }
 }
}

int main(){
 int arr[10];
 for(int i=0;i<10;i++){
  cin>>arr[i];
 }
 bubblesort(arr,10);
 for(int i=0;i<10;i++){
  cout<<arr[i]<<" ";
 }
}
