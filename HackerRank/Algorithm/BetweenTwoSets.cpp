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
int main()
{
    vector<int>a = {2,6};
    vector<int>b = {24,36};
    int count = getTotalX(a,b);
    cout << count << endl;
}
