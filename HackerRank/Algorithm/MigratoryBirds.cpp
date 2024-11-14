#include<bits/stdc++.h>
using namespace std;
int migratoryBirds(vector<int> arr) 
{
    int realMax;
    vector<int>count(5,0);
    for(int i=0;i<arr.size();i++)
    {
        count[arr[i]-1]++;
    }
    int maxVal= INT32_MIN;
    for(int i = count.size()-1; i >= 0; i--)
    {
        if(maxVal <= count[i])
        {
            maxVal = count[i];
            realMax = i+1;
        }
    }
    return realMax;
}
int migratoryBirds2(vector<int>arr)
{
    int realMax;
    unordered_map<int,int>count;
    for(int i = 0; i < arr.size(); i++)
    {
        auto it = count.find(arr[i]);
        if(it == count.end())
        {
            count.insert(make_pair(arr[i],1));
        }
        else
        {
            it->second++;
        }
    }
    int maxVal= INT32_MIN;
    for(auto it = count.begin(); it != count.end(); it++)
    {
        if(maxVal < it->second)
        {
            maxVal = it->second;
            realMax = it->first;
        }
        else if(maxVal == it->second)
        {
            maxVal = it->second;
            realMax = min(realMax,it->first);
        }
    }
    return realMax;
}
int main()
{
    vector<int>arr = {1,1,2,2,3};
    int migratoryBirdsSolution = migratoryBirds2(arr);
    cout << migratoryBirdsSolution << endl;
}