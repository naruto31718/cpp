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

int main(){
 int n,k;
 cin>>n>>k;
 vector<int> arr(n);
 for(int i=0;i<n;i++){
  cin>>arr[i];
 }
 sort(arr.begin(),arr.end());
 int low=0,high=n-1;
 
  while(high>=low){
   int sum = arr[low]+arr[high];
   if(sum==k){
    cout<<low<<" "<<high<<endl;
    break;
   } 
   if(sum>k){
    high-=1;
   }else{
    low+=1;
   }
  }
}