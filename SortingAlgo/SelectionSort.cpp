#include<iostream>
using namespace std;
int main()
{
    int n = 5;
    int arr[n] = {64,25,12,22,11};
    for(int i=0;i<n-1;i++)
    {
        int MinIndex = i;
        for(int j=i;j<n;j++)
        {
            if(arr[j]<arr[MinIndex])
            {
               MinIndex = j;
            }
        }
        if(arr[i] > arr[MinIndex])
        {
            swap(arr[i],arr[MinIndex]);
        }
    }
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
}
