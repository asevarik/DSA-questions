#include<bits/stdc++.h>
using namespace std;

//!Efficient Approach actually naive abhi mujhe hi samjh hi aai he so
//!time :o(n) space:o(1)
int maxProfit(int arr[],int n){
    int profit=0;
    for (int i = 1; i < n; i++)
    {
        if(arr[i]>arr[i-1]){
            profit+=(arr[i]-arr[i-1]);
        }
    }
    return profit;
}

int main(){
    int arr[]={1,5,3,8,12};
    int n=5;
    cout<<maxProfit(arr,n);
}