#include <bits/stdc++.h>
using namespace std;
void sort01(vector<int>& arr)
{
    int start = 0;
    int end = arr.size() - 1;
    while(start <= end)
    {
        if(arr[start] == 0)
        {
            start++;
        }
        else
        {
            swap(arr[start++],arr[end--]);
        }
    }
}
void printArray(vector<int>& arr)
{
    for(int i : arr)
    {
        cout << i << " ";
    }
}
int main()
{
    vector<int>arr = {0,1,1,1,1,0,0,0,0,0};
    sort01(arr);
    printArray(arr);
}