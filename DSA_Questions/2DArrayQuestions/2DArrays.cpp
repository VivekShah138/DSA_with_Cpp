#include<bits/stdc++.h>
using namespace std;
int main()
{
    int matrix[4][3] = {{1,2,3},{2,3,1},{3,2,1},{1,3,2}};
    int rows = 4;
    int columns = 3;
    cout << matrix[3][2] << endl;
    cout << "x-------------------------------------x" << endl;
    cout << "whole matrix " << endl;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}