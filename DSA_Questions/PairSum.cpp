#include<bits/stdc++.h>
using namespace std;
// N Square Complexity
vector<vector<int>> pairSum(int arr[],int size,int requiredSum)
{
    vector<vector<int>>pairs;
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(arr[i] + arr[j] == requiredSum)
            {
                vector<int>temp;
                temp.push_back(arr[i]);
                temp.push_back(arr[j]);
                pairs.push_back(temp);
            }
        }
    }
    return pairs;
}

// N Complexity
vector<vector<int>> pairSum2(int arr[],int size,int requiredSum)
{
    vector<vector<int>>pairs;
    int i = 0;
    int j = size-1;
    while(i<j)
    {
        if(arr[i] + arr[j] == requiredSum)
        {
            vector<int>temp;
            temp.push_back(arr[i]);
            temp.push_back(arr[j]);
            pairs.push_back(temp);
            i++;
            j--;
        }
        else if(arr[i] + arr[j] < requiredSum)
        {
            i++;
        }
        else if(arr[i] + arr[j] > requiredSum)
        {
            j--;
        }
    }
    return pairs;
}
int main()
{
    int arr[5] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    int requiredSum;
    cout << "Enter the required Sum" << endl;
    cin >> requiredSum;
    vector<vector<int>> requiredList = pairSum2(arr,size,requiredSum);
    for(auto i:requiredList)
    {
        for(int j=0;j<i.size();j++)
        {
            cout << i[j] << " ";
        }
        cout << endl;
    }
}