#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool compareCount(vector<int>& countS1,vector<int>& countWindow)
{
    for(int i = 0; i < 26; i++)
    {
        if(countS1[i] != countWindow[i]) return 0;
    }
    return 1;
}
bool checkInclusion(string s1, string s2) 
{
    // storing the count of all character in s1
    vector<int>countS1(26,0);
    for(int i = 0; i < s1.length(); i++)
    {
        int index = s1[i] - 'a';
        countS1[index]++;
    }

    // storing the count of all character in first window size of s2;
    vector<int>countWindow(26,0);
    int windowSize = s1.length();
    int i = 0;
    while(i < windowSize && i < s2.length())
    {
        int index = s2[i] - 'a';
        countWindow[index]++;
        i++;
    }

    // comparing both count arrays 
    if(compareCount(countS1,countWindow)) return 1;

    // traversing rest of the s2 string and check the permutations in window
    while(i < s2.length())
    {
        char newChar = s2[i];
        int newIndex = newChar - 'a';
        countWindow[newIndex]++;

        char oldChar = s2[i-windowSize];
        int oldIndex = oldChar - 'a';
        countWindow[oldIndex]--;

        if(compareCount(countS1,countWindow)) return 1;
        i++;
    }

    return 0;
}
int main()
{
    string s1 = "ab";
    string s2 = "eidbaoo";
    if(checkInclusion(s1,s2))
    {
        cout << "Permutation Present " << endl;
    }
    else
    {
        cout << "Permutation not Present " << endl;
    }

}