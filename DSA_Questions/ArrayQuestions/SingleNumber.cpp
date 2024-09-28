#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int singleNumber(vector<int>&arr)
{
    int ans = 0;
    for(int i=0;i<arr.size();i++)
    {
        ans = arr[i] ^ ans;
    }
    return ans;
}
int main()
{
    vector<int>arr = {2,2,1};
    int singleNumberSolution = singleNumber(arr);
    cout << "Number Repeated Only Once is " << singleNumberSolution << endl;
}