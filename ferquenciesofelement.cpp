#include<bits/stdc++.h>
using namespace std;
//!naive solution time:o(n^2) space o(1)
void frequencies(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        int count =1;
        for ( int j = i+1; j<n; j++)
        {
            if(arr[j]==arr[i]){
                count++;
                arr[j]=-1;
            }
        }
        if(arr[i]!=-1){
                cout<<"element"<<arr[i]<<" "<<count<<"\n";
    
        }
    }
    
}

//!efficient approach time:o(n) space=o(n)
void frequencies1(int arr[],int n){
    unordered_map<int,int> mp;
    int i;
    for ( i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    unordered_map<int,int>::iterator itr;
    for ( itr = mp.begin(); itr !=mp.end(); itr++)
    {
        cout<<itr->first<<" has repeated "<<itr->second<<" times \n";
    }
}

int main(){
    int arr[]={1,2,3,3,4,4,5,6,6};
    int n=9;
    frequencies1 (arr,n);
    return 0;
}