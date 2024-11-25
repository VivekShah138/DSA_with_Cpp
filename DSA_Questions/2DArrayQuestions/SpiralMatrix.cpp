#include<bits/stdc++.h>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix) 
{
    int m = matrix.size()-1; // rows
    int n = matrix[0].size()-1; // columns
    int sRow = 0;
    int eRow = m;
    int sColumn = 0;
    int eColumn = n;
    vector<int>solution;
    int j = 0;
    while(sRow <= eRow && sColumn <= eColumn)
    {
        // Top
        for(int i = sColumn; i <= eColumn; i++)
        {
            solution.push_back(matrix[sRow][i]);
        }

        // Right
        for(int i = sRow+1; i <= eRow; i++)
        {
            solution.push_back(matrix[i][eColumn]);
        }

        // Bottom
        for(int i = eColumn-1; i >= sColumn; i--)
        {
            if(sRow == eRow)
            {
                break;
            }
            solution.push_back(matrix[eRow][i]);
        }

        // Left
        for(int i = eRow-1; i >= sRow+1; i--)
        {
            if(sColumn == eColumn)
            {
                break;
            }
            solution.push_back(matrix[i][sColumn]);
        }
        sRow++;
        eRow--;
        sColumn++;
        eColumn--;
    }
    return solution;
}
int main()
{
    vector<vector<int>>matrix = {{1,2,3},{2,3,1},{3,2,1},{1,3,2}};
    return 0;
}