#include<bits/stdc++.h>
using namespace std;

//!naive solution in depth was written in copy time:o(n^2) space:o(1)
int findMajority(int arr[],int n){
    for(int i=0;i<n;i++){
        int count=1;
        for (int j = i+1; j < n; j++)
        {
            if(arr[i]==arr[j]){
                count++;
            }
        }
        if(count>(n/2)){
            return i;
        }
    }
return -1;
}
//Efficient Solution moore's boording algorithm in copy me acche se samjhaya he 

int findMajority1(int arr[],int n){
    int res=0,count=1;
    //below for loop is used for finding the potential majority element from the array 
    //drawback of this problem is that it returns the random index of the potential majority element
    for (int  i = 0; i < n; i++)
    {
        if(arr[i]==arr[res]){
            count++;
        }else{
            count--;
        }
        if(count==0){
            count=1;
            res=i;
        }
    }
    count=0;
    for (int i = 0; i < n; i++)
    {
        if(arr[res]==arr[i]){
            count++;
        }
    }
    if(count<=(n/2)){
        return res;
    }
    return res;
}
//driver code
int main(){
    int arr[]={8,8,6,6,6,4,6};
    int n=7;
    cout<<findMajority(arr,n);
    cout<<findMajority1(arr,n);
}