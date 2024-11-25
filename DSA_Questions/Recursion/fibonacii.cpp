#include <bits/stdc++.h>
using namespace std;
int fibonacciWithoutRecursion(int n)
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
int fibonacciWithRecursion(int n)
{
    if(n == 0 || n == 1) return n;
    return fibonacciWithRecursion(n-1) + fibonacciWithRecursion(n-2);
}
int main()
{
    vector<int>arr = {5,4,3,4,2,1};
    
    cout << "WithoutRecursion " << fibonacciWithoutRecursion(4) << endl;
    cout << "WithRecursion " << fibonacciWithRecursion(4) << endl;
    return 0;
}