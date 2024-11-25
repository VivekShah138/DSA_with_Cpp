#include <bits/stdc++.h>
using namespace std;
bool ifSorted(vector<int>arr, int size)
{
    if(size == 0 || size == 1) return true;
    return arr[size-1] >= arr[size-2] && ifSorted(arr,size-1);
}
int main()
{
    vector<int>arr = {1,2,3,4,5};
    cout << ifSorted(arr,arr.size());
    return 0;
}
