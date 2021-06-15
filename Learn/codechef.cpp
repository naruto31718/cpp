#include <iostream>
#include <vector>
#include<algorithm>
#include<math.h>
typedef signed long long ll;

using namespace std;

int main(){
  string won = "CONTEST_WON";
  string top = "TOP_CONTRIBUTOR";
  string bug = "BUG_FOUND";
  string host = "CONTEST_HOSTED";
  string india= "INDIAN";
  string notinida = "NON_INDIAN";
   int t;
   cin>>t;
   while(t-- >0){
     int n;
     string locality;
     cin>>n>>locality;
     int laddu=0,ans;
     while(n-- > 0){
       string s;
       cin>>s;
       if(s==won){
         int rank;
         cin>>rank;
         laddu+=300;
                if(rank<=20){ 
                    laddu+=20-rank;
                }
       }else if(s==top){
         laddu+=300;
       }else if(s==bug){
         int sev;
         cin>>sev;
         laddu+=sev;
       }else if(s==host){
          laddu+=50;
       }
     }
     if(locality==india){
       ans = laddu/200;
     }else{
       ans = laddu/400;
     }
     cout<<ans<<endl;
   }
}