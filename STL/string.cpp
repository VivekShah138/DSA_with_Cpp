#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s = "Hello World";

    cout << "using cin to get input of string " << endl;
    char str[100];

    cout << "Enter the string " << endl;
    cin >> str;

    cout << "Output is " << str << endl;


    cout << "x----------------------------------------------x" << endl;

    cout << "using getline to get input of string " << endl;
    char str2[100];

    cout << "Enter the string " << endl;
    cin.getline(str2,100); // Here it uses "\n" (new line) to end the input

    cout << "Output is " << str2 << endl;


    cout << "x----------------------------------------------x" << endl;

    cout << "using getline to get input of string with delimiter" << endl;
    char str3[100];

    cout << "Enter the string " << endl;

    // Here we use delimiter 
    // Delimiter is the character by which we want to end our line 
    cin.getline(str3,100,'.'); // Here it uses "." (full stop) to end the input

    cout << "Output is " << str3 << endl;


    cout << "x----------------------------------------------x" << endl;




    // It will return the index of char in the string
    // size_t pos = s.find('o');
    // cout << pos << endl;

    // It will return the index of char in the string and it will start finding from specified index for e.g. here it is 5
    size_t pos = s.find('o',5);
    cout << pos << endl;

    string s1 = "It's a good night!";

    // It will find the index of starting character i.e. g
    size_t pos1 = s1.find("good");

    // It will find the substring from the specified index and Number of characters in substring , if no Number of characters in substring is specified it will consider the end of orignal string i.e. "!" so sub will give "good night!"
    string sub = s1.substr(pos1);
    cout << sub << endl;

    // It will just give "good"
    string sub1 = s1.substr(pos1,4);
    cout << sub1 << endl;

    string s2 = "03abc";
    string sun2 = s2.substr(0,2);
    // This will convert the string to integer
    int s2Number = stoi(sun2);
    string numberConv = to_string(s2Number);
    cout << s2Number + s2Number << endl;
    cout << numberConv << endl;
    return 0;
}