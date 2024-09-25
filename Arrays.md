# DSA Array

1. <b>Left Rotation Array/Rotate an Array Anticlockwise</b> <br>
<I>Input</I> : Array = {1,2,3,4,5},k=2 <br>
<I>Output</I> : [3,4,5,1,2] <br>
<I>Input</I> : Array = {3,4,5,1,2},k=2 <br>
<I>Output</I> [5,1,2,3,4]
``` C++
#include<iostream>
using namespace std;
void reversearray(int start,int end,int arr[])
{
    while(start<=end)
    {
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}
void rotatearrayleft(int start,int end,int k,int arr[])
{
    k = k % end;
    reversearray(start,k-1,arr);
    reversearray(k,end-1,arr);
    reversearray(start-1,end,arr);
}
void PrintArray(int n,int arr[])
{
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " " ;
    }
}
int main()
{
    int n = 7;
    int k;
    cin >> k;
    int arr[n] = {1,2,3,4,5,6,7};
    rotatearrayleft(0,n,k,arr);
    PrintArray(n,arr);
}
```

2. <b>Right Rotation Array/Rotate an Array Clockwise</b> <br>
<I>Input</I> : Array = {1,2,3,4,5},k=2 <br>
<I>Output</I>: [4,5,1,2,3] <br>
<I>Input</I> : Array = {4,5,1,2,3},k=2 <br>
<I>Output</I>: [2,3,4,5,1]
``` C++
#include<iostream>
using namespace std;
void reversearray(int start,int end,int arr[])
{
    while(start<=end)
    {
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}
void rotatearrayright(int start,int end,int k,int arr[])
{
    k = k % end;
    reversearray(start-1,end,arr);
    reversearray(start,k-1,arr);
    reversearray(k,end-1,arr);
}
void PrintArray(int n,int arr[])
{
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " " ;
    }
}
int main()
{
    int n = 7;
    int k;
    cin >> k;
    int arr[n] = {1,2,3,4,5,6,7};
    rotatearrayleft(0,n,k,arr);
    PrintArray(n,arr);
}
```

3. <b>Check and remove Number from array.</b><br>
<b>Explanation</b> : check if the given number is present in array or not. If it is present remove it from array  but maintain the same order of array.<br>
<I>Input</I> : arr = [1,2,3,4,5] n = 3<br>
<I>Output</I> : arr = [1,2,4,5]<br>
<I>Input</I> : arr = [1,2,3,4,5] n = 10<br>
<I>Output</I> : Number not present<br>
``` C++
#include<iostream>
using namespace std;
void NewArray(int arr[],int size,int num)
{
    int NewSize = size - 1;
    int arr2[NewSize];
    int s = 0;
    for(int i=0;i<size;i++)
    {
        if(arr[i] != num)
        {
            arr2[s] = arr[i];
            s = s + 1;
        }
    }
    for(int i : arr2)
    {
        cout << i << " ";
    }
}
bool NumberCheck(int arr[],int size,int num)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i] == num)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int n;
    int arr[5] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    cin >> n;
    if(NumberCheck(arr,size,n))
    {
        NewArray(arr,size,n);
    }
    else
    {
        cout << "Number Not Present" << endl;
    }
}
```

4. <b>Find the Second Largest Salary</b><br>
<i>Input</i> : arr = [1000]<br>
<i>Output</i> : No Second Highest Salary Present<br>
<i>Input</i> : arr = [100,200]<br>
<i>Output</i> : 100<br>
<i>Input</i> : arr = [600,400,600,700,700]<br>
<i>Output</i> : 600<br>
<i>Input</i> : arr = [100,200,300,400,500]<br>
<i>Output</i> : 400<br>
<b><u>First Method Without Sets</u></b>
``` C++
int FindSecondLargestSalary(int size,vector<int>Salary)
{
    sort(Salary.begin(),Salary.end());
    for(int i:Salary)
    {
        if(Salary[size-1] == Salary[size-2] && size != 1)
        {

            Salary.pop_back();
            size = Salary.size();
        }
        else if(size > 1)
        {
            return Salary[size-2];
        }
        else
        {
            return -1;
        }
    }
}
int main()
{
    vector<int> Salaray = {600,400,600,700,700};
    int size = Salaray.size();
    int SecondLargestSalary = FindSecondLargestSalary(size,Salaray);
    if(SecondLargestSalary == -1)
    {
        cout << "No Second Largest Salary Present" << endl;
    }
    else
    {
        cout << SecondLargestSalary;
    }
}
```
<b><u>Second Method with Sets</u></b>
``` C++
int FindSecondLargestSalary(int size,vector<int>Salary)
{
    //There are again two ways to copy vector values from vector to set
    //One is using for loop and appending them
    set<int>NoDuplicateSalary;
    for(int i:Salary)
    {
        NoDuplicateSalary.insert(i);
    }

    //Another is creating new set and then adding values from vector using range constructor 
    set<int>NoDuplicateSalary2(Salary.begin(),Salary.end());
    
    //There are two way to copy set values from set to vector 
    //One is using copy method which requires the resizing of vector
    Salary.resize(NoDuplicateSalary.size());
    copy(NoDuplicateSalary.begin(),NoDuplicateSalary.end(),Salary.begin());
    size = Salary.size();

    //Another is creating new vector and then adding values from set using range constructor
    vector<int>NewSalary(NoDuplicateSalary.begin(),NoDuplicateSalary.end());

    sort(Salary.begin(),Salary.end());
    if(size > 1)
    {
        return Salary[size-2];
    }
    else
    {
        return -1;
    }
}
int main()
{
    vector<int> Salaray = {100,100};
    int size = Salaray.size();
    int SecondLargestSalary = FindSecondLargestSalary(size,Salaray);
    if(SecondLargestSalary == -1)
    {
        cout << "No Second Largest Salary Present" << endl;
    }
    else
    {
        cout << SecondLargestSalary;
    }
}
```
<b><u>Third Method with log(n) complexity</u></b>
```C++
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int SecondLargest(int *arr,int size)
{
    int largestsalaray = 0;
    int secondlargest = 0;
    for(int i=0;i<size;i++)
    {
        if(arr[i] > (largestsalaray && secondlargest))
        {
            secondlargest = largestsalaray;
            largestsalaray = arr[i];
        }
        else if((arr[i] < largestsalaray) && (arr[i]) > secondlargest)
        {
            secondlargest = arr[i];
        }
    }
    if((size == 0) || (secondlargest == 0))
    {
        return -1;
    }
    return secondlargest;
}
int main()
{
    int arr[5]={100,200,300,200,100};
    int size = sizeof(arr)/sizeof(arr[0]);
    if(SecondLargest(arr,size) == -1)
    {
        cout << "No Second Largest Salary" << endl;
    }
    else
    {
        cout << "Second Largest Salary is -> " << SecondLargest(arr,size) << endl;
    }
}
```

