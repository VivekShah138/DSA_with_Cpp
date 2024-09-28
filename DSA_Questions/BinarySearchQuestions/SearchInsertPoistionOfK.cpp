#include<bits/stdc++.h>
using namespace std;
int searchInsertK(vector<int>&Arr,int N,int k)
{
    int start = 0;
    int end = N-1;
    int mid = start + (end - start)/2;
    while(start <= end)
    {
        if(Arr[mid] == k)
        {
            return mid;
        }
        else if(Arr[mid] < k)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return end + 1;
}
int main()
{
    vector<int >arr = {1,2,8,10,11,12,19};
    int k;
    cin >> k;
    int indexFound = searchInsertK(arr,arr.size(),k);
    cout << indexFound << endl;
}