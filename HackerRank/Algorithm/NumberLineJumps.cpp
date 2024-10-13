#include<iostream>
using namespace std;

string kangaroo(int x1, int v1, int x2, int v2) 
{
    if(v2 >= v1)
    {
        return "NO";
    }
   int a = (x2 - x1);
   int b = (v1 - v2);
   if(a % b == 0)
   {
        return "YES";
   }
   else 
   {
        return "NO";
   }
}
int main()
{
    int x1,x2,v1,v2;
    x1 = 2;
    x2 = 4;
    v1 = 5;
    v2 = 8;
    cout << kangaroo(x1,x2,v1,v2) << endl;
}