5. <b>Two Repeated in Array(Imcomplete Solution)</b><br>
<i>Input</i> : array[ ] = {1,2,1,3,4,3} N = 4 <br>
<i>Output</i>: 1 3<br>
<i>Explaination</i> : In the given array, 1 and 3 are repeated two times.<br>
<i>Input</i> : array[ ] = {1,2,2,1} N = 2<br>
<i>Output</i> : 2 1<br>
<i>Explaination</i> :  In the given array,1 and 2 are repeated two times and second occurence of 2 comes before 1. So the output is 2 1.<br>
``` C++
#include<iostream>
#include<vector>
using namespace std;
vector<int>tworepeated(int arr[],int size)
{
    vector<int>tworepeat;
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(arr[i] == arr[j])
            {
                tworepeat.push_back(arr[i]);
            }
        }
    }
    return tworepeat;
}
int main()
{
    int k = 4;
    int arr2[4] = {1,2,2,1};
    int size = sizeof(arr2)/sizeof(arr2[0]);
    vector<int>ans = tworepeated(arr2,size);
    for(int i:ans)
    {
        cout << i << " ";
    }
}
```

6. <b>Find The Max And Min Value in Array</b><br>
<i>Input</i> : arr[ ] = {1,2,3,4,5}, size = 5<br>
<i>Output</i> : Min -> 1, Max -> 5<br>
``` C++
#include<iostream>
using namespace std;
int FindMIN(int arr[],int size)
{
    int min = INT32_MAX;
    for(int i=0;i<size;i++)
    {
        if(arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}
int FindMAX(int arr[],int size)
{
    int max = INT32_MIN;
    for(int i=0;i<size;i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
int main()
{
    int arr[5] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << "Min -> " << FindMIN(arr,size) << endl;
    cout << "Max -> " << FindMAX(arr,size) << endl;
}
```

7. <b>AlternateSwap in Array</b><br>
<i>Input</i> : arr = {1,2,3,4,5,8,7,9,19,10}, size=10<br>
<i>Output</i> : 2 1 4 3 8 5 9 7 10 19 <br>
<i>Input</i> : arr = {1,2,3,4,5} , size=5<br>
<i>Output</i> : 2,1,4,3,5<br>
```C++
#include<iostream>
using namespace std;
void SwapAlternate(int arr[],int size)
{
    if(size % 2 == 0)
    {
        for(int i=0;i<size;i=i+2)
        {
            int j = i + 1;
            swap(arr[i],arr[j]);
        }
    }
    else
    {
        for(int i=0;i<size-1;i=i+2)
        {
            int j = i + 1;
            swap(arr[i],arr[j]);
        }
    }
}
int main()
{
   int arr[10]={1,2,3,4,5,8,7,9,19,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    SwapAlternate(arr,size);
    for(int i:arr)
    {
        cout << i << " ";
    }
}
```

8. <b>Find kth smallest/Largest element</b><br>
<i>Input</i> : arr[ ] = {7,10,4,20,15}, Size=5, k=4<br>
<i>Output</i> : smallest: 15, largest: 7<br>
<i>Explaination</i> : 15 is the 4th smallest number and 7 is the 4th largest number in the given series.<br>
<i>Input</i> : arr[ ] = {7,10,4,3,20,15} Size=6, k=3<br>
<i>Output</i> : smallest: 7, largest: 10<br>
<i>Explaination</i> : 7 is the 3rd smallest number and 10 is the 3rd largest number in the given series.<br>
``` C++
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>RemoveDuplicates(int arr[],int size)
{
    vector<int>NoDuplicates;
    for(int i=0;i<size;i++)
    {
        if((arr[i]^arr[i+1]) != 0)
        {
            NoDuplicates.push_back(arr[i]);
        }
    }
    return NoDuplicates;
}
int kthLargestNumber(int arr[],int size,int k)
{
    sort(arr,arr+size); // You can use any sorting algorithm who's complexity is n*logn
    vector<int>NoDuplicates = RemoveDuplicates(arr,size);
    return NoDuplicates.at(NoDuplicates.size()-k);
}
int kthSmallestNumber(int arr[],int size,int k)
{
    sort(arr,arr+size); // You can use any sorting algorithm who's complexity is n*logn
    vector<int>NoDuplicates = RemoveDuplicates(arr,size);
    return NoDuplicates.at(k-1);
}
int main()
{
    int k;
    cin >> k;
    int arr[10] = {1,2,3,4,5,5,4,3,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    int kthlargest = kthLargestNumber(arr,size,k);
    int kthsmallest = kthSmallestNumber(arr,size,k);
    cout << k <<"th " << " largest element is " << kthlargest << endl;
    cout << k <<"th " << " smallest element is " << kthsmallest << endl;
}
```

