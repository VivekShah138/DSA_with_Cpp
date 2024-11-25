#include<bits/stdc++.h>
using namespace std;
int maxRowSum(int matrix[][3],int rows,int columns)
{
    int sum = 0;
    for(int i = 0; i < rows; i++)
    {
        int rowSum = 0;
        for(int j = 0; j < columns; j++)
        {
            rowSum = rowSum + matrix[i][j];
        }
        sum = max(sum,rowSum);
    }
    return sum;
}
int maxColumnSum(int matrix[][3],int rows,int columns)
{
    int sum = 0;
    for(int j = 0; j < columns; j++)
    {
        int rowSum = 0;
        for(int i = 0; i < rows; i++)
        {
            rowSum = rowSum + matrix[i][j];
        }
        sum = max(sum,rowSum);
    }
    return sum;
}
int main()
{
    int matrix[4][3] = {{1,2,3},{20,20,20},{9,8,7},{10,11,12}};
    int rows = 4;
    int columns = 3;
    cout << maxRowSum(matrix,rows,columns) << endl;
    cout << maxColumnSum(matrix,rows,columns) << endl;
}