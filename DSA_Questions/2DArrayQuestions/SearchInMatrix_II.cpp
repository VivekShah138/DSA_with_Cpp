#include<bits/stdc++.h>
using namespace std;
bool searchMatrixII(vector<vector<int>>& matrix, int target) 
{
    int m = matrix.size();
    int n = matrix[0].size();
    int row = 0;
    int column = n - 1;
    while(row < m && column >= 0)
    {
        if(target == matrix[row][column])
        {
            return true;
        }   
        else if(target > matrix[row][column])
        {
            row++;
        }
        else
        {
            column--;
        }
    }
    return false;
}
int main()
{
    vector<vector<int>>matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    if(searchMatrixII(matrix,25))
    {
        cout << "Found " << endl;
    }
    else
    {
        cout << "Not Found " << endl;
    }
    return 0;
}