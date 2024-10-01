#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
// N Square Time Complexity
int maxArea(vector<int>&height)
{
    int area = 0;
    for(int i = 0; i < height.size(); i++)
    {
        for(int j = i+1; j < height.size(); j++)
        {
            int h = min(height[i],height[j]);
            int w = j-i;
            int currentArea = h * w; 
            area = max(area,currentArea);
        }
    }
    return area;
}
// N Time Complexity
int maxArea2(vector<int>&height)
{
    int area = 0;
    int i = 0;
    int j = height.size()-1;
    while(i < j)
    {
        int w = j-i;
        int h = min(height[i],height[j]);
        int currentArea = w * h;
        area = max(currentArea,area);
        if(height[i] < height[j])
        {
            i++;
        }
        else if(height[j] <= height[i])
        {
            j--;
        }
    }
    return area;
}
//gfg
long long maxArea(long long A[], int len)
{
    // Your code goes here
    int area = 0;
    int i = 0;
    int j = len-1;
    while(i < j)
    {
        int w = j-i;
        int h = min(A[i],A[j]);
        int currentArea = w * h;
        area = max(currentArea,area);
        if(A[i] < A[j])
        {
            i++;
        }
        else if(A[j] <= A[i])
        {
            j--;
        }
    }
    return area;
}
int main()
{
    vector<int>arr = {1,8,6,2,5,4,8,3,7};
    int maxAreaSolution = maxArea2(arr);
    cout << maxAreaSolution << endl;
}