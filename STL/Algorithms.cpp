#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
   //initializing the vector
   vector<int>v;

   //pushing the elements
   v.push_back(2);
   v.push_back(10);
   v.push_back(5);
   v.push_back(20);
   v.push_back(40);
   v.push_back(11);

   //printing the elements
   for(auto i:v)
   {
    cout<<i<<" ";
   }
   cout<<endl;

   //Binary search
   cout<<"Finding whether 10 is present or not from range start to end-> "<<binary_search(v.begin(),v.end(),10)<<endl;
   //taking the iterator and doing +2 to it
   vector<int>::iterator it=v.begin();
   it=it+2;
   //Binary search trying with different range
   cout<<"Finding whether 10 is present or not from range 2 to end-> "<<binary_search(it,v.end(),10)<<endl;
   cout<<"Finding whether 20 is present or not from range 2 to end-> "<<binary_search(it,v.end(),20)<<endl;
   cout<<"Finding whether 13 is present or not from range start to end-> "<<binary_search(v.begin(),v.end(),13)<<endl;


   //Rotate
   cout<<"Before Rotating-> "<<endl;
   for(auto i:v)
   {
    cout<<i<<" ";
   }cout<<endl;
   rotate(v.begin(),it,v.end());
   cout<<"After Rotating-> "<<endl;
   for(auto i:v)
   {
    cout<<i<<" ";
   }
   cout<<endl;


   //Sorting
   cout<<"Before Sorting-> "<<endl;
   for(auto i:v)
   {
    cout<<i<<" ";
   }
   cout<<endl;
   cout<<"Is this vector sorted-> "<<is_sorted(v.begin(),v.end())<<endl;
   sort(v.begin(),v.end());
   cout<<"After Sorting-> "<<endl;
   for(auto i:v)
   {
    cout<<i<<" ";
   }
   cout<<endl;
   cout<<"Is this vector sorted-> "<<is_sorted(v.begin(),v.end())<<endl;


   //Min-Max
   int a=10;
   int b=20;
   int maxi=max(a,b);
   int mini=min(a,b);
   cout<<"Max-> "<<maxi<<endl;
   cout<<"Mini-> "<<mini<<endl;
   int c=30;
   int d=40;


   //Swapping
   cout<<"Befor Swapping: "<<endl;
   cout<<"c->"<<c<<endl<<"d-> "<<d<<endl;
   swap(c,d);
   cout<<"After Swapping: "<<endl;
   cout<<"c->"<<c<<endl<<"d-> "<<d<<endl;


   //Reversing
   string name="vivek";
   cout<<"Before Reversing: "<<endl;
   cout<<"String-> "<<name<<endl;
   reverse(name.begin(),name.end());
   cout<<"After Reversing: "<<endl;
   cout<<"String-> "<<name<<endl;


   //Deleting Duplicate elements using unique
   //New_Vector
   vector<int>v2;
   //pushing elements
   v2.push_back(2);
   v2.push_back(2);
   v2.push_back(5);
   v2.push_back(5);
   v2.push_back(7);
   v2.push_back(7);
   //printing elements
   cout<<"Vector: "<<endl;
   for(int i:v2)
   {
      cout<<i<<" ";
   }
   cout<<endl;
   //finding unique elements
   auto last=unique(v2.begin(),v2.end());
   //erasing duplicate elements
   v2.erase(last,v2.end());
   //printing unique elements
   cout<<"Vector after deleting duplicates: "<<endl;
   for(int i:v2)
   {
      cout<<i<<" ";
   }
   cout<<endl;

   //New_Vector
   vector<int>v3;
   //pushing elements
   v3.push_back(2);
   v3.push_back(2);
   v3.push_back(5);
   v3.push_back(5);
   v3.push_back(7);
   v3.push_back(7);
   v3.push_back(2);
   v3.push_back(2);
   v3.push_back(5);
   v3.push_back(5);
   v3.push_back(7);
   v3.push_back(7);
   //printing elements
   cout<<"Vector: "<<endl;
   for(int i:v3)
   {
      cout<<i<<" ";
   }
   cout<<endl;
   //finding unique elements
   auto last2=unique(v3.begin(),v3.end());
   //erasing duplicate elements
   v3.erase(last2,v3.end());
   //printing unique elements
   cout<<"Vector after deleting duplicates: "<<endl;
   for(int i:v3)
   {
      cout<<i<<" ";
   }
   cout<<endl;
   //In this case still there are duplicate elements because unique identifies only adjecent unique elements so there are still unique elements present so we will first sort the vector and then apply the unique command and erase the duplicate one
   sort(v3.begin(),v3.end());
   cout<<"vector after sorting: "<<endl;
   for(int i:v3)
   {
      cout<<i<<" ";
   }
   cout<<endl;
   //Vector is sorted
   //Now apply unique
   auto last3=unique(v3.begin(),v3.end());
   //Now erase
   v3.erase(last3,v3.end());
   cout<<"Vector after deleting duplicates: "<<endl;
   for(int i:v3)
   {
      cout<<i<<" ";
   }
   cout<<endl;
   //You can do it directly as well
   //first sort all the elements and then directly apply unique once and erase the duplicate
   //Like this:
   // //New_Vector
   // vector<int>v3;
   // //pushing elements
   // v3.push_back(2);
   // v3.push_back(2);
   // v3.push_back(5);
   // v3.push_back(5);
   // v3.push_back(7);
   // v3.push_back(7);
   // v3.push_back(2);
   // v3.push_back(2);
   // v3.push_back(5);
   // v3.push_back(5);
   // v3.push_back(7);
   // v3.push_back(7);
   // //printing elements
   // cout<<"Vector: "<<endl;
   // for(int i:v3)
   // {
   //    cout<<i<<" ";
   // }
   // cout<<endl;
   // //sorting the vector
   // sort(v3.begin(),v3.end());
   // cout<<"vector after sorting: "<<endl;
   // for(int i:v3)
   // {
   //    cout<<i<<" ";
   // }
   // cout<<endl;
   // //finding unique elements
   // auto last2=unique(v3.begin(),v3.end());
   // //erasing duplicate elements
   // v3.erase(last2,v3.end());
   // //printing unique elements
   // cout<<"Vector after deleting duplicates: "<<endl;
   // for(int i:v3)
   // {
   //    cout<<i<<" ";
   // }
   // cout<<endl;


   //Lower_Bound & UpperBound

   //For Arrays
   int arr[7]={1,2,3,5,7,8,25};
   cout<<endl;
   int *ptr=lower_bound(arr,arr+7,5);
   cout<<"Lower_Bound for 5-> "<<*ptr<<endl;
   int *ptr2=lower_bound(arr,arr+7,6);
   cout<<"Lower_Bound for 6-> "<<*ptr2<<endl;
   int *ptr3=lower_bound(arr,arr+7,25);
   cout<<"Lower_Bound for 25-> "<<*ptr3<<endl;
   int *ptr4=lower_bound(arr,arr+7,30);
   cout<<"Lower_Bound for 30-> "<<*ptr4<<endl;//in this case it will return any garbage value because it has exceeded the array length
   int *ptr5=upper_bound(arr,arr+7,5);
   cout<<"Upper_Bound for 5-> "<<*ptr5<<endl;
   int *ptr6=upper_bound(arr,arr+7,6);
   cout<<"Upper_Bound for 6-> "<<*ptr6<<endl;
   int *ptr7=upper_bound(arr,arr+7,25);
   cout<<"Upper_Bound for 25-> "<<*ptr7<<endl;//in this case it will return any garbage value because it has exceeded the array length as upperbound gives the next element
   int *ptr8=upper_bound(arr,arr+7,30);
   cout<<"Upper_Bound for 30-> "<<*ptr8<<endl;//in this case it will return any garbage value because it has exceeded the array length as upperbound gives the next element
   int *ptr9=upper_bound(arr+5,arr+7,5);
   cout<<"Upper_Bound for 5 for range(arr+5,arr+7)-> "<<*ptr9<<endl;

   //For Vectors
   vector<int>vect;
   vect.push_back(1);
   vect.push_back(32);
   vect.push_back(64);
   vect.push_back(8);
   vect.push_back(16);
   vect.push_back(2);
   vect.push_back(4);
   sort(vect.begin(),vect.end());
   for (auto i:vect)
   {
      cout<<i<<" ";
   }
   cout<<endl;
   auto it2=lower_bound(vect.begin(),vect.end(),3);
   cout<<"Lower_Bound for 3-> "<<*it2<<endl;
   auto it3=lower_bound(vect.begin(),vect.end(),80);
   cout<<"Lower_Bound for 80-> "<<*it3<<endl;
   auto it4=upper_bound(vect.begin(),vect.end(),16);
   cout<<"Upper_Bound for 16-> "<<*it4<<endl;
   auto it5=upper_bound(vect.begin(),vect.end(),64);
   cout<<"Upper_Bound for 64-> "<<*it5<<endl;
   auto it6=lower_bound(vect.begin(),vect.end(),32);
   cout<<"Lower_Bound for 32-> "<<*it6<<endl;
   cout<<"Lower_Bound Position-> "<<(it6-vect.begin()+1)<<endl;//this will give the position of Lower_Bound
}
