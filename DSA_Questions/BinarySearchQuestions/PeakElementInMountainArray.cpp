#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int peakIndexInMountainArray(vector<int>& arr) 
{
    int start = 1;
    int end = arr.size()-2;
    int mid = start + (end - start)/2;
    while(start <= end)
    {
        if(arr[mid] < arr[mid+1])
        {
            start = mid+1;
        }
        else if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1])
        {
            return mid;
        }
        else 
        {
            end = mid-1;
        }
        mid = start + (end - start)/2;
    }
    return -1;
}
int main()
{
    vector<int>arr = {1,2,4,3};
    int peakIndex = peakIndexInMountainArray(arr);
    cout << peakIndex << endl;
}