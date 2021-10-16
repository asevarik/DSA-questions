#include<iostream>
using namespace std;
//!naive method time:o(n^2) space:o(1)
int maxsum(int arr[],int n,int k){
    int res=INT16_MIN;
    for (int i = 0; i+k-1 < n; i++) //this condition is used to iterate the array till -5 (to prevent the extra )
    {
        int sum=0;
        for (int j= 0; j <k; j++) //this loops runs with j=0 beacuse we have to take three concecutive pairs sum if it's j=i then it'll never run to 3 paird so far 
        {
            sum+=arr[i+j]; //it'll do because we are initializing the j with zero while doing i+j we can access the right array elements at right place
        }
        res=max(res,sum);
    }
    return res;
}
//!optimised solution which uses sliding window 
//!time:o(n) space:o(1)
int maxconcecutivesum(int arr[],int n,int k){
    int curr_sum=0;
    //making the current sum to the size of the window 
    for (int i = 0; i < k; i++)
    {
        curr_sum+=arr[i];
    }
    //assiging the max_sum to the current sum 
    int max_sum=curr_sum;
    for (int i = k; i < n; i++)
    {
        //now to obtain the maximum sum we simply subtract the first element of the window and add another element to window and check
        //with the max_sum and return the res result
        curr_sum+=(arr[i]-arr[i-k]);
        max_sum=max(curr_sum,max_sum);
    }
    return max_sum;
    
}

int main(){
    int arr[]={1,8,30,-5,20,7};
    int n=6;
    cout<<maxconcecutivesum(arr,n,3);
}