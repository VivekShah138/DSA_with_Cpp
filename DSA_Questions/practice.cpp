#include <bits/stdc++.h>
using namespace std;
int print(int n)
{
    int a = 0;
    int b = 1;
    int c;
    for(int i = 2;i <= n;i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}
int main()
{
    vector<int>arr = {5,4,3,4,2,1};
    for(auto i : arr)
    {
        cout << i << " ";
    }
    
    // cout << print(4);s
}
