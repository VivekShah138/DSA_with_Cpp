#include<bits/stdc++.h>
using namespace std;
void reverseLetters(string &word)
{
    int start = 0;
    int end = word.length()-1;
    while(start <= end)
    {
        swap(word[start++],word[end--]);
    }
}
string reverseWords(string s) 
{
    string word;
    string reversedLetters;
    int i = 0;
    while(i < s.length())
    {
        
        if((s[i] != ' ' && s[i+1] == ' ') || (s[i] != ' ' && s[i+1] == '\0'))
        {
            word += s[i];
            // reverseLetters(word);
            reverse(word.begin(),word.end());
            reversedLetters += " " + word;
            word.clear();
        }
        else if(s[i] != ' ')
        {
            word += s[i];
        }
        i++;
    }
    reverse(reversedLetters.begin(),reversedLetters.end());
    reversedLetters.erase(reversedLetters.length()-1);
    return reversedLetters;
}
int main()
{
    string s = "     helllooo            world   ";
    cout << reverseWords(s) << endl;
}