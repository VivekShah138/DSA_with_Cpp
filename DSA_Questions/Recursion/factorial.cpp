#include <bits/stdc++.h>
using namespace std;
int factorial(int n)
{
    if(n == 0) return 1;
    return n * factorial(n-1);
}
void print(int n)
{
    if(n == 1)
    {
        cout << n << endl;
        return;
    }
    cout << n << " ";
    print(n-1);
}
int main()
{   
    print(10);
    // cout << endl;
    cout << factorial(4);
    return 0;
}
