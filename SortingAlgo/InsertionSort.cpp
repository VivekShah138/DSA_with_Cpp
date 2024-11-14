#include<iostream>
#include<vector>
using namespace std;
//RUN THIS FOR BETTER UNDERSTANDING OF CODE
// void InsertionSort(vector<int>&arr , int n)
// {
//     for(int i=1;i<n;i++)
//     {
//         int temp = arr[i];
//         cout << "temp- " << temp << endl;
//         int j=i-1;
//         cout << "j " << j << endl;
//         for(;j>=0;j--)
//         {
//            if(arr[j]>temp)
//            {
//              cout << "entered if " << endl;
//              cout << "Before arr[j+1] = arr[j] " << endl;
//              for(auto i:arr)
//              {
//                 cout << i << " ";
//              }cout << endl;
//              cout << "arr[j+1] " << arr[j+1]  <<" at index " << (j+1) << " arr[j] " << arr[j] <<" at index " << (j) << endl;
//              arr[j+1] = arr[j];
//              cout << "After arr[j+1] = arr[j] " << endl;
//              for(auto i:arr)
//              {
//                 cout << i << " ";
//              }cout << endl;
//              cout << "arr[j+1] " << arr[j+1]  <<" at index " << (j+1) << " arr[j] " << arr[j] <<" at index " << (j) << endl;
//            }
//            else
//            {
//             cout << "Entered else " << endl;
//             break;
//             cout << "break" << endl;
//            }
//         }
//         cout << "Doing arr[j+1] = temp " << endl;
//         arr[j+1] = temp;
//         for(auto i:arr)
//         {
//           cout << i << " ";
//         }cout << endl;
//         cout << "arr[j+1] " << arr[j+1] <<" at index " << (j+1) <<" j index " << (j)<< endl;
//     }
//     cout << "Sorted Array" << endl;
//     for(auto i:arr)
//     {
//         cout << i << " ";
//     }
// }
void InsertionSort(vector<int> &arr,int n)
{
    int i = 1;
    while(i<n)
    {
        int j = i-1;
        int temp = arr[i];
        while(j>=0)
        {
            if(arr[j]>temp)
            {
                arr[j+1] = arr[j];
            }
            else
            {
                break;
            }
            j--;
        }
        arr[j+1] = temp;
        i++;
    }
}
void insertionSort(vector<int>&arr)
{
    int i=1;
    while(i < arr.size())
    {
        int temp = arr[i];
        int j = i-1;
        while(j >= 0 && temp < arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
        i++;
    }
}
void printArray(vector<int>&arr)
{
    cout << "sorted array" << endl;
    for(int i : arr)
    {
        cout << i << " ";
    }
}
int main()
{
   vector<int>v;
   int n,temp;
   cin >> n;
   for(int i=0;i<n;i++)
   {
    cin >> temp ;
    v.push_back(temp);
   }
   InsertionSort(v,n);
   insertionSort(v);

   printArray(v);
}