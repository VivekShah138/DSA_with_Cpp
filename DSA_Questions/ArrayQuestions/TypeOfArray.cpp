#include<bits/stdc++.h>
using namespace std;
int maxNtype(vector<int>&arr)
{
    int ans = 0;
    for(int i=1;i<arr.size()-1;i++)
    {
        if(arr[0] < arr[arr.size()-1])
        {
            ans = 1;
            if(arr[i] < arr[i-1])
            {
                ans = 3;
                return ans;
            }
        }
        else if(arr[0] > arr[arr.size()-1])
        {
            ans = 2;
            if(arr[i] < arr[i+1])
            {
                ans = 4;
                return ans;
            }
        }
    }
    return ans;
}
int main()
{
    vector<int>arr = {1,10,9,8,7,6,5,4,3,2};
    int type = maxNtype(arr);
    cout << type;
    
}