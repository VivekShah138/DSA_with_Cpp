#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>>matrix = {{1,2,3},{2,3,1},{3,2,1},{1,3,2}};
    // int rows = matrix.size();
    // int columns = matrix[i].size();
    cout << matrix[3][2] << endl;
    cout << "x-------------------------------------x" << endl;
    cout << "whole matrix " << endl;
    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}