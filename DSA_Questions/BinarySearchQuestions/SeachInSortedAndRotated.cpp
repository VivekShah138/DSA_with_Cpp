#include<bits/stdc++.h>
using namespace std;
int binarySearch2(int start,int end,int key,vector<int>&arr)
{
    int mid = start + (end - start)/2;
    while(start <= end)
    {
        if(arr[mid] == key)
        {
            return mid;
        }
        else if(arr[mid] > key)
        {
            end = mid-1;
        }
        else if(arr[mid] < key)
        {
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    return -1;
}
int findPivot(vector<int> &arr)
{
    int start = 0;
    int end = arr.size()-1;
    int mid = start + (end - start)/2;
    while(start < end)
    {
        if(arr[mid] >= arr[0])
        {
            start = mid  + 1;
        }
        else if(arr[mid] < arr[0])
        {
            end = mid;
        }
        mid = start + (end - start)/2;
    }
    return start;
}
int findNumber(vector<int>&arr,int key)
{
    int pivot = findPivot(arr);
    if(arr[pivot] <= key && key <= arr[arr.size()-1])
    {
        int ans = binarySearch2(pivot,arr.size()-1,key,arr);
        return ans;
    }
    else
    {
        int ans = binarySearch2(0,pivot-1,key,arr);
        return ans;
    }
}
int main()
{
    vector<int>arr = {13,14,15,16,17,1,2,3,4,5,6,7,8,9,10,11,12};
    int searchedNumber;
    cin >> searchedNumber;
    int pivotIndex = findPivot(arr);
    int pivotElement = arr[pivotIndex];
    cout << "Array is " ;
    for(int i:arr)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "The pivot is " << pivotElement << " At index " << pivotIndex << endl;
    int numberFoundAt = findNumber(arr,searchedNumber);
    if(numberFoundAt == -1)
    {
        cout << "Number not present" << endl;
    }
    else
    {
        cout << "Number is present at " << numberFoundAt << endl;
    }
}