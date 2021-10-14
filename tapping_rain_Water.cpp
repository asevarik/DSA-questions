#include <bits/stdc++.h>
using namespace std;
//?solution is also explianed in depth in copy also please revisit this problems to learn them 
//!naive solution time:o(n^2) space comexity:o(1)
int tappinrainwater(int arr[],int n){
    int res=0;
    //beacuse water is not stored in corner towers 
    for (int i = 1; i < n-1; i++)
    {
        int lmax=arr[i];
        //used for finding the height of left most tower
        for (int j = 0; j < i; j++)
        {
            lmax=max(arr[j],lmax);
        }
        int rmax=arr[i];
        //used for finding the height of right most tower
        for (int j = i+1; j < n; j++)
        {
            rmax=max(arr[j],rmax);
        }
        res=res+(min(lmax,rmax)-arr[i]);
    }
    return res;
}

//!optimized solution time:o(n) space:o(n)
int OtappingrainwaterProblem(int arr[],int n){
    int res=0;
    int lmax[n],rmax[n];
    lmax[0]=arr[0];
    rmax[n-1]=arr[n-1];
    //below loops is for precalculating the max height of the towers
    for (int i = 1; i < n; i++)
    {
        lmax[i]=max(lmax[i-1],arr[i]);
    }
    for (int i = n-2; i >=0; i--)
    {
        rmax[i]=max(rmax[i+1],arr[i]);
    }
    for (int i = 1; i < n-1; i++)
    {
        res=res+(min(lmax[i],rmax[i])-arr[i]);
    }
    return res;
}

int main()
{
    int arr[]={5,0,6,2,3};
    int n=5;
    cout<<OtappingrainwaterProblem(arr,n);
    return 0;
}