9. <b>Find Unique Numbers.</b><br>
<i>Input</i> : [1, 1, 2, 2, 3, 3, 4, 4]<br>
<i>Output</i> : None<br>
<i>Input</i> : [1]<br>
<i>Output</i> : 1<br>
<i>Input</i> : [1, 1, 2, 2, 3, 3, 4, 4, 5]<br>
<i>Output</i> : 5<br>
```C++
#include<iostream>
#include<algorithm>
using namespace std;
int uniquenumber(int arr[],int size)
{
    int ans = 0;
    sort(arr,arr+size);
    for(int i=0;i<size;i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}
int main()
{
    int arr[8] = {1, 1, 2, 2, 3, 3, 4, 4};
    int size = sizeof(arr)/sizeof(arr[0]);
    int unique = uniquenumber(arr,size);
    if(unique == 0)
    {
        cout << "None" << endl;
    }
    else
    {
        cout << "Unique Number in the array is : " << unique << endl;
    }
    
}
```

10. <b>Unique Number of Occurrences(Leetcode/Apple/Google)</b><br>
<i>Explaination</i> : Given an array of integers arr, return true if the number of occurrences of each value in the array is unique, or false otherwise. <br>
<i>Input</i> : arr = [1,2,2,1,1,3],size = 6
<i>Output</i> : True
<i>Input</i> : arr = [1,2],size = 2
<i>Output</i> : False
<i>Input</i> : arr = [-3,0,1,-3,1,1,1,-3,10,0],size = 10
<i>Output</i> : True
```C++
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>FrequencyOfNumbers(int arr[],int size)
{
    sort(arr,arr+size);
    vector<int>count;
    for(int i=0;i<size;)
    {
        int c=0;
        for(int j=i;j<size;j++)
        {
            if(arr[i] == arr[j])
            {
                c++;
            }
        }
        count.push_back(c);
        i = i + c;
    }
    return count;
}
bool Unique(int arr[],int size)
{
   vector<int>Frequency = FrequencyOfNumbers(arr,size);
    int sizeofFrequency = Frequency.size();
    for(int i=0;i<sizeofFrequency;i++)
    {
        for(int j=i+1;j<sizeofFrequency;j++)
        {
            if(Frequency[i] == Frequency[j])
            {
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    int arr[9] = {-3,0,1,-3,1,1,1,-3,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    vector<int>Count = FrequencyOfNumbers(arr,size);
    if(Unique(arr,size) == 1)
    {
        cout << "True " << endl;
    }
    else
    {
        cout << "False " << endl;
    }
}
```
<b><u>Using maps and sets in n complexity</u></b>
```C++
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
map<int,int> FrequencyofNumbers(int arr[],int size)
{
    map<int,int>FrequencyCount;
    for(int i=0;i<size;i++)
    { 
        auto it = FrequencyCount.find(arr[i]);
        if(it == FrequencyCount.end())
        {
            FrequencyCount.insert({arr[i],1});
        }
        else
        {
            it->second++;
        }
    }
    return FrequencyCount;
}
bool Unique(int arr[],int size)
{
    map<int,int> Frequency = FrequencyofNumbers(arr,size);
    set<int>Isunique;
    for(auto i=Frequency.begin();i!=Frequency.end();i++)
    {
        Isunique.insert(i->second);
    }
    if(Isunique.size() == Frequency.size())
    {
        return 1;
    }
    return 0;
}
int main()
{
    int arr[6]={1,2,2,1,1,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    if(Unique(arr,size) == 1)
    {
        cout << "True " << endl;
    }
    else
    {
        cout << "False " << endl;
    }
}
```

