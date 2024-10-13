#include <bits/stdc++.h>
using namespace std;

string timeConversion(string s)
{
    string hrs = s.substr(0,2);
    size_t pos = s.find(hrs);
    
    
    if(s[8] == 'P')
    {
        size_t  pos2 = s.find('P');
        if(hrs == "01")
        {
            s.replace(pos,2,"13");
        }
        else if (hrs == "02")
        {
            s.replace(pos,2,"14");
        }
        else if (hrs == "03")
        {
            s.replace(pos,2,"15");
        }
        else if (hrs == "04")
        {
            s.replace(pos,2,"16");
        }
        else if (hrs == "05")
        {
            s.replace(pos,2,"17");
        }
        else if (hrs == "06")
        {
            s.replace(pos,2,"18");
        }
        else if (hrs == "07")
        {
            s.replace(pos,2,"19");
        }
        else if (hrs == "08")
        {
            s.replace(pos,2,"20");
        }
        else if (hrs == "09")
        {
            s.replace(pos,2,"21");
        }
        else if (hrs == "10")
        {
            s.replace(pos,2,"22");
        }
        else if (hrs == "11")
        {
            s.replace(pos,2,"23");
        }
        s.erase(pos2,2);
        
    }
    else if(s[8] == 'A')
    {
        size_t  pos2 = s.find('A');
        if(hrs == "12")
        {
            s.replace(pos,2,"00");
        }
        s.erase(pos2,2);
    }
}
string timeConversion2(string s)
{
    string hrs = s.substr(0,2);
    int hours = stoi(hrs);
    string minutes = s.substr(3,2);
    string seconds = s.substr(6,2);
    char format = s[8];

    if(format == 'P' && hours != 12)
    {
        hours+=12;
    }
    else if(format == 'A' && hours == 12)
    {
        hours = 0;
    }
    string hourStr = (hours < 10 ? "0" : "") + to_string(hours);

    return hourStr + ":" + minutes + ":" + seconds;
}
int main()
{
    string s = "12:40:22AM";
    string timeConversionResult = timeConversion2(s);
    cout << timeConversionResult << endl;
}
