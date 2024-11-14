#include <bits/stdc++.h>
using namespace std;
bool isValid(vector<int>&arr, int mid, int m)
{
    sort(arr.begin(),arr.end());
    int latestPosition = arr[0];
    int count = 1;
    for(int i = 1; i < arr.size();i++)
    {
        if((arr[i] - latestPosition) >= mid)
        {
            latestPosition = arr[i];
            count++;
        }
        if(count == m) return true;
    }
    return false;
}
int maxDistance(vector<int>& position, int m) 
{
    int maxVal = INT32_MIN;
    int minVal = INT32_MAX;
    for(int i : position)
    {
        maxVal = max(i,maxVal);
        minVal = min(i,minVal);
    }

    int start = 1;
    int end = maxVal - minVal;    
    int ans = 0;
    while(start <= end)
    {
        int mid = start + (end - start)/2;
        if(isValid(position,mid,m))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }   
    return ans;
}
int main()
{
    vector<int>arr = {1,2,8,9,4};
    cout << maxDistance(arr,3);
}