11. <b>Sqaure of a sorted an Array(Leetcode)</b><br>
<i>Input</i> : arr[ ] = {1,2,3,4,5},size = 5<br>
<i>Output</i> : 1 4 9 16 25<br>
<i>Input</i> :arr[ ] = {-9,-7,-5,-3,-1,0,2,4,6,8},size = 10<br>
<i>Output</i> : 0 1 4 9 16 25 36 49 64 81<br>
<i>Explaination</i> : You have been given an sorted array in increasing order and you have to return an array with sqaure of each digits in increasing order..Try to achieve it in O(n) complexity.<br>
<b><u>In NlogN Complexity</u></b><br>
```C++
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>SquareOfaSortedArray(int arr[],int size)
{
    vector<int>Sqaure;
    for(int i=0;i<size;i++)
    {
        Sqaure.push_back(arr[i]*arr[i]);
    }
    sort(Sqaure.begin(),Sqaure.end());
    return Sqaure;
}
int main()
{
    int arr[10]={-9,-7,-5,-3,-1,0,2,4,6,8};
    int size = sizeof(arr)/sizeof(arr[0]);
    vector<int>Square = SquareOfaSortedArray(arr,size);
    for(int i:Square)
    {
        cout << i << " ";
    }
}
```
<b><u>In LogN complexity using Two Pointer approach </u><b>
```C++
#include<iostream>
#include<vector>
using namespace std;
void swap(int &a,int &b)
{
    int c = a;
    a = b;
    b = c;
    
}
vector<int>SquareOfaSortedArray(int arr[],int size)
{
    vector<int>Sqaure;
    int negptr;
    int posptr;
    for(int i=0;i<size;i++)
    {
        if(arr[i] >= 0)
        {
            posptr = i;
            break;
        }
        else
        {
            negptr = i;
        }
    }
    while(posptr < size || negptr >= 0)
    {
        if((arr[posptr]*arr[posptr]) < (arr[negptr]*arr[negptr]))
        {
            Sqaure.push_back(arr[posptr]*arr[posptr]);
            posptr++;
        }
        else
        {
            Sqaure.push_back(arr[negptr]*arr[negptr]);
            negptr--;
        }
    }
    return Sqaure;
}
int main()
{
    int arr[10]={-9,-7,-5,-3,-1,0,2,4,6,8};
    int size = sizeof(arr)/sizeof(arr[0]);
    vector<int>Square = SquareOfaSortedArray(arr,size);
    for(int i:Square)
    {
        cout << i << " ";
    }
}
```

12.  <b>Swap the array elements(GFG)</b><br>
<i>Explaination</i> : Given an array arr of n positive integers. The task is to swap every ith element of the array with (i+2)th element.<br>
<i>Input</i> : arr[] = {1 2 3 4 5},size = 5<br>
<i>Output</i> :3 4 5 2 1 <br>
<i>Explaination</i> : Swapping 1 and 3, makes the array 3 2 1 4 5.Now, swapping 2 and 4, makes the array 3 4 1 2 5. Again,swapping 1 and 5, makes the array 3 4 5 2 1.<br>
<i>Input</i> :arr[] = {1 2 3},size = 3<br>
<i>Output</i> : 3 2 1<br>
```C++
#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
    int c = a;
    a = b;
    b = c;
    
}
void swapElements(int arr[], int n)
{
        
    // Your code here
    for(int i=0;i+2<n;i++)
    {
        swap(arr[i],arr[i+2]);
    } 
}
int main()
{
    int arr[5] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i:arr)
    {
        cout << i << " ";
    }
}
```

13. <b>Sort in Specific Order(GFG)</b>><br>
<i>Input</i> : Arr = {1, 2, 3, 5, 4, 7, 10},Size = 7><br>
<i>OutPut</i> : 7 5 3 1 2 4 10><br>
<i>Input</i> :Arr = {0, 4, 5, 3, 7, 2, 1},Size = 7><br>
<i>OutPut</i> : 7 5 3 1 0 2 4><br>
<b><u>Using Vectors</u></b>><br>
```C++
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void SortInSpecificOrder(long long arr[],long long size)
{
    vector<long long>sortIt;
    sort(arr,arr+size);
    for(int i=size-1;i>=0;i--)
    {
        if(arr[i] % 2 != 0)
        {
            sortIt.push_back(arr[i]);
        }
    }
    for(int i=0;i<size;i++)
    {
        if(arr[i] % 2 == 0)
        {
            sortIt.push_back(arr[i]);
        }
    }
    for(int i:sortIt)
    {
        cout << i << " ";
    }
}
int main()
{
    long long arr[10] = {1,2,3,5,4,7,10,0,6,8};
    long long size = sizeof(arr)/sizeof(arr[0]);
    SortInSpecificOrder(arr,size);
}
```
<b><u>Without Vectors and more optimized</u></b>
```C++
void SortInSpecificOrder(long long arr[],long long n)
{
    long long brr[n];
    long long k=0;
    for(int i=0;i<n;i++)
    {
        brr[i] = arr[i];
    }
    long long start = 0;
    long long end = n-1;
    for(int i=0;i<n;i++)
    {
        if(brr[i] % 2 != 0)
        {
            arr[start] = brr[i]; 
            start ++;
        }
        else
        {
            arr[end] = brr[i];
            end --;
        }
    }
    sort(arr,arr+start,greater<int>());
    sort(arr+start,arr+n);
}
int main()
{
    long long arr[10]={1,2,3,5,4,7,10,0,6,8};
    long long size = sizeof(arr)/sizeof(arr[0]);
    SortInSpecificOrder(arr,size);
    for(int i:arr)
    {
        cout << i << " ";
    }
}
```
<b><u>More optimized than previous one</u></b>
```C++
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void SortInSpecificOrder(long long arr[],long long n)
{
    long long start = 0;
    long long end = n-1;
    while(start<=end)
    {
        if(arr[start] % 2 != 0)
        { 
            start ++;
        }
        else
        {
            swap(arr[start],arr[end]);
            end --;
        }
    }
    sort(arr,arr+start,greater<int>());
    sort(arr+start,arr+n);
}
int main()
{
    long long arr[10]={1,2,3,5,4,7,10,0,6,8};
    long long size = sizeof(arr)/sizeof(arr[0]);
    SortInSpecificOrder(arr,size);
    for(int i:arr)
    {
        cout << i << " ";
    }
}
```

