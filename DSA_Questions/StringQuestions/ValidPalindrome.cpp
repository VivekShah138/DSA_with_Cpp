#include<bits/stdc++.h>
using namespace std;

// Coverting to valid string and in lowerCase
string lowercase(string s)
{
    string lowercase;
    for(int i=0;i<s.size();i++)
    {
        if((s[i] <= 90) && (s[i] >= 65))
        {
            s[i] = s[i] + 32;
            lowercase.push_back(s[i]);
        }
        else if((s[i] <= 122 ) && (s[i] >= 97))
        {
            lowercase.push_back(s[i]);
        }
        else if((s[i] <= '9') && (s[i] >= '0'))
        {
            lowercase.push_back(s[i]);
        }
    }
    return lowercase;
}
bool isPalindrome(string s)
{
    s = lowercase(s);
    int start = 0;
    int end = s.size()-1;
    while(start < end)
    {
        if(s[start] != s[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}
int main()
{
    string s = "A man, a plan, a canal: Panama"; // Convert to "amanaplanacanalpanama" and check if its a valid palindrome or not
    
}