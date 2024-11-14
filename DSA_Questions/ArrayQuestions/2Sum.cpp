#include<bits/stdc++.h>
using namespace std;
// Time complexity O(n*n)
vector<int> twoSum(vector<int>& nums, int target) 
{
    vector<int>solution;
    for(int i = 0; i < nums.size(); i++)
    {
        for(int j = i+1; j < nums.size(); j++)
        {
            int sum = nums[i] + nums[j];
            if(sum == target)
            {
                solution.push_back(i);
                solution.push_back(j);
                return solution;
            }
        }
    }
}

// Using Two Pointers 
// Time Complexity O(nlogn) 
vector<int> twoSum2(vector<int>& nums, int target) 
{
    vector<int>solution;
    sort(nums.begin(),nums.end());
    int start = 0;
    int end = nums.size() - 1;
    while(start < end)
    {
        int sum = nums[start] + nums[end];
        if(target == sum)
        {
            solution.push_back(start);
            solution.push_back(end);
            return solution;
        }
        else if(sum < target)
        {
            start ++;
        }
        else
        {
            end --;
        }
    }
}

// Using Hashing
// Time Complexity O(n)
vector<int> twoSum3(vector<int>& nums, int target) 
{
    unordered_map<int,int>complement;
    vector<int>solution;
    for(int i = 0; i < nums.size(); i++)
    {
        int first = nums[i];
        int second = target - nums[i];

        auto it = complement.find(second);
        if(it != complement.end())
        {
            solution.push_back(i);
            solution.push_back(it->second);
            return solution;
            
        }
        complement.insert(make_pair(first,i));
    }
}

int main()
{
    vector<int> arr = {12,11,7,2};
    int target = 9;
    vector<int>solution = twoSum3(arr,target);
    for(int i : solution)
    {
        cout << i << " ";
    }
}