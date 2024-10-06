#include <bits/stdc++.h>
using namespace std;
bool isValid(int n,int m,int max,int arr[])
{
    int studentCount = 1;
    int pages = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > max)
        {
            return false;
        }
        if(pages + arr[i] <= max)
        {
            pages = pages + arr[i];
        }
        else
        {
            studentCount++;
            pages = arr[i];
        }
    }
    if(studentCount <= m)
    {
        return true; 
    }
    else
    {
        return false;
    }
}
long long findPages(int n, int arr[], int m) 
{
    if(m > n)
    {
        return -1;
    }
    long long sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    long long start = 0;
    long long end = sum;
    long long ans = -1;
    while(start <= end)
    {
        long long mid = start + (end - start)/2;
        if(isValid(n,m,mid,arr))
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
    int arr[4] = {2,1,3,4};
    int n = 4, m = 2;
    cout << findPages(n,arr,m);
}
