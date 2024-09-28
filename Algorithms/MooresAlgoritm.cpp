#include<bits/stdc++.h>
using namespace std;
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
    int majorityElementSolution = mooresAlogorithm(nums);
    cout << majorityElementSolution << endl;
}