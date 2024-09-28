#include<bits/stdc++.h>
using namespace std;
int myPow(int x,int n)
{
    int ans = 1;
    while(n > 0)
    {
        int a = n & 1;
        if(a == 1)
        {
            ans = ans * x;
            x = x * x;
        }
        else
        {
            x = x * x;
        }
        n = n >> 1;
    }
    return ans;
}
double myPow2(double x,int n)
{
    if(x == 0) return 0;
    if(x == 1) return 1;
    if(n == 1) return x;
    if(n == 0) return 1;
    if(x==-1 && n%2==0) return 1.0;
    if(x==-1 && n%2!=0) return -1.0;
    
    long power = n;
    if(n < 0)
    {
        power = -power;
        x = 1 / x;
    }
    double ans = 1.0;
    while(power > 0)
    {
        int a = power & 1;
        if(a == 1)
        {
            ans = ans * x;
        }
        x = x * x;
        power = power >> 1;
    }
    return ans;
}
int main()
{
    int x,n;
    double x2;
    cout << "Enter the Number " << endl;
    cin >> x;
    cout << "Enter the Power " << endl;
    cin >> n;
    cout << "Enter the Number in Double " << endl;
    cin >> x2;
    int solution = myPow(x,n);
    double solution2 = myPow2(x2,n);
    cout << "Solution for power in Integer is " << solution << endl;
    cout << "Solution for power in Double is " << solution2 << endl;
}