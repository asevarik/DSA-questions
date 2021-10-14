#include<bits/stdc++.h>
using namespace std;
//helper function which rotates the array only one time 
void leftRotate(int arr[],int n){
    int temp=arr[0];
    for (int i = 0; i < n; i++)
    {
        arr[i]=arr[i+1];
    }
    arr[n-1]=temp;
}
//!Naive solution for rotating array d times
//!time compexity:theta(nd) time and space:o(1)
void leftrotateArrayKtimes(int arr[],int n,int d){
    for (int i = 0; i < d; i++)
    {
        leftRotate(arr,n);
    }
    
}
 
//!medium optimized solution for rotating array
//!time:0(n) and space:0(d)
void leftrotateArrayK1(int arr[],int n,int d){
    int temp[d],i;
    //copies d element from arr to temp
    for ( i = 0; i < d; i++)
    {
        temp[i]=arr[i];
    }
    //this is a bit tricky hope you understand that after putting d elements in temp array
    //from d(suppose d=2) and array ={1,2,3,4,5} so the d will bhi index 2 and we are 
    //shifting array from not one position but d (2nd position in this case )position
    for ( i = d; i < n; i++)
    {
        arr[i-d]=arr[i];
    }
    //after above operation this the array will look like {3,4,5,4,5}
    
    for ( i = 0; i < d; i++)
    {
        //we only copying the elements from temp array to normal array that's all 
        arr[n-d+i]=temp[i];
    }
    
}

//helper function to reverse the array
void reverse(int arr[],int low,int high){
    while (low<high)
    {
        swap(arr[low],arr[high]);
        low++;
        high--;
    }
    
}
//test array={1,2,3,4,5} d=2
//time:0(n),space:0(1)
void rotatearryktimes2(int arr[],int n,int d){
    //reverse array to d elements :{2,1,3,4,5}
    reverse(arr,0,d-1);//zero index he isiliye d-1 kiya he 
    //reverse the remaining elements:{2,1,5,4,3}
    reverse(arr,d,n-1);
    //reverse the whole array:{3,4,5,1,2} this is the required answer 
    reverse(arr,0,n-1);
}

int main()
{
int arr[]={1,2,3,4};
    rotatearryktimes2( arr,4,2);
for ( int i = 0; i < 4; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
    }