#include<bits/stdc++.h>
using namespace std;
//!naive solution time:o(n^2) space:o(1)
int maxsubarray(int arr[],int n){
    //in this approach i have calculated all the subarrays using inner for loop and i have calculated the overall sum of he problem 
    //so this solution is kinda slow due to presence of inner loop
    int res=arr[0];
    for (int i = 0; i < n; i++)
    {
        int curr_sum=arr[i];
        int curr_max=arr[i];
        for (int j = i; j <n; j++)
        {
            int index=(i+j)%n;
            curr_sum+=arr[index];
            curr_max=max(curr_max,curr_sum);
        }
        res=max(curr_max,res);
    }
    return res;
}

//this is the helper function which supports the optimised solution
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
//!optimised solution time:o(n) space:o(1)
int overallMaxsum(int arr[],int n){
    //idea is that i have didived the problem into 2 tasks first is finding the maximum sum of subarray which we'll be solved by 
    //kandane's algorithm (helper function in this case) and after that i have calculated the overall sum of the array and negate the values of it 
    //after that have calculated the maximum sum of the circular array and returned max of maximum sum and maximum circular sum 
    int max_normal=maximumsubarray1(arr,n);
    if(max_normal<0){
        return max_normal;
    }
    int arr_sum=0;
    for (int i = 0; i < n; i++)
    {
        arr_sum+=arr[i];
        arr[i]=-arr[i];
    }
    int max_circular=arr_sum+maximumsubarray1(arr,n);
    return max(max_normal,max_circular);
}

int main(){
int arr[]={-5,-3};
cout<<overallMaxsum(arr,2);
}