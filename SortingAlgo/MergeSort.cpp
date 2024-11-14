#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void merge(int *arr,int start,int end)
{
    int mid = start + (end-start)/2;

    int len1 = mid - start + 1;
    int len2 = end - mid ;

    // create two different arrays
    int *arr2 = new int[len1];
    int *arr3 = new int [len2];

    // Copy Values
    int MainArrayIndex = start;
    for(int i=0;i<len1;i++)
    {
        arr2[i] = arr[MainArrayIndex];
        MainArrayIndex++;
    } 
    
    MainArrayIndex = mid + 1;
    for(int i=0;i<len2;i++)
    {
        arr3[i] = arr[MainArrayIndex];
        MainArrayIndex++;
    }

    // Merge
    int i = 0;   // Index1
    int j = 0;   // Index2
    MainArrayIndex = start;
    while (i < len1 && j < len2)
    {
        if(arr2[i] < arr3[j])
        {
            arr[MainArrayIndex++] = arr2[i++];
        }
        else if(arr3[j] <= arr2[i])
        {
            arr[MainArrayIndex++] = arr3[j++];
        }
    }
    while(i < len1)
    {
        arr[MainArrayIndex++] = arr2[i++];
    }
    while(j < len2)
    {
        arr[MainArrayIndex++] = arr3[j++];
    }
}
void MergeSort(int *arr,int start,int end)
{
    if(start >= end)
    {
        return;
    }

    int mid = start + (end-start)/2;

    //Sort Left Part
    MergeSort(arr,start,mid);

    //Sort Right Part
    MergeSort(arr,mid+1,end);

    // Merger 
    merge(arr,start,end);
}

int main()
{
    int arr[7] = {11,5,19,17,2,7,3};
    int n = 7;
    MergeSort(arr,0,n-1);
    for(int i:arr)
    {
        cout << i << " ";
    }
}