#include<bits/stdc++.h>
using namespace std;
bool linearSearch(int matrix[][3],int rows,int columns,int key)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            if(matrix[i][j] == key)
            {
                return true;
            } 
        }
    }
    return false;
}
pair<int,int>linearSearch2(int matrix[][3],int rows,int columns,int key)
{
    pair<int,int>solution(-1,-1);
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            if(matrix[i][j] == key)
            {
                solution.first = i;
                solution.second = j;
                return solution;
            } 
        }
    }
    solution.first = -1;
    solution.second = -1;
    return solution;
}
int main()
{
    int matrix[4][3] = {{1,2,3},{6,5,4},{9,8,7},{10,11,12}};
    int rows = 4;
    int columns = 3;
    int key = 8;
    if(linearSearch(matrix,rows,columns,key))
    {
        cout << "found " << endl;
    }
    else
    {
        cout << "Not Found " << endl;
    }
    pair<int,int>solution = linearSearch2(matrix,rows,columns,key);
    if(solution.first != -1 || solution.second != -1)
    {
        cout << " Key Found at " << solution.first << " row and " << solution.second << " column "<< endl;
    }
    else
    {
        cout << "key not found " << endl;
    }

}