#include<bits/stdc++.h>
using namespace std;
int findMin(vector<int> &arr)
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
    if(arr[start] > arr[0])
    {
        return arr[0];
    }
    else
    {
        return arr[start];
    }
    
}
int main()
{
    vector<int>arr = {4,5,1,2,3};
    int minElement = findMin(arr);
    cout << "Array is " ;
    for(int i:arr)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "The Minimum in sorted and rotated array is " << minElement << endl;
}