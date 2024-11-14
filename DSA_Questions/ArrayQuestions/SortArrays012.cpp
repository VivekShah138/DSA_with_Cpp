#include <bits/stdc++.h>
using namespace std;
void sort012Approach1(vector<int>& arr) 
{
    sort(arr.begin(),arr.end()); 
}
void sort012Approach2(vector<int>& arr) 
{
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] == 0)
        {
            zeroCount++;
        }
        else if(arr[i] == 1)
        {
            oneCount++;
        }
        else
        {
            twoCount++;
        }
    }
    int index = 0;
    for(int i = 0; i < zeroCount;i++)
    {
        arr[index++] = 0;
    }
    for(int i = 0; i < oneCount; i++)
    {
        arr[index++] = 1;
    }
    for(int i = 0; i < twoCount; i++)
    {
        arr[index++] = 2;
    }
}
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
