#include<bits/stdc++.h>
using namespace std;
void print(int matrix[][3],int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Time complexity o(n*n)
int DiagonalSum(int matrix[][3],int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j)
            {
                sum += matrix[i][j];         
            }
            else if(j == n-i-1)
            {
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}
// Time complexity o(n*n)
int DiagonalSum2(int matrix[][3],int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += matrix[i][i];
        sum += matrix[i][n-i-1];
    }
    if(n % 2 != 0)
    {
        sum -= matrix[n/2][n/2];
    }
    return sum;
}
int main()
{
    int matrix[4][3] = {{1,2,3},{4,5,6},{9,8,7}};
    int n = 3;
    cout << " matrix is " << endl;
    print(matrix,n);
    cout << DiagonalSum(matrix,n) << endl;
    cout << DiagonalSum2(matrix,n) << endl;
}