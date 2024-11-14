#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    while(b != 0)
    {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}
int gcdArray(vector<int>arr)
{
    int result = arr[0];
    for(int i=0; i<arr.size(); i++)
    {
        // Minimum possible gcd can be 1
        if(result == 1)
        {
            return 1;
        }
        result = gcd(result,arr[i]);
    }
    return result;
}
int lcm(int a,int b)
{
    return (a*b) / gcd(a,b);
}
int lcmArray(vector<int>arr)
{
    int result = arr[0];
    for(int i=0; i<arr.size(); i++)
    {
        // Minimum possible lcm can be 0
        if(result == 0)
        {
            return 0;
        }
        result = lcm(result,arr[i]);
    }
    return result;
}
int main()
{
    vector<int>a = {2,6};
    vector<int>b = {24,36};
    int resultGCD = gcdArray(b);
    int resultLCM = lcmArray(a);
    cout << "GCD of given array is : " << resultGCD << endl;
    cout << "LCM of given array is : " << resultLCM << endl;
}
