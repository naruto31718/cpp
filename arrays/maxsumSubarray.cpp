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
#include<climits>


using namespace std;

int kadaneMaxsum(int arr[],int n){
 int currSum=0,maxSum = INT_MIN;
 for(int i=0;i<n;i++){
  currSum += arr[i];
  if(currSum<0){
   currSum = 0;
  }
  maxSum = max(currSum,maxSum);
 }
 return maxSum;
}

int maxSumwithWrap(int arr[],int n){
 int kadaneSum = kadaneMaxsum(arr,n);
 int totalSum = 0;
int maxSum = INT_MIN;
for(int i=0;i<n;i++){
 totalSum+=arr[i];
 arr[i]  = -arr[i];
}
totalSum += kadaneMaxsum(arr,n);
return max(totalSum,kadaneSum);
}

int main(){
 int n;
 cin>>n;
 int arr[n];
 // int currSum[n+1];
 for(int i=0;i<n;i++){
  cin>>arr[i];
 }
 // currSum[0] = 0;
 // for(int i=1;i<=n;i++){
 //  currSum[i] = currSum[i-1]+arr[i-1];
 // }
 // int maxSum = INT_MIN;

 // for(int i=1;i<=n;i++){
 //  int sum = 0;
 //  for(int j=0;j<n;j++){
 //   sum = currSum[i] - currSum[j];
 //   maxSum = max(sum,maxSum);
 //  }
 // }

 // cout<<maxSum<<endl;
 cout<<maxSumwithWrap(arr,n)<<endl;
}