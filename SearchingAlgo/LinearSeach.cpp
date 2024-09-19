#include<bits/stdc++.h>
using namespace std;
int linearSeach(int arr[],int size,int key)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i] == key)
        {
            return i;
        }
    }
    return 0;
}
int main()
{
    int arr[10] = {100,200,300,400,500,600,700,800,900,1000};
    int key;
    cout << "Please Enter the Value to be searched" <<  endl;
    cin >> key;
    int size = sizeof(arr)/sizeof(arr[0]);
    int linearSearchOutput = linearSeach(arr,size,key);
     if(linearSearchOutput == 0)
    {
        cout << "Value not found" << endl;
    }
    else
    {
        cout << "value is present at " << linearSearchOutput << endl;
    }
    
}