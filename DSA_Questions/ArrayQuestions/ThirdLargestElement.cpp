#include<bits/stdc++.h>
using namespace std;
int thirdLargest(vector<int>&arr)
{
    if(arr.size() < 3)
    {
        return -1;
    }
    int max1 = INT32_MIN;
    int k1,k2;
    int max2 = INT32_MIN;
    int max3 = INT32_MIN;
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] > max1)
        {
            max1 = arr[i];
            k1 = i;
        }
    }
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] > max2 && i != k1)
        {
            max2 = arr[i];
            k2 = i;
        }
    }
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] > max3 && i != k1 && i != k2)
        {
            max3= arr[i];
        }
    }
    return max3;
}
int thirdLargest2(vector<int>&arr)
{
    if(arr.size() < 3)
    {
        return -1;
    }
    int max = INT32_MIN;
    int maxs = INT32_MIN;
    int maxt = INT32_MIN;
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] > max)
        {
            maxt = maxs;
            maxs = max;
            max = arr[i];
        }
        else if(arr[i] > maxs)
        {
            maxt = maxs;
            maxs = arr[i];
        }
        else if(arr[i] > maxt)
        {
            maxt = arr[i];
        }
    }
    return maxt;

}
int main()
{
    vector<int>arr = {1,2,3,4,5,6,7,8,9};
    int thirdLargestSolution = thirdLargest2(arr);
    cout << thirdLargestSolution << endl;
}