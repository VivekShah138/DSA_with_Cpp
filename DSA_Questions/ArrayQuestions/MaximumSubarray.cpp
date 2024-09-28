#include<bits/stdc++.h>
using namespace std;
//Using Naive Approach with n square complexity.
int maxSubArraySum(int arr[],int size)
{
    int maxSum = INT32_MIN;
    
    for(int i=0;i<size;i++)
    {
        int currentSum = 0;
        for(int j=i;j<size;j++)
        {
            currentSum = currentSum + arr[j];
            maxSum = max(currentSum,maxSum);
        }
    }
    return maxSum;
}
int kandaneAlgo(int arr[],int size)
{
    int maxSum = INT32_MIN;
    int currentSum = 0;
    for(int i=0;i<size;i++)
    {
        currentSum = currentSum + arr[i];
        maxSum = max(currentSum,maxSum);
        if(currentSum < 0)
        {
            currentSum = 0;
        }
    }
    return maxSum;
}
int main()
{
    int arr[5] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    // int maxSum = maxSubArraySum(arr,size);
    int maxSum = kandaneAlgo(arr,size);
    cout << "Maximum Subarray Sum is " << maxSum << endl;
    vector<int>arr2;
    arr2.size();
}
