#include<bits/stdc++.h>
using namespace std;

//!mycode + naive
//!time:o(n^2) space:o(1)
void leadercount(int arr[],int n){
    //my approach is simple i have selected one element from the array and traverse this element 
    //from rest of the elements on the right side if greater element found i have set flag as false
    //and break out of the inner loop of flag is true then i have simply print the element
    for (int i = 0; i < n; i++)
    {
        bool flag=true;
        for (int j = i+1; j < n; j++)
        {
            if(arr[i]<=arr[j]){
                flag=false;
                break;
            }
        }
        if(flag){
            cout<<arr[i]<<" ";
        }
    }
    
}

//!efficient approach
//!time complexity:o(n) space:o(1)
//!important:drawback of this methoed is it print the leader in reverse order
void leadercount1(int arr[],int n){
    int curr_leader=arr[n-1];
    cout<<curr_leader;
    for (int i = n-2; i >=0; i--)
    {
        //the approach is simple we have traversing the array from right side and updating the 
        //current leader if element is found in the right side of the array else ignore 
        if(curr_leader<arr[i]){
            curr_leader=arr[i];
            cout<<curr_leader<<" ";
        }
    }
    
}

//driver code
int main(){
    int arr[]={7,10,4,3,6,5,2};
    int n=7;
    leadercount1(arr,n);
}