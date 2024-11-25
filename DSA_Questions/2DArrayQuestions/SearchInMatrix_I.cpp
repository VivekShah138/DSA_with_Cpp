#include<bits/stdc++.h>
using namespace std;
bool searchInRow(vector<vector<int>>& matrix, int target,int mid)
{
    int row_start = 0;
    int row_end = matrix[mid].size()-1;
    while(row_start <= row_end)
    {
        int  row_mid = row_start + (row_end - row_start)/2;
        if(target == matrix[mid][row_mid])
        {
            return true;
        }
        else if(target > matrix[mid][row_mid])
        {
            row_start = row_mid + 1;
        }
        else
        {
            row_end = row_mid - 1;
        }
    }
    return false;
}
bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    int start = 0;
    int end = matrix.size()-1;
    while(start <= end)
    {
        int mid = start + (end - start)/2;
        if(target >= matrix[mid][0] && target <= matrix[mid][matrix[mid].size()-1])
        {
            return searchInRow(matrix,target,mid);
        }
        else if (target > matrix[mid][matrix[mid].size()-1])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return false;
}
int main()
{
    vector<vector<int>>matrix = {{1,3,5,7}};
    if(searchMatrix(matrix,1))
    {
        cout << "Found " << endl;
    }
    else
    {
        cout << "Not Found " << endl;
    }
    return 0;
}