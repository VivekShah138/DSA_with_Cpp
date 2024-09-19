#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int binarySearch(int arr[],int start,int end,int key)
{

    while(start <= end)
    {
        int mid = start + (end - start)/2;
        if(arr[mid] == key)
        {
            return mid;
        }
        else if(arr[mid] < key)
        {
            start = mid  + 1;
        }
        else if(arr[mid] >= key)
        {
            end = mid - 1;
        }
    }
    return 0;
    
    
}
int main()
{
    int arr[10] = {10,11,12,13,14,15,16,17,18,19};
    int size = sizeof(arr)/sizeof(arr[0]);
    int key;
    cout << "Please enter the element to be found" << endl;
    cin >> key;
    int ansBinarySearch = binarySearch(arr,0,size-1,key);
    if(ansBinarySearch == 0)
    {
        cout << "Value not found" << endl;
    }
    else
    {
        cout << "value is present at " << ansBinarySearch << endl;
    }
}