14. <b>Sort 01</b><br>
<i>Input</i> : arr={0,1,0,1,1,0,1} size=7<br>
<i>Output</i> : 0 0 0 1 1 1 1 <br>
<i>Input</i> : arr={0,1,0,1,1,0,1,0,0,0} size=10<br>
<i>Output</i> : 0 0 0 0 0 0 1 1 1 1<br>
```C++
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void sort01(int arr[], int n)
{
    int start=0;
    int end=n-1;
    while(start<=end)
    {
        if(arr[start] == 0)
        {
            start++;
        }
        else
        {
            swap(arr[start],arr[end]);
            end--;
        }
    }
}
int main()
{
    int arr[10] = {1,1,1,1,0,0,0,0,1,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    sort01(arr,size);
    for(int i:arr)
    {
        cout << i << " " ;
    }
}
```

15. <b>Sort 012(Three Pointer Approach)</b><br>
<i>Input</i> : arr={0,1,0,1,2,2,2,1,0,1} size=10<br>
<i>Output</i> : 0 0 0 1 1 1 1 <br>
<i>Input</i> : arr={0,1,0,2,1,0,2,2,0,0} size=10<br>
<i>Output</i> : 0 0 0 0 0 1 1 2 2 2<br>
```C++
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void Sort012(int arr[],int size)
{
    int mid=0;
    int start=0;
    int end=size-1;
    while(mid<=end)
    {
        if(arr[mid] == 1)
        {
            mid++;
        }
        else if(arr[mid] == 0)
        {
            swap(arr[start],arr[mid]);
            start++;
            mid++;
        }
        else
        {
            swap(arr[mid],arr[end]);
            end--;
        }
    }
}
int main()
{
    int arr[28]={0,1,2,1,2,1,2,0,1,2,1,2,1,2,0,1,2,1,2,1,2,0,1,2,1,2,1,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    Sort012(arr,size);
    for(int i:arr)
    {
        cout << i << " ";
    }
}
```

16. <b>Union & Intersection Of Two Arrays</b><br>
<i>Input</i> int arr[ ]={12,42},size=2,int brr[ ]={3,4,5,28,37,42,43,46},size2=8<br>
<i>Output</i> Union = {3 4 5 12 28 37 42 43 46} , InterSection = {42} <br>
<i>Input</i> arr1[]={1, 3, 4, 5, 7},size=5,arr2[]={2, 3, 5, 6},size2=4 <br>
<i>Output</i> Union = {1 2 3 4 5 6 7} , Intersection = {3 5} <br>
<b><u>You can use Sets also</u></b><br>
```C++
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>UnionArray(int arr[],int size,int brr[],int size2)
{
    vector<int>Union;
    int i=0;
    int j=0;
    while((i < size) && (j < size2))
    {
        if(arr[i] < brr[j])
        {
            Union.push_back(arr[i]);
            i++;
        }
        else if(arr[i] > brr[j])
        {
            Union.push_back(brr[j]);
            j++;
        }
        else
        {
            Union.push_back(arr[i]);
            i++;
            j++;
        }
    }
    while(i<size)
    {
        Union.push_back(arr[i]);
        i++;
    }
    while(j<size2)
    {
        Union.push_back(brr[j]);
        j++;
    }
    vector<int>Union2;
    for(int k=0;k<Union.size();k++)
    {
        if(Union[k] != Union[k+1])
        {
            Union2.push_back(Union[k]);
            
        }
    }
    return Union2;
}
int Resize(vector<int> Ans) //For Removing Duplicates from vector
{
    int k=0;
    for(int l=0;l<Ans.size();l++)
    {
        if((Ans[l] != Ans[l+1]) && ((l+1) <= Ans.size()))
        {
            Ans[k] = Ans[l];
            k++;
        }
    }
    return k;
}
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>Ans;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int newSize1 = Resize(nums1);
        int newSize2 = Resize(nums2);
        nums1.resize(newSize1);
        nums2.resize(newSize2);
        int i=0;
        int j=0;
        while((i < nums1.size()) && (j < nums2.size()))
        {
            if(nums1[i] == nums2[j])
            {
                Ans.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j])
            {
                i++;
            }
            else if(nums2[j] < nums1[i])
            {
                j++;
            }
        }
        return Ans;
    }
int main()
{
    int arr[5]={1, 3, 4, 5, 7};
    int size = sizeof(arr)/sizeof(arr[0]);
    int brr[4]={2, 3, 5, 6};
    int size2 = sizeof(brr)/sizeof(brr[0]);
    vector<int>Union = UnionArray(arr,size,brr,size2);
    vector<int>Intersection = IntersectionArray(arr,size,brr,size2);
    for(int i:Union)
    {
        cout << i << " ";
    }
    for(int i:Intersection)
    {
        cout << i << " ";
    }
}
```

