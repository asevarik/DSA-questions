#include <bits/stdc++.h>
using namespace std;

//!naive solution
//!time comlexity o(nlog n)

int kthSmallest(int arr[], int n, int k)
{
    // Sort the given array
    sort(arr, arr + n);
 
    // Return k'th element in the sorted array
    return arr[k - 1];
}

//kth smallest element
//!time compexity:o(log n) avg and o(n) worst
int kthsmallestelementEfficient(int arr[],int n,int k){
    //set automatically sorts the element and stores them in a BST whose time compexity is o(log n) in avg case and o(n) in worst case
    set<int> s(arr, arr + n);
    set<int>::iterator itr
        = s.begin(); // s.begin() returns a pointer to first
                     // element in the set
   advance(itr, k - 1); // itr points to kth element in set
 
    return *itr ;
} 

int main()
{
 
    int arr[] = { 12, 3, 5, 7, 19 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    cout<<kthSmallest(arr,n,k);
    return 0;
}
 