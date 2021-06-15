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

bool isPermutation(vector<int> arr){
 sort(arr.begin(),arr.end());
 for(int i=0;i<arr.size();i++){
  if(arr[i]!=i+1){
   return false;
  }
 }
 return true;
}

int main(){
 int n,q;
 cin>>n>>q;
 vector<vector<int>> colours;
 vector<vector<int>> queries;
 vector<string> ans;
 for(int i=0;i<n;i++){
   vector<int> colour;
   int r,g,b;
   cin>>r>>g>>b;
   colour.push_back(r);
   colour.push_back(g);
   colour.push_back(b);
   colours.push_back(colour);
 }
 for(int i=0;i<q;i++){
   vector<int> query;
   int x,y,z;
   cin>>x>>y>>z;
   query.push_back(x);
   query.push_back(y);
   query.push_back(z);
   queries.push_back(query);
 }
  for(int i=0;i<queries.size();i++){
    int x = queries[i].at(0);
    int y = queries[i].at(1);
    int z = queries[i].at(2);
    bool x_true=false,y_true=false,z_true=false;
    for(int i=0;i<colours.size();i++){
      if(x==colours[i].at(0)){
        x_true=true;
      }
    }
    for(int i=0;i<colours.size();i++){
      if(y==colours[i].at(1)&&colours[i].at(0)>=x){
        y_true=true;
      }
    }
    for(int i=0;i<colours.size();i++){
      if(z==colours[i].at(2)&&colours[i].at(0)>=x&&colours[i].at(1)>=y){
        z_true=true;
      }
    }
    if(x_true&&y_true&&z_true){
      cout<<"YES"<<endl;
    }else{
      cout<<"NO"<<endl;
    }
  }
}