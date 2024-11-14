#include<iostream>
#include<vector>
using namespace std;
// void BubbleSort(vector<int>&arr,int n)
// {
//    for(int i=0;i<n-1;i++) // for round n-1
//    {
//     for(int j=0;j<n-i;j++)
//     {
//         if(arr[j]>arr[j+1] && (j+1) < (n-i))
//         {
//             swap(arr[j],arr[j+1]);
//         }
//         //Or you can also write
//         //for(int j=0;j<n-i-1;j++)
//         // {
//         //     if(arr[j]>arr[j+1])
//         //     {
//         //        swap(arr[j],arr[j+1]);
//         //     }
//         // }
//     }
//    }
//    for(int i:arr)
//    {
//     cout << i << " ";
//    }
// }
//MINOR CHANGE
// void BubbleSort(vector<int>&arr,int n)
// {
//    for(int i=1;i<n;i++) // for round n-1
//    {
//     for(int j=0;j<n-i;j++)
//     {
//         if(arr[j]>arr[j+1])
//         {
//             swap(arr[j],arr[j+1]);
//         }
//     }
//    }
//    for(int i:arr)
//    {
//     cout << i << " ";
//    }
// }
//OPTIMISED CODE
//if the code is already sorted there will be no swapped so if we check that if there were any swaps or not we can optimise our code...so if no swaps were made in sibgle round we can conclude that it is already sorted
void BubbleSort(vector<int>&arr,int n)
{
   for(int i=0;i<n-1;i++) // for round n-1
   {
    bool swapped = false; //assigned it as false means initially in round no swaps are made
    for(int j=0;j<n-i;j++)
    {
        if(arr[j]>arr[j+1] && (j+1) < (n-i))
        {
            swap(arr[j],arr[j+1]);
            swapped = true; //value of bool changes if there is a swap
        }
    }
    if(swapped == false) // check the value of swap and if there is no swap it will break out of loop in this way we have optimised our code
    {
        break;
    }
   }
   for(int i:arr)
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
   BubbleSort(v,n);
}