#include <bits/stdc++.h>
using namespace std;
//!optimized solution time:o(n) space:o(1)
int concecutiveones(int arr[],int n){
    int count=0;
    int res=0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==1){
            count++;
            res=max(count,res);
            
        }else{
            count=0;
        }
    }
    return res;
}
//!naive solution time:o(n^2) space:o(1)
int concecutiveones1(int arr[],int n){
    int res=0;
    for ( int i = 0; i < n; i++)
    {
       int count=0;
    
        if(arr[i]==1){
            for (int j = i; j < n; j++)
        {
            if(arr[j]==1)count++;
            else break;
        }
        }
        res=max(res,count);    
        
    }
    return res;
}

int main()
{
    int arr[]={1,1,0,1,1,1,0,1,1,1};
    int n=10;
    cout<<concecutiveones(arr,n);    
}