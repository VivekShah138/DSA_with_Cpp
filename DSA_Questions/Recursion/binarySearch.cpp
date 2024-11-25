#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int>arr, int start,int end,int key)
{
    int mid = start + (end - start)/2;
    if(start <= end)
    {
        if(arr[mid] == key) return mid;
        else if(arr[mid] > key) return binarySearch(arr,start,mid-1,key); 
        else return binarySearch(arr,mid+1,end,key); 
    }
    return -1;
    
}
int main()
{
    vector<int>arr = {1,2,3,4,5};
    cout << binarySearch(arr,0,arr.size()-1,6);
    return 0;
}
