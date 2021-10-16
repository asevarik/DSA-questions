#include<iostream>
using namespace std;
//!naive solution time:o(n^2) space:o(1)
bool subarray(int arr[],int n,int given_sum){
    for(int i=0;i<n;i++){
        int sum=0;
        for (int j = i; j < n; j++)
        {
            sum+=arr[j];
        if(sum==given_sum){
            return true;
        }
        }
    }
    return false;
} 
bool subarray1(int arr[],int n,int given_sum){
    int curr_sum=arr[0];
    int s=0;
    for (int e = 1; e < n; e++)
    {
        while(curr_sum>given_sum&&s<e-1){
            curr_sum-=arr[s];
            s++;
        }
        if(curr_sum==given_sum){
            return true;
        }
        if(e<n){
            curr_sum+=arr[e];
        }
    }
    return (curr_sum==given_sum);
}

//driver code
int main(){
    int arr[]={1,4,20,3,10,5};
    if(subarray1(arr,6,4)){
        cout<<"yes";
    }else{
        cout<<"no";
    }
}