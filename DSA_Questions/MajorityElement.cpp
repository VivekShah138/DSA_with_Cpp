#include<bits/stdc++.h>
using namespace std;
// Time Complexity N sqaure
int majorityElement(vector<int>&nums)
{
    int m = nums.size()/2;
    for (int i = 0; i < nums.size(); i++)
    {
        int count = 0;
        for(int j = 0; j < nums.size(); j++)
        {
            if(nums[i] == nums[j])
            {
                count++;
            }
        }
        if(count > m)
        {
            return nums[i];
        }
    }
    return -1;
    
}
// Time Complexity logN
int majorityElement2(vector<int>&nums)
{
    // edge case
    if(nums.size() == 1)
    {
        return nums[0];
    }
    int m = nums.size()/2;
    sort(nums.begin(),nums.end());
    int count = 1;
    for(int i = 1; i < nums.size(); i++)
    {
        if(nums[i] == nums[i-1])
        {
            count++;
            if(count > m)
            {
                return nums[i];
            }
        }
        else
        {
            count = 1;
        }
    }
    return -1;
}
// Time Complexity N
int mooresAlogorithm(vector<int>&nums)
{
    int freqency = 0;
    int answer = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(freqency == 0)
        {
            answer = nums[i];
        }
        if(nums[i] == answer)
        {
            freqency++;
        }
        else
        {
            freqency--;
        }
    }
    return answer;
}
int main()
{
    vector<int> nums = {1,1,2,1,2,2,2};
    // int majorityElementSolution = majorityElement2(nums);
    int majorityElementSolution = mooresAlogorithm(nums);
    cout << majorityElementSolution << endl;
}