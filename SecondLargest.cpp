#include <bits/stdc++.h>
using namespace std;


//!finds the largest element
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
//!naive approach
//!time compexity :o(n)
int secondLargest(int arr[],int n){
    //geting largest element from the above function
    int largest=getLargestEfficient(arr,n);
    //initializing result for corner case if all elements are same like {10,10,10}
    int res=-1;
    for (int i = 0; i < n; i++)
    {
        //checking for elements which is not equal to largest element else ignore the element(eliminates the largest element as well it's duplicate like{20,20,16,10})
        if(arr[i]!=arr[largest]){
            //for first iteration res will set to 0 in this testing array
            if(res==-1){
                res=i;
            //applying same method for finding largest element
            }else if(arr[res]<arr[i]){
                res=i;
            }
        }
    }
    //returns the element
    return arr[res];
}

//!Efficient approach 
int secondLargestEfficient(int arr[],int n){
    //geting largest initialized to zero
    int largest=0;
    //initializing result for corner case if all elements are same like {10,10,10}
    int res=-1;
    for (int i = 0; i < n; i++)
    {
    //the approach is basically when largest element found we store the largest element in array and previous result in res (by default it'll be second largest)
        if(arr[i]>arr[largest]){
            res=largest;
            largest=i;
        }
        else if(arr[i]!=arr[largest]){
            if(res==-1 || arr[i]>arr[res]){
                res=i;
            }
            }
        }
    //returns the element
    return arr[res];
    }
     



//driver code
int main()
{
    int arr[]={2,14,1,3,16};
    cout<<secondLargestEfficient(arr,5);
}