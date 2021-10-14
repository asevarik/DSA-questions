#include<bits/stdc++.h>
using namespace std;
//? important :that this prblem is also based on the kadan's algorithm 
//!naive solution time:o(n^2) space:o(1)
int concecutiveEvenOdd(int arr[],int n){
    int res=0;
    for (int i = 0; i < n; i++)
    {
        int curr=1;
        for (int j = i+1; j < n; j++)
        {
            //this logic is for alternating subarray
            if((arr[j]%2==0&&arr[j-1]%2!=0)||(arr[j]%2!=0&&arr[j-1]%2==0))curr++;
            else break;
        }
        res=max(curr,res);
    }
    return res;
}
//!optimized solution based on kadan'es algo time:o(n) space:o(1)
int concecutiveEvenOdd1(int arr[],int n){
    int res=0;
    int curr=0;
    for (int i = 1; i < n; i++)
    {
        if((arr[i]%2==0&&arr[i-1]%2!=0)||(arr[i]%2!=0&&arr[i-1]%2==0)){
            curr++;
            res=max(res,curr);
        }
        else curr=1;
        
    }
    return res;
}

int main(){
    int arr[]={5,10,20,6,3,8};
    int n=6;
    cout<<concecutiveEvenOdd1(arr,n);
}