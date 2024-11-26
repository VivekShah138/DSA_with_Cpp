#include<bits/stdc++.h>
using namespace std;
// Creating new Array
int compress(vector<char>& chars) 
{
    vector<char>ans;
    int i = 1;
    char toBeMatch = chars[0];
    int count = 1;
    while(i < chars.size())
    {
        if(toBeMatch == chars[i])
        {
            count++;
        }
        else
        {
            ans.push_back(toBeMatch);
            if(count > 1)
            {
                string strCount = to_string(count);
                for(auto digit : strCount)
                {
                    ans.push_back(digit);
                }
                
            }
            toBeMatch = chars[i];
            count = 1;
        }
        i++;
    }
    ans.push_back(toBeMatch);
    if(count > 1)
    {
        string strCount = to_string(count);
        for(auto digit : strCount)
        {
            ans.push_back(digit);
        }
                
    }
    for(auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return ans.size();
}

// Inplace 
int compress2(vector<char>& chars) 
{
    int i = 0;
    int newIndex = 0;
    int n = chars.size();
    while(i < n)
    {
        int j = i + 1;
        while(j < n)
        {
            if(chars[j] == chars[i]) j++;
            else break;
        }
        int count = j - i;
        if(count == 1)
        {
            chars[newIndex++] = chars[i++];
        }
        else
        {
            chars[newIndex++] = chars[i++];
            string strCount = to_string(count);
            for(auto digit : strCount)
            {
                chars[newIndex++] = digit;
            }
        }
        i = j;
    }
    return newIndex;
}
int main()
{
    vector<char>s = {'a','a','b','b','c','c','c','c','c','c','c','c','c','c','c','c','c','c','c','c','c','c','c','c','c','c','c','c','c','d','e'};
    cout << compress2(s) << endl;
}