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

void spiralPrint(int m, int n, int a[R][C])
{
    int i, k = 0, l = 0;
 
    /* k - starting row index
        m - ending row index
        l - starting column index
        n - ending column index
        i - iterator
    */
 
    while (k < m && l < n) {
        /* Print the first row from
               the remaining rows */
        for (i = l; i < n; ++i) {
            cout << a[k][i] << " ";
        }
        k++;
 
        /* Print the last column
         from the remaining columns */
        for (i = k; i < m; ++i) {
            cout << a[i][n - 1] << " ";
        }
        n--;
 
        /* Print the last row from
                the remaining rows */
        if (k < m) {
            for (i = n - 1; i >= l; --i) {
                cout << a[m - 1][i] << " ";
            }
            m--;
        }
 
        /* Print the first column from
                   the remaining columns */
        if (l < n) {
            for (i = m - 1; i >= k; --i) {
                cout << a[i][l] << " ";
            }
            l++;
        }
    }
}
 

int main(){
   int n,m;
   cin>>n>>m;
   int arr[n][m];
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
     cin>>arr[i][j];
    }
   }

   // int row_start=0,row_end=n-1,col_start=0,col_end=m-1;

   // while(row_start<=row_end && col_start<=col_end ){ 
   //  for(int col = col_start;col_start<=col_end;col++){
   //       cout<<arr[row_start][col]<<" ";
   //  }
   //  row_start++;
   //  for(int row = row_start;row<=row_end;row++){
   //   cout<<arr[row][col_end]<<" ";
   //  }
   //  col_end--;
   //  for(int col = col_end;col>=col_start;col--){
   //   cout<<arr[row_end][col]<<" ";
   //  }
   //  row_end--;
   //  for(int row = row_end;row>=row_start;row--){
   //   cout<<arr[row][col_start]<<" ";
   //  }
   //  col_start++;
   // }
   spiralPrint(n,m,arr);
}