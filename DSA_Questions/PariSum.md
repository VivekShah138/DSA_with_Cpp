<b>PairSum</b><br>
<i>Explaination</i> : You are given an integer array 'ARR' of size 'N' and an integer 'S'. Your task is to return the list of all pairs of elements such that each sum of elements of each pair equals 'S'. <br>
<i>Input</i> : N=5,Sum=5,Array=1 2 3 4 5<br>
<i>Output</i> : 1 4, 2 3<br>
<i>Input</i> : N=5,Sum=0,Array=2 -3 3 3 -2<br>
<i>Output</i> : -3 3,-3 3,-2 2, <br>
```C++
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> PairSum(int arr[],int size,int sum)
{
    vector<vector<int>> Pairs;
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            
            if((arr[i] + arr[j]) == sum )
            {
                vector<int>temp;
                temp.push_back(arr[i]);
                temp.push_back(arr[j]);
                Pairs.push_back(temp);
            }
           
        }
    }
    sort(Pairs.begin(),Pairs.end());
    return Pairs;
}
int main()
{
    int arr[5]={1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    int sum;
    cin >> sum;
    vector<vector<int>> Pairs = PairSum(arr,size,sum);
    for(auto i:Pairs)
    {
        for(int j=0;j<i.size();j++)
        {
            cout << i[j] << " ";
        }
        cout << endl;
    }
}
```
<b> With Optimal Approach using two pointer approach</b><br>
Because the array is sorted we can compare the requiredSum with two pointers.
```C++
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
```
