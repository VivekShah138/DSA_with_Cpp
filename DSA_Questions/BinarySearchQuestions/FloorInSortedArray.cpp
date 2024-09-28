#include<bits/stdc++.h>
using namespace std;
// Time Complexity N
int findFloor(vector<long long> &v, long long n, long long x) 
{
    // Your code here
    int ans = -1;
    for(int i = 0;i < n; i++)
    {
        if(x >= v[i])
        {
            ans = i;
            cout << i << endl;
        }
        else
        {
            return ans;
        }
    }
    return ans;
}
// Time Complexity Log N
int findFloor2(vector<long long> &v, long long n, long long x) {

        // Your code here
        int start = 0;
        int end = n-1;

        if(v[end] <= x)
        {
            return end;
        }
        if(v[start] > x)
        {
            return -1;
        }
        int mid = start + (end - start)/2;
        while(start < end)
        {
            if(v[mid] <= x)
            {
                start = mid + 1;
            }
            else
            {
                end = mid;
            }
            mid = start + (end - start)/2;
        }
        return start-1;
    }

// Time Complexity Log N (Little bit Optimized)
int findFloor3(vector<long long> &v, long long n, long long x) 
{

        // Your code here
        int start = 0;
        int end = n-1;
        int mid = start + (end - start)/2;
        while(start <= end)
        {
            if(v[mid] == x)
            {
                return mid;
            }
            else if(v[mid] < x)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
            mid = start + (end - start)/2;
        }
        return end;
}
int main()
{
    vector<long long >arr = {35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113};
    vector<long long >arr2 = {1,3,4,5};
    long long x;
    cin >> x;
    int floorIndex = findFloor2(arr2,arr2.size(),x);
    cout << "FLoor of provided number is present at " << floorIndex << " index." << endl;

}