17. <b>Remove Duplicates from sorted array</b><br>
<i>Explaintion<i/> : Given a sorted array a[] of size n, delete all the duplicated elements from a[] & modify the array such that only distinct elements should be present there.<br>
<i>Input</i> : N = 5,Array = {2, 2, 2, 2, 2}<br>
<i>Output</i> : 1 (Only one element will remain after removing duplicate).<br>
<i>Input</i> : N = 4,Array = {1, 2, 2, 4}<br>
<i>Output</i> : 3<br>
<b><u>With one extra space</u></b>
```C++
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> RemoveDuplicates(int arr[],int size)
{
    vector<int>NoDuplicates;
    for(int i=0;i<size;i++)
    {
        if(arr[i] != arr[i+1])
        {
            NoDuplicates.push_back(arr[i]);
        }
    }
    return NoDuplicates;
}
int main()
{
    int arr[5]={1,2,2,3,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    vector<int>NoDuplicates =  RemoveDuplicates(arr,size);
    for(int i:NoDuplicates)
    {
        cout << i << " ";
    }
}
```
<b><u>With no extra space</u></b>
```C++
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int RemoveDuplicates(int arr[],int size)
{
    int j=0;
    for(int i=0;i<size;i++)
    {
        if((arr[i] != arr[i+1]) && ((i+1) <= size))
        {
            arr[j] = arr[i];
            j++;
        }
    }
    return j;
}
int main()
{
    int arr[5]={1,2,2,3,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    int size2 =  RemoveDuplicates(arr,size);
    for(int i=0;i<size2;i++)
    {
        cout << arr[i] << " ";
    }
}
```

18. <b>Remove Duplicates from unsorted array</b><br>
<i>Explaintion<i/> : Given a sorted array a[] of size n, delete all the duplicated elements from a[] & modify the array such that only distinct elements should be present there.<br>
<i>Input</i> : N = 5,Array = {2, 2, 2, 2, 2}<br>
<i>Output</i> : {2} <br>
<i>Input</i> : N = 4,Array = {1, 2, 2, 4}<br>
<i>Output</i> : {1,2,4}<br>
<b><u>With one extra space</u></b>
```C++
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> RemoveDuplicates(int arr[],int size)
{
    vector<int>NoDuplicateVector;
    map<int,int>NoDuplicateMap;
    for(int i=0;i<size;i++)
    {
        if(NoDuplicateMap.find(arr[i]) == NoDuplicateMap.end())
        {
            NoDuplicateMap[arr[i]]++; // It enteres arr[i] as key and increases it's value by on
            NoDuplicateVector.push_back(arr[i]);
        }
    }
    return NoDuplicateVector;
}
int main()
{
    int arr[5]={1,2,2,3,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    vector<int>NoDuplicates =  RemoveDuplicates(arr,size);
    for(int i:NoDuplicates)
    {
        cout << i << " ";
    }
}
```

