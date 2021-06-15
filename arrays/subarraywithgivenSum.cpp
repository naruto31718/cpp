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

int main(){
 int t;
 cin>>t;
 while(t-->0){
  int n,sum;
  cin>>n>>sum;
  int a[n];
  for(int i=0;i<n;i++){
   cin>>a[i];
  }
  int i=0,j=0,st=-1,en=-1,su=0;
  while(j<n&&sum>=su+a[j]){
   su+=a[j];
   j++;
  }
  if(sum==su){
   st=i+1;
   en=j;
  }
  while(j<n){
      su+=a[j];
      while(su>sum){
       su-=a[i];
       i++;
      }
      if(sum==su){
       st=i+1;
       en=j+1;
       break;
      }
      j++;
  }
  cout<<st<<" "<<en<<endl;
 }
}