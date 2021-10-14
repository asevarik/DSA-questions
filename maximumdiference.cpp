#include<bits/stdc++.h>
using namespace std;

//maximum difference between elements of array i.e arr[j]-arr[i] where j>i;

//!naive solution time:o(n^2) space:o(n)
int maxdifference(int arr[],int n){
    int res=arr[1]-arr[0];
    for (int i = 1; i < n-1; i++)
    {
        for(int j=i+1;j<n;j++){
            res=max(res,arr[j]-arr[i]);
        }
    }
    return res;
}
//!effificient solution time:o(n) space:o(1)
int maxdifference1(int arr[],int n){
    int res=arr[1]-arr[0];
    int minval=arr[0];
    for(int j=1;j<n-1;j++){
        res=max(res,arr[j]-minval);
        minval=min(minval,arr[j]);
    }
    return res;
}

int main(){
    int arr[]={2,3,10,6,4,8,1};
    int n=7;
    cout<<maxdifference1(arr,n);
}
