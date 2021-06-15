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

bool pallindrome(char arr[],int n){
  for(int i=0;i<n;i++){
    if(arr[i]!=arr[n-1-i]){
     return false;
    }
  } 
  return true;
}

void largest_word_length(char arr[]){
  int i=0,currLen=0,maxLen=0;
  while(1){
   if(arr[i]==' '||arr[i]=='\0'){
    if(currLen>maxLen){
       maxLen = currLen;
    }
    currLen=0;
   }else{
    currLen++;
   }
   if(arr[i]=='\0'){
    break;
   }
   i++;
  }
  cout<<maxLen<<endl;
}

int main(){
 int n;
 cin>>n;
 char arr[n+1];
 cin>>arr;
 cout<<pallindrome(arr,n)<<endl;
}