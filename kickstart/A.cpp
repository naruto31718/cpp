#include<iostream>
#include<set>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t-->0){
		int i=1;
		int n,k=0,r=0,c=0;
		cin>>n;
		int x[n][n];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>x[i][j];
			}
		}
		for(int i=0;i<n;i++){
    k+=x[i][i];
		}
		set<int> set;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
       if(set.find(x[i][j])==set.end()){
               set.insert(x[i][j]);
							}else{
								r++;
								break;
							}
			}
		}
		set.clear();
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
       if(set.find(x[j][i])==set.end()){
               set.insert(x[j][i]);
							}else{
								c++;
								break;
							}
			}
		}
		cout<<"case #"<<i<<":"<<k<<" "<<r<<" "<<c<<endl;

	}
}