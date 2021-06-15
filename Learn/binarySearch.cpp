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

using namespace std;

int binarySearch(int low,int high,int arr[],int x){
 if(high>=low){
   int mid = (low+(high))/2;
   if(arr[mid]==x){
    return mid;
   }
   if(arr[mid]>x){
    return binarySearch(low,mid-1,arr,x);
   }else{
    return binarySearch(mid+1,high,arr,x);
   }
 }
 return -1;
}

int main(){
 int arr[1000];
 int n = sizeof(arr)/sizeof(arr[0]);
 for(int i=0;i<n;i++){
    arr[i]=i+1;
 }
 cout<<binarySearch(0,n-1,arr,466);
}