#include<bits/stdc++.h>
using namespace std;
void sort012Approach3(vector<int>& arr)
{
    int start = 0;
    int mid = 0;
    int end = arr.size() - 1;
    while(mid <= end)
    {
        if(arr[mid] == 1) 
        {
            mid++;
        }
        else if(arr[mid] == 0)
        {
            swap(arr[start++],arr[mid++]);
        }
        else
        {
            swap(arr[mid],arr[end--]);
        }
    }
}
void printArray(vector<int>& arr)
{
    cout << "Sorted Array" << endl;
    for(int i : arr)
    {
        cout << i << " ";
    }
}
int main()
{
    vector<int>arr = {1,0,2,1,0,2,1,0,2,1,0,2};
    sort012Approach3(arr);
    printArray(arr);
    return 0;
}