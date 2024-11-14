#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
    int i = m-1;
    int j = m+n-1;
    int k = n-1;
    while((i >= 0) && (k >= 0))
    {
        if(nums1[i] > nums2[k])
        {
            nums1[j--] = nums1[i--];
        }
        else if(nums1[i] <= nums2[k])
        {
            nums1[j--] = nums2[k--];
        }
    }
    while(k >=0 )
    {
        nums1[j--] = nums2[k--];
    }
}
void printArray(vector<int>&nums1)
{
    for(int i : nums1)
    {
        cout << i << " ";
    }
}
int main()
{
    vector<int>arr = {1,2,3,0,0,0};
    vector<int>arr2 = {1,2,3};
    merge(arr,3,arr2,3);
    printArray(arr);
}