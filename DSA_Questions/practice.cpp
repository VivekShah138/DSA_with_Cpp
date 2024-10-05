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
// Time Complexity O(1)
// Space Complexity O(1)
int singleNonDuplicate3(vector<int>&nums)
{
    
}
int main()
{
    vector<int>arr = {1,1,2,2,3,3,4,5,5};
    int singleNonDuplicateElement = singleNonDuplicate2(arr);
    cout << singleNonDuplicateElement << endl;
}