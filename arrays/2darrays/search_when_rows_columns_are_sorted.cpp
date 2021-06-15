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
   int n,m,k;
   cin>>n>>m>>k;
   int arr[n][m];
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
     cin>>arr[i][j];
    }
   }
   int r = 0;c=m-1;

   bool flag=false;

   while(r<n&&c>=0){
    if(arr[r][c]==k){
       flag=true;
       break;
    }else if(arr[r][c]>k){
     c--;
    }else{
     r++;
    }
   }

   if(flag){
    cout<<"Found"<<endl;
   }else{
    cout<<"NotFound"<<endl;
   }
}