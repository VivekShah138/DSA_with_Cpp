#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int maxRepeating(vector<int>&arr)
{
   unordered_map<int,int>frequency;
   for(int i = 0; i < arr.size(); i++)
   {
        auto it = frequency.find(arr[i]);
        if(it == frequency.end())
        {
            frequency.insert({arr[i],1});
        }
        else
        {
            it -> second++;
        }
   }
   int minVal = INT32_MAX;
   bool check = false;
   for(auto it = frequency.begin(); it != frequency.end(); it++)
   {
        if(it -> second > 1 && it -> first < minVal)
        {
            minVal = it -> first;
            check = true;
        }
   }
   if(check == false)
   {
        return 0;
   }
   else
   {
        return minVal;
   }
   
}
int main()
{
    vector<int>arr = {1,2,3};
    int maxRepeatingSolution = maxRepeating(arr);
    cout << maxRepeatingSolution << endl;
}