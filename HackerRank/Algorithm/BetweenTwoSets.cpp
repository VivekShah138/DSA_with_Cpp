#include <bits/stdc++.h>
using namespace std;
int getTotalX(vector<int> a, vector<int> b) 
{
    vector<int>common(100,1);
    for(int i=0;i<a.size();i++)
    {
        for(int j=1;j<=100;j++)
        {
            if(j % a[i] == 0 && common[j-1] == 1)
            {
                common[j-1] = 1;
            }
            else
            {
                common[j-1] = 0;
            }
        }
    }

    for(int i=0;i<b.size();i++)
    {
        for(int j=1;j<=100;j++)
        {
            
            if((b[i] % j == 0) && (common[j-1] == 1))
            {
                common[j-1] = 1;
            }
            else
            {
                common[j-1] = 0;
            }
        }
    }
    
    int count = 0;
    for(int i : common)
    {
        if(i == 1)
        {
            count++;
        }
    }
    return count;
}

// Another Approach
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
int getTotalX2(vector<int>a,vector<int>b)
{
    int resultGCD = gcdArray(b);
    
    int resultLCM = lcmArray(a);
    int multiple = 0;
    int count = 0;
    while(multiple <= resultGCD)
    {
        multiple += resultLCM;
        if(resultGCD % multiple == 0)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    vector<int>a = {2,6};
    vector<int>b = {24,36};
    int count = getTotalX(a,b);
    cout << count << endl;
}
