#include<bits/stdc++.h>
using namespace std;
//time complexity:o(n) space:o(1)
//this problem has a dry run of it in the copy so please go through it and have something please refer to the video section i also have better understanding after 
//seen the video 
int minflips(int arr[],int n){
    int i;
    for(i=1;i<n;i++){
        if(arr[i]!=arr[i-1]){
            if(arr[i]!=arr[0]){
                cout<<"From"<<i<<"to";
            }else{
                cout<<(i-1)<<endl;
            }
        }
    }
    if(arr[n-1]!=arr[0]){
        cout<<i-1<<endl;
    }
    return 0;
}
//driver code
int main(){
    int arr[]={0,0,1,1,0,0,1,1,0,1};
    int n=10;
    minflips(arr,n);
}