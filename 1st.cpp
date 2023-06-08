#include <bits/stdc++.h>
using namespace std;
int largestSubarraySum1(vector<int>&v,int n){
    int maxSum=0;
    int cs=0;
    for(int i=0;i<n;i++){
        cs+=v[i];
        if(cs>maxSum){
            maxSum=cs;
        }
        if(cs<0){
            cs=0;
        }
        
    }
    return maxSum;
}
int binarySearch(vector<int>&v,int l,int h,int x){
    while(l<=r){
        int mid=l+(r-l)/2;
        if(v[mid]==x)
        return mid;
        if(arr[mid]<x)
        l=mid+1;
        else
        r=mid-1;
    }
      return -1;
}
int main() {
   
   int  n;

srand(time(0));

n = rand() % 100;

   vector<int>v(n,1);
   cout << "The Maximum Sum is: "<<largestSubarraySum1(v,n) << endl;
cout<<binarySearch(v,0,n,1);
    return 0;
}