19. <b>Maximum Subarray(Kandane's Algorithm)</b> <b><u>VVVIMP</u></b><br>
<i>Explaination</i> : Given an integer array , find the subarray with the largest sum, and return its sum.<br>
<i>Input</i> : nums = [-2,1,-3,4,-1,2,1,-5,4]<br>
<i>Output</i> : 6<br>
<i>Input</i> : nums = [1]<br>
<i>Output</i> : 1<br>
<b><u>This is not solved using kandane Algorithm it is solved using N^2 Complexity.</b></u>
```C++
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int MaxSubArraySum(int arr[],int size)
{
    int FinalSum = INT32_MIN;
    for(int i=0;i<size;i++)
    {
        int sum = 0;
        for(int j=i;j<size;j++)
        {
            sum = sum + arr[j];
            if(sum > FinalSum)
            {
                FinalSum = sum;
            }
        }
    }
    return FinalSum;
}
int main()
{
    int arr[4]={2,6,4,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    int FinalSum = MaxSubArraySum(arr,size);
    cout<<FinalSum;
}
```

20. <b>Find Duplicates in an Array(GFG)</b><br>
<i>Explaination</i> : Given an array a of size N which contains elements from 0 to N-1, you need to find all the elements occurring more than once in the given array. Return the answer in ascending order. If no such element is found, return list containing [-1]. <br>
<i>Input</i> : N = 4,a[] = {0,3,1,2}<br>
<i>Output</i> : -1<br>
<i>Input</i> : N = 5,a[] = {2,3,1,2,3}<br>
<i>Output</i> : 2 3<br>
<b><u>This problem is solved using Ordered maps and vector</u></b> <br> <i>It can also be solve in O(1)space complexity as well as using unordered_maps please find solutions at GFG</i><br>
```C++
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>FindDuplicates(int arr[],int size)
{
    vector<int>Duplicates;
    map<int,int>DuplicatesMaps;
    for(int i=0;i<size;i++)
    {
        auto it = DuplicatesMaps.find(arr[i]);
        if(it == DuplicatesMaps.end())
        {
            DuplicatesMaps.insert({arr[i],1});
        }
        else
        {
            
            it->second++;
        }
    }
    for(auto it=DuplicatesMaps.begin();it != DuplicatesMaps.end();it++)
    {
        int a = it->second;
        int b = it->first;
        if((a) > 1)
        {
            Duplicates.push_back(b);
        }
    }
    if(Duplicates.size() == 0)
    {
        Duplicates.push_back(-1);
    }
    return Duplicates;    
}
int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    vector<int>DuplicatesVector = FindDuplicates(arr,size);
    for(int i:DuplicatesVector)
    {
        cout << i << endl;
    }
}
```
<b><u>With constant space complexity O(1).</u></b>
```C++
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>FindDuplicate(int arr[],int size)
{
    vector<int>Duplicate;
    for(int i=0;i<size;i++)
    {
        int index = abs(arr[i]) - 1;
        if(arr[index] < 0)
        {
            Duplicate.push_back(abs(arr[i]));
        } 
        arr[index] = arr[index] * (-1);
    }
    if(Duplicate.size() == 0)
    {
        Duplicate.push_back(-1);
    }
    return Duplicate;
}
int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    vector<int>Ans = FindDuplicate(arr,size);
    for(auto i:Ans)
    {
        cout << i << " ";
    }
}
```

21. <b>PairSum</b><br>
<i>Explaination</i> : You are given an integer array 'ARR' of size 'N' and an integer 'S'. Your task is to return the list of all pairs of elements such that each sum of elements of each pair equals 'S'. <br>
<i>Input</i> : N=5,Sum=5,Array=1 2 3 4 5<br>
<i>Output</i> : 1 4, 2 3<br>
<i>Input</i> : N=5,Sum=0,Array=2 -3 3 3 -2<br>
<i>Output</i> : -3 3,-3 3,-2 2, <br>
```C++
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> PairSum(int arr[],int size,int sum)
{
    vector<vector<int>> Pairs;
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            
            if((arr[i] + arr[j]) == sum )
            {
                vector<int>temp;
                temp.push_back(arr[i]);
                temp.push_back(arr[j]);
                Pairs.push_back(temp);
            }
           
        }
    }
    sort(Pairs.begin(),Pairs.end());
    return Pairs;
}
int main()
{
    int arr[5]={1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    int sum;
    cin >> sum;
    vector<vector<int>> Pairs = PairSum(arr,size,sum);
    for(auto i:Pairs)
    {
        for(int j=0;j<i.size();j++)
        {
            cout << i[j] << " ";
        }
        cout << endl;
    }
}
```

22. <b>Last duplicate element in a sorted array</b><br>
<i>Explaination</i> : Given a sorted array with duplicate elements and we have to find the index of the last duplicate element and return the index of it and also return the duplicate element.<br>
<i>Input</i> : arr[ ] = {1, 5, 5, 6, 6, 7}, size=6<br>
<i>Output</i> : 4 6 -> Index is 4 and duplicate number is 6;<br>
<i>Input</i> : arr[ ] = {1, 2, 3, 4, 5}, size=5<br>
<i>Output</i> : -1<br>
```C++
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>LastDuplicateElementInASortedArray(int arr[],int size)
{
    int counter = 0;
    int a=0;
    int b=0;
    vector<int>LastDuplicate;
    for(int i=0;i+1<size;i++)
    {
        if(arr[i] == arr[i+1])
        {
            counter++;
            a = i+1;
            b = arr[i+1];
        }
        if((counter>0) && (i+1 == size-1))
        {
            LastDuplicate.push_back(a);
            LastDuplicate.push_back(b);
        }
    }
    if(size == 1  || counter == 0 )
    {
        LastDuplicate.push_back(-1);
    }
    
    return LastDuplicate;
}
int main()
{
    int arr[2]={8,8};
    int size = sizeof(arr)/sizeof(arr[0]);
    vector<int>LastDuplicate = LastDuplicateElementInASortedArray(arr,size);
    for(auto i:LastDuplicate)
    {
        cout << i << " ";
    }
}
```
<b><u>Another method is with less complexity is you can travese array reversely and find teh solution</u></b>
```C++
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>LastDuplicateElementInASortedArray(int arr[],int size)
{
    vector<int>LastDuplicate{-1};
    for(int i=size-1;i>0;i--)
    {
        if(arr[i] == arr[i-1])
        {
            LastDuplicate.pop_back();
            LastDuplicate.push_back(i);
            LastDuplicate.push_back(arr[i]);
            return LastDuplicate;
        }
    }
    return LastDuplicate;
}
int main()
{
    int arr[10]={1,2,3,4,4,5,5,6,6,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    vector<int>LastDuplicate = LastDuplicateElementInASortedArray(arr,size);
    for(auto i:LastDuplicate)
    {
        cout << i << " ";
    }
}
```

23. <b>Merge Two Sorted Array</b><br>
<i>Explaination</i> : Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order without using any extra space. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements. <br>
<i>Input</i> : n = 4, arr1[] = [1 3 5 7], m = 5, arr2[] = [0 2 6 8 9]<br>
<i>Output</i> : arr1[] = [0 1 2 3], arr2[] = [5 6 7 8 9]<br>
<i>Input</i> : n = 2, arr1[] = [10 12], m = 3, arr2[] = [5 18 20]<br>
<i>Output</i> : arr1[] = [5 10], arr2[] = [12 18 20]<br>
```C++
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int n,int arr2[], int m)
{
        int i = n-1;
        int j = 0;
        while((i >= 0) && (j < m))
        {
            if(arr[i] > arr2[j])
            {
                swap(arr[i],arr2[j]);
            }
            i--;
            j++;
        }
        sort(arr,arr+n);
        sort(arr2,arr2+m);
}
int main()
{
    int arr[5]={1,1,1,2,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    int arr2[5]={0,2,4,30,32};
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    merge(arr,size,arr2,size2);
    for(int i:arr)
    {
        cout << i << " ";
    }
    cout << endl;
    for(int i:arr2)
    {
        cout << i << " ";
    }
}
```

24. <b>Move Zeros(Leetcode[283])</b><br>
<i>Explaination</i> : Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.Note that you must do this in-place without making a copy of the array.<br>
<i>Input</i> : nums = [0,1,0,3,12]<br>
<i>Output</i> : [1,3,12,0,0]<br>
<i>Input</i> : nums = [0]<br>
<i>Output</i> : [0]<br>
```C++
void moveZeroes(vector<int>& nums) 
{
    int i=0;
    int j=0;
    while(j<nums.size())
    {
        if(nums[j] == 0)
        {
            j++;
        }
        else if(nums[j] != 0)
        {
            swap(nums[i],nums[j]);
            i++;
            j++;
        }
    }
}
int main()
{
    int arr[7]={0,1,0,1,0,1,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    vector<int>nums = {0,1,0,1,0,1,3};
    moveZeroes(nums);
    for(int i:nums)
    {
        cout << i << " ";
    }
}
```

25. <b>RemoveElement(LeetCode[27])</b><br>
<i><b><u>Explaination</u></b></i> :<br> Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.<br>
Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:<br>
Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.<br>
Return k.<br>
<b><u><i>Input</i></b></u> :<br> nums = [0,1,2,2,3,0,4,2], val = 2 <br>
<b><u><i>Output</i></b></u> :<br> 5, nums = [0,1,4,0,3,_,_,_]<br>
<b><u><i>Input</i></b></u> :<br> nums = [3,2,2,3], val = 3<br>
<b><u><i>Output</i></b></u> :<br> 2, nums = [2,2,_,_]<br>
```C++
int removeElement(vector<int>& nums, int val)
{
    int count=0;
    int i=0;
    int j=0;
    while(j<nums.size())
    {
        if(nums[j] == val)
        {
            j++;
        }
        else if(nums[j] != val)
        {
            swap(nums[i],nums[j]);
            count++;
            i++;
            j++;
        }
    }
    return count;
}
int main()
{
    int val;
    cin >> val;
    vector<int>nums = {0,1,2,2,3,0,4,2};
    cout << removeElement(nums,val);
}
```

26. <b>Check if Array is Sorted and Rotated (1752 Leetcode). </b><br>
<i><b><u>Explaination </i></b></u>: Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.<br>
<u><b><i>Input</i></b></u> : nums = [3,4,5,1,2]<br>
<u><b><i>Output</i></b></u> : True<br>
<u><b><i>Input</i></b></u> : nums = [2,1,3,4]<br>
<u><b><i>Output</i></b></u> : False<br>
<u><b><i>Input</i></b></u> : nums = [1,2,3]<br>
<u><b><i>Output</i></b></u> : True<br>
```C++
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void reverse(vector<int>&nums,int start,int end)
{
    while(start <= end)
    {
        swap(nums[start],nums[end]);
        start++;
        end--;
    }
}
void rotate(vector<int>&nums,int k)
{
    int size =  nums.size();
    reverse(nums,0,k-1);
    reverse(nums,k,size-1);
    reverse(nums,0,size-1);
}
bool ValueK(vector<int>&nums)
{
    int size = nums.size();
    int k = 0;
    for(int i=1;i<size;i++)
    {
        if(nums[i-1] > nums[i])
        {
            k = i;
        }
    }
    rotate(nums,k);
    for(int i=1;i<size;i++)
    {
        if((nums[i-1] > nums[i]))
        {
            return false;
        }
    }
    return true;

}
int main()
{
    vector<int>nums = {7,9,1,1,1,3};
    cout << ValueK(nums);
}
```
<b>Another Solution</b><br>
```C++
bool check(vector<int>& nums) {
        int count=0;
        int size = nums.size();
        for(int i=1;i<size;i++)
        {
            if(nums[i-1] > nums[i])
            {
                count++;
            }
        }
        if(nums[size-1] > nums[0])
        {
            count++;
        }
        if(count <= 1)
        {
            return true;
        }
        return false;
    }

int main()
{
    vector<int>nums = {7,9,1,1,1,3};
    cout << check(nums);
}
```

27. <b>Sum of Arrays (CodeStudios)</b><br>
<i><u><b>Explaination</u></b> : <br>The length of each array is greater than zero.<br>The first index of each array is the most significant digit of the number.For example, if the array A[] = {4, 5, 1}, then the integer represented by this array is 451 and array B[] = {3, 4, 5} so the sum will be 451 + 345 = 796. So you need to return {7, 9, 6}.<br>
Both numbers do not have any leading zeros in them. And subsequently, the sum should not contain any leading zeros.<br></i> 
<i><u><b>Input</b></u></i> : A[] = {4, 5, 1}, B[] = {3, 4, 5}<br>
<i><u><b>Output</b></u></i> : {7, 9, 6}<br>
<i><u><b>Input</b></u></i> : A[] = {1, 2, 3, 4}, B[] = {6}<br>
<i><u><b>Output</b></u></i> : {1, 2, 4, 0}<br>
```C++
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int ArraySum (vector<int>&a, int size)
{
    int sum = 0;
    int n = 0;
    for(int i=0;i<size;i++)
    {
        n = a[i];
        sum = (sum*10) + n;
    }
    return sum;
}
void Reverse(vector<int>&ab,int start,int end)
{
    while(start<=end)
    {
        swap(ab[start],ab[end]);
        start++;
        end--;
    }
}
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	int sum = ArraySum(a,n);
    int sum2 = ArraySum(b,m);
    int finalSum = sum + sum2;
    cout << finalSum << endl;
    int lastinterger = 0;
    vector<int>SumOfArray;
    while(finalSum > 0)
    {
        lastinterger = finalSum % 10;
        SumOfArray.push_back(lastinterger);
        finalSum = finalSum / 10;
    }
    Reverse(SumOfArray,0,SumOfArray.size()-1);
    return SumOfArray;
}
int main()
{
    int arr[5]={2,1,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    vector<int>a = {4,5,1};
    vector<int>b = {3,4,5};
    vector<int>SumOfArray = findArraySum(a,a.size(),b,b.size());
    for(int i:SumOfArray)
    {
        cout << i << " ";
    }
}
```

28. 