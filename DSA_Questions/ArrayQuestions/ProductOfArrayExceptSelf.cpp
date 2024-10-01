#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
// Time Conplexity N square
vector<int>productExceptSelf(vector<int>& nums) 
{
    vector<int>solution;
    for(int i = 0;i < nums.size(); i++)
    {
        int product = 1;
        for(int j = 0;j < nums.size(); j++)
        {
            if(j != i)
            {
                product = product * nums[j];
            }
        }
        solution.push_back(product);
    }
    return solution;
}
// Time Complexity N  
// Space Complexity N
vector<int>productExceptSelf2(vector<int>&nums) 
{
    int n = nums.size();
    vector<int>solution(n,1);
    vector<int>prefix(n,1);
    vector<int>suffix(n,1);
    
    for(int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i-1] * nums[i-1];
    }
    for(int i = n-2; i >= 0; i--)
    {
        suffix[i] = suffix[i+1] * nums[i+1];   
    }
    for(int i = 0;i < n; i++)
    {
        solution[i] = prefix[i] * suffix[i];
    }
    return solution;
}
// Time Complexity N  
// Space Complexity 1
vector<int>productExceptSelf3(vector<int>&nums) 
{
    int n = nums.size();
    vector<int>solution(n,1);
    int prefix = 1;
    int suffix = 1;
    
    for(int i = 1; i < n; i++)
    {
        prefix = nums[i-1] * prefix;
        solution[i] = solution[i] * prefix;
    }
    for(int i = n-2; i >= 0; i--)
    {
        suffix = nums[i+1] * suffix;  
        solution[i] = solution[i] * suffix;
    }
    return solution;
}
int main()
{
    vector<int>arr = {1,2,3,4};
    vector<int> productExceptSelfSolution = productExceptSelf3(arr);
    for(int i : productExceptSelfSolution)
    {
        cout << i << " ";
    }
}