#include<bits/stdc++.h>
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

int main(){
    int arr[]={1,8,30,-5,20,7};
    int n=6;
    cout<<maxsum(arr,n,3);
}