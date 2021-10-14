#include <bits/stdc++.h>
using namespace std;




//!my approach
//!Time complexity :o(n) space complexity:o(n)
void zerosToEnd(int arr[],int n){
    //i simply created the vector and pushed the non zero element to it and after that i have pushed 
    //it into the vector and copied the vector to original array and pushed zero after it 
    vector<int> v;
    int i;
    for (i = 0; i < n; i++)
    {
        if(arr[i]!=0){
            v.push_back(arr[i]);
        }
    }
    for ( i = 0; i < v.size(); i++)
    {
        arr[i]=v[i];
    }
    for(;i<n;i++){
        arr[i]=0;
    }

}

//!GFG naive solution 
//!time Complexity:o(n^2),space complexity:o(1)
void zerostoEnd1(int arr[],int n){
    //basic idea for this approach is when zero is encoutered we'll run the inner for loop until 
    //the non zero element is found if found then we'll perform swapping since inner loop runs to n-1 so time complexity is o(1)
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==0){
            for (int j= i+1; j < n; j++){
                if(arr[j]!=0){
                    swap(arr[i],arr[j]);
                }
            }
            
        }
    }
    
}

//!GFG optimized solution
//!Time Complexity:o(n) space:o(1)
void zerosToEnd2(int arr[],int n){
    //idea is to traverse through array once while doing that i have inilialized the count with zro which will
    //be used to swap with non zero element
    //once non zero element is encounterd than swapping occures with either with the same element(first iteration in this case)
    //if zero is encounterd than we simply ignore 
    int count=0;
    for (int i = 0; i < n; i++)
    {
    if(arr[i]!=0){
        //this check is implimented to prevent the extra swapping occures with the same element
        if(arr[i]==arr[count]){
            count++;
            continue;
        }
        swap(arr[count],arr[i]);
        count++;
    }
    }
    
}


int main()
{
int arr[]={1,0,2,0,0,3,4};
    zerosToEnd2(arr,7);
for ( int i = 0; i < 7; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
    }