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
#include<cmath>
#include<climits>


using namespace std;

int main(){
  int t;
  cin>>t;
  while(t-- > 0){
   int n;
   cin>>n;
   int a[n+1];
   for(int i=0;i<n;i++){
     cin>>a[i];
   }
   a[n]=INT_MIN;
   int ans = 0;
   int max = INT_MIN;

   for(int i=0;i<n;i++){
      if(a[i]>max&&a[i]>a[i+1]){
       ans++;
      }
      if(a[i]>max){
       max = a[i];
      }
   }

   cout<<ans<<endl;
  }
}