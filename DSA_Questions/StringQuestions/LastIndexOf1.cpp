#include<bits/stdc++.h>
using namespace std;
int lastIndex(string s)
{
    for(int i = s.length()-1; i >= 0; i--)
    {
        if(s[i] == '1')
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    string s = "1100";
    int lastIndexSolution = lastIndex(s);
    cout << lastIndexSolution << endl;
}