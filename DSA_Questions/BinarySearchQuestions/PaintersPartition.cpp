#include <bits/stdc++.h>
using namespace std;
bool isValid(int arr[],int n,int k,long long mid)
{
    int painters = 1;
    long long maxTime = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > mid)
        {
            return false;
        }
        if((maxTime + arr[i]) <= mid)
        {
            maxTime = maxTime + arr[i];
        }
        else
        {
            painters++;
            maxTime = arr[i];
        }
    }
    if(painters > k)
    {
        return false;
    }
    else
    {
        return true;
    }
}
long long minTime(int arr[], int n, int k)
{
    long long sum = 0;
    long long start = LONG_LONG_MIN;
    for(int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        start = max(start,(long long)arr[i]);
    }
    
    long long end = sum;
    long long ans = -1;
    while(start <= end)
    {
        long long mid = start + (end - start)/2;
        if(isValid(arr,n,k,mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}
int main()
{
    int arr[5] = {5,10,30,20,15};
    int n = 5;
    int k = 3;
    cout << minTime(arr,n,k) << endl;
    long long low = LONG_MIN;
}
