#include <bits/stdc++.h>
using namespace std;

//Naive approach it choose oen element from the array and compare them to all the exsisting elements from the array 
//!overall time compexity :o(n^2)
int getLargest(int arr[],int n){
    for(int i=0;i<n;i++){
        bool flag=true;
        //this flag act a breaking point when largest element found in the array rather than a[i]
        for (int j = i; j < n; j++)
        {
            if(arr[i]<arr[j]){
                flag=false;
                break;
            }
        }
        if(flag==true){
            //returns the index of the array on which the element is located
            return i;
        }
        
    }
    //this block of code can never be executed because every array has a largest element
    return -1;
}


//!Efficient approach 
//!time complexity:theta(n)
int getLargestEfficient(int arr[],int n){
    //assuming that the largest element of the array reside at index 0 
    //then while traversing the array we are comparing the array with previous subarray largest element 
    int res=0;
    for (int i = 1; i < n; i++)
    {
        //if new element is largest than we update the res else we simply ignore the things 
        if(arr[res]<arr[i]){
            res=i;
        }
    }
    
    return res;
}


//driver code
int main()
{
    int arr[]={2,14,1,3,16};
    cout<<getLargestEfficient(arr,5);
}