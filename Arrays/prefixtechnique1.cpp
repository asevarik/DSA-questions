#include<iostream>
using namespace std;
static int arr[4];
//naive time:o(n) space:o(1)
int getSum(int arr[],int l,int r){
    int sum=0;
    for (int i = l; i <= r; i++)
    {
        sum+=arr[i];
    }
    return sum;
    
}
//helper function for optimised solution
void prefixarrmaker(int arr1[],int n){
    arr[0]=arr1[0];
    for (int i = 1; i <n; i++)
    {
        arr[i]=arr1[i]+arr[i-1];
    }
    
}
//!optimised solution time:o(1) space:o(1)
int getSum1(int l,int r){
    return arr[r]-arr[l-1];
}

int main(){
    int arr[]={2,8,10,20};
    // cout<<getSum(arr,0,1);
    prefixarrmaker(arr,4);
    cout<<getSum1(0,2);
}