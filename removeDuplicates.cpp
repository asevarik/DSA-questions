#include <bits/stdc++.h>
using namespace std;
//?important given that array is sorted
//!naive approach
//!time compexity:o(n) space compexity:o(n)
int removeDuplicates(int arr[],int n){
    //initialize temp array

    int temp[n];
    //insert first element in array because its the unique element by default  
    temp[0]=arr[0];
    //res is initialized for size of new array
    int res=1;
    for (int i = 1; i < n-1; i++)
    {
        //if element not present in temp array then inserting element in temp after that inserting the position
        if(temp[res-1]!=arr[i]){
            temp[res]=arr[i];
            res++;
        }
    }
    cout<<res;
        return res;
}
//!Efficient Solution
//!time complexity is o(n) space complexity:o(1)
int removeDuplicatesEfficient(int arr[],int n){
    int res=1;
    //instead of using an temporay array i have used the same array and impliment the above idea to save some space
    for (int i = 0; i < n-1; i++)
    {
        if(arr[res-1]!=arr[i]){
            arr[res]=arr[i];
            res++;
        }
    }
    cout<<res;
    return res;
}

int main()
{
    int arr[]={1,1,2,2,3,3};
    removeDuplicatesEfficient(arr,6);
    return 0;
}
