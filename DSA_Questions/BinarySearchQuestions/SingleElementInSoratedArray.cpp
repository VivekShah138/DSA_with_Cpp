#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
// Time Complexity O(N)
// Space Complexity O(N)
int singleNonDuplicate(vector<int>& nums) 
{
    unordered_map<int,int>frequency;
    for(int i = 0; i < nums.size(); i++)
    {
        auto it = frequency.find(nums[i]);
        if(it == frequency.end())
        {
            frequency.insert({nums[i],1});
        }
        else
        {
            it -> second++;
        }
    }
    for(auto it = frequency.begin(); it != frequency.end(); it++)
    {
        if((it -> second) == 1)
        {
            return it -> first;
        }
    }
    return -1;        
}
// Time Complexity O(N)
// Space Complexity O(1)
// The structure of the algorithm involves a linear scan through the array. Even if you check fewer elements, the overall scan is still linear, and therefore, the time complexity remains O(N)
int singleNonDuplicate2(vector<int>&nums)
{
    int i = 0;
    while(i < nums.size()-1)
    {
        if(nums[i] != nums[i+1])
        {
            return nums[i];
        }
        i += 2;
        if(i == nums.size()-1 && nums[i] != nums[i-1])
        {
            return nums[i];
        }
    }
}
// Time Complexity O(Log N)
// Space Complexity O(1)
int singleNonDuplicate3(vector<int>&nums)
{
    if(nums.size() == 1) return nums[0];
    if(nums[0] != nums[1]) return nums[0];
    if(nums[nums.size()-1] != nums[nums.size()-2]) return nums[nums.size()-1];
    int start = 0;
    int end = nums.size()-1;
    
    while(start <= end)
    {
        int mid = start + (end - start)/2;
        if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
        {
            return nums[mid];
        }
        else if(mid % 2 == 0)
        {
            if(nums[mid] == nums[mid-1])
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else
        {
            if(nums[mid] == nums[mid-1])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
    return -1;
}
int main()
{
    vector<int>arr = {3,3,7,7,10,11,11};
    int singleNonDuplicateElement = singleNonDuplicate3(arr);
    cout << singleNonDuplicateElement << endl;
}