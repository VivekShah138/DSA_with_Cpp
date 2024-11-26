#include<bits/stdc++.h>
using namespace std;
string removeOccurrences(string s, string part) 
{
    while (s.length() > 0 && s.find(part) < s.length())
    {
        s.erase(s.find(part),part.length());
    } 
    return s;
}
int main()
{
    string s = "daabcbaabcbc";
    string part  = "abc";
    string removedOccurences = removeOccurrences(s,part);
    cout << "String " << s << " after removing all occurences of substring " << part << " is --> " << removedOccurences << endl; 
}