#include <bits/stdc++.h>
using namespace std;
vector<int> gradingStudents(vector<int> grades) 
{
    for(int i=0;i<grades.size();i++)
    {
        if(((grades[i]+1) % 5 == 0) && (grades[i] >= 38))
        {
            grades[i] = grades[i]+1;
        }
        else if(((grades[i]+2) % 5 == 0) && (grades[i] >= 38))
        {
            grades[i] = grades[i]+2;
        }
        else 
        {
            grades[i] = grades[i];      
        }
    }
    return grades;
}
int main()
{
    vector<int>grades = {12,34,54,65,89};
    vector<int>gradingStudentsSolution = gradingStudents(grades);
    for(int i:gradingStudentsSolution)
    {
        cout << i << " ";
    }
    return 0;
}