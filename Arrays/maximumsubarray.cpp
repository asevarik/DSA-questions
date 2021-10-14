#include<bits/stdc++.h>
using namespace std;

//!naive approach time:o(n^2) space:o(1)
int maximumsubarray(int arr[],int n){
    int res=0;
    for (int i = 0; i < n; i++)
    {
        int currentsum=0;
        for (int j = i; j < n; j++)
        {
            currentsum+=arr[j];
            res=max(currentsum,res);
        }
        
    }
    return res;
}
//!optimised approach time:o(n) space:o(1)
int maximumsubarray1(int arr[],int n){
    //by default it is the largest sum of the array 
    int res=arr[0];
    int maxending=arr[0];//it will be treated as current sum
    for (int  i = 0; i < n; i++)
    {
        maxending=max(maxending+arr[i],arr[i]);
        res=max(res,maxending);
    }
    
    return res;
}

int main(){
    int arr[]={-5,1,-2,3,-1,2,-2};
    int n=7;
    cout<<maximumsubarray1(arr,n);
}