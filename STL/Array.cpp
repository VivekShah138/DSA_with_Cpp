#include<iostream>
#include<array>
using namespace std;
int main()
{
   //Initializing an array
  array<int,10>arr={1,2,3,4,5,6,7,8,9,10};

  //Checking size
  int size=arr.size();

  //printing array
  for(int i=0;i<size;i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;

  //Checking element at particular position
  cout<<"Element at 3rd is- "<<arr.at(3);
  cout<<endl;

  //checking whether array is empty or not
  cout<<"Empty or Not- "<<arr.empty();
  cout<<endl;

  //checking first element
  cout<<"First Element- "<<arr.front();
  cout<<endl;
  
  //checking last element
  cout<<"Last Element- "<<arr.back();
}