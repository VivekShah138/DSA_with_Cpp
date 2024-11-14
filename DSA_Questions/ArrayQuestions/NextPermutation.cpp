#include<bits/stdc++.h>
using namespace std;
int findPivot(vector<int>&nums)
{
    int pivot = -1;
    for(int i = nums.size()-2; i >= 0; i--)
    {
        if(nums[i] < nums[i+1])
        {
            pivot = i;
            break;
        }
    }
    return pivot;
}
int rightMostNumber(vector<int>&nums,int pivot)
{
    for(int i = nums.size()-1; i >= 0;i--)
    {
        if(nums[i] > nums[pivot])
        {
            return i;
        }
    }
    return -1;
}
void reverseArray(vector<int>& nums,int start,int end)
{
    while(start <= end)
    {
        swap(nums[start++],nums[end--]);
    }
}
void nextPermutation(vector<int>& nums) 
{
    int pivot = findPivot(nums);
    if(pivot == -1)
    {
        reverseArray(nums,0,nums.size()-1);
        return;
    }
    int rightMostElement = rightMostNumber(nums,pivot);
    swap(nums[pivot],nums[rightMostElement]);
    reverseArray(nums,pivot+1,nums.size()-1);
}
int main()
{
    vector<int>arr = {2,3,1};
    // cout << findPeakElement(arr) << endl;
    // reverseArray(arr,0,arr.size()-1);
    nextPermutation(arr);
    for(int i : arr)
    {
        cout << i << " ";
    }
    
}