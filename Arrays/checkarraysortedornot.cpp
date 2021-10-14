#include <bits/stdc++.h>
using namespace std;
//! naive method
//!time compexity:o(n^2)
int isSorted(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
        if(arr[j]<arr[i]){
            cout<<"array is not sorted";
            return 0;
        }
        }
        
    }
    cout<<"array is sorted";
    return 1;
}



//!time compexity:o(n)
int isSortedefficient(int arr[],int n){
    for (int i = 0; i < n-1; i++)
    {
        if(arr[i]>arr[i+1]){
            cout<<"array is not sorted";
            return 0;
        }
    }
    cout<<"array is sorted";
    return 1;
}
int main()
{
    int arr[] = { 1,2,5,4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    isSorted(arr,n);
    return 0;
}