#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
  //Initializing a vector
  vector<int>v;

  //Checking capacity
  cout<<"Capacity is->"<<v.capacity()<<endl;

  //Inserting elements
  v.push_back(10);

   //Checking capacity
  cout<<"Capacity is->"<<v.capacity()<<endl;

  //Inserting elements
  v.push_back(20);

   //Checking capacity
  cout<<"Capacity is->"<<v.capacity()<<endl;

  //Inserting elements
  v.push_back(30);

   //Checking capacity
  cout<<"Capacity is->"<<v.capacity()<<endl;

   //Checking size
  cout<<"Size is->"<<v.size()<<endl;

  // Emplace_back also inserts the element at the end of vector
  v.emplace_back(50);

  //Checking element at particular position
  cout<<"Element at 3rd -> "<<v.at(2)<<endl;

  //checking first element
  cout<<"First Element-> "<<v.front()<<endl;

  //checking last element
  cout<<"Last Element-> "<<v.back()<<endl;

  //checking how pop works
  cout<<"before pop"<<endl;
  for(int i:v)
  {
    cout<<i<<" ";
  }
  v.pop_back();
  cout<<"after pop"<<endl;
  for(int i:v)
  {
    cout<<i<<" ";
  }

  //checking how clear works
  cout<<"Before clearing"<<endl;
  cout<<"Capacity is-> "<<v.capacity()<<endl;
  cout<<"Size is->"<<v.size()<<endl;
  v.clear();
  cout<<"After clearing"<<endl;
  cout<<"Capacity is-> "<<v.capacity()<<endl;
  cout<<"Size is-> "<<v.size()<<endl;

  //initialising in new way
  vector<int>a(5,21);
  cout<<"Vector a is "<<endl;
  for(int i:a)
  {
    cout<<i<<" ";
  }
  cout<<endl;
  
  //coping a vector
  vector<int>b(a);
  cout<<"Vector b is "<<endl;
  for(int i:b)
  {
    cout<<i<<" ";
  }
  cout << endl;

  //Erasing From Vector
  vector<int>v2;
  //Entering Vector
  v2.push_back(3);
  v2.push_back(6);
  v2.push_back(1);
  v2.push_back(8);
  v2.push_back(5);
  v2.push_back(10);
  //Printing vector
  cout << "Print the vector v2 " << endl;
  for(int i:v2)
  {
    cout<<i<<" ";
  }
  cout<<endl;

  // FRONT AND BACK
  cout << "vector front element " << v2.front() << endl;
  cout << "vector back element " << v2.back() << endl;

  // ITERATORS
  v2.begin(); // It points to the first element at 0th index of the vector
  v2.end(); // It does point last element of vector but it points to the next position after to last element of vector, So when you deference it, it will give you some garbage value.

  // REVERSE ITERATORS
  v2.rbegin(); // It points to the last element of the vector
  v2.rend(); // It does point first element at 0th index of vector but it points to the position before the first element of vector, So when you deference it, it will give you some garbage value.

  // Printint the v2 vector using vector iterator
  // creating a iterator
  cout << "Printint the v2 vector using vector iterator " << endl;
  vector<int>:: iterator itr;
  for(itr = v2.begin(); itr != v2.end(); itr++)
  {
    cout << *itr << " ";
  }
  cout << endl;

  // Printint the v2 vector using vector REVERSE ITERATORS
  // creating a iterator
  cout << "Printint the v2 vector using vector iterator " << endl;
  vector<int>:: reverse_iterator itr2;
  for(itr2 = v2.rbegin(); itr2 != v2.rend(); itr2++)
  {
    cout << *itr2 << " ";
  }
  cout << endl;


  cout<<"Size-> "<<v2.size()<<endl;
  v2.erase(v2.begin()); //first element of vetcor is deleted
  for(int i:v2)
  {
    cout<<i<<" ";
  }
  cout<<endl;
  cout<<"Size-> "<<v2.size()<<endl;
  v2.erase(v2.begin()+1); //second element is deleted
  for(int i:v2)
  {
    cout<<i<<" ";
  }
  cout<<endl;
  cout<<"Size-> "<<v2.size()<<endl;
  v2.erase(v2.begin()+1,v2.begin()+3);  //deletes all elements from second element to 3 element
  for(int i:v2)
  {
    cout<<i<<" ";
  }
  cout<<endl;
  cout<<"Size-> "<<v2.size()<<endl;
  v2.erase(v2.begin(),v2.end());   // v2.erase[start,end) --> this means start is included but end is not included
  for(int i:v2)
  {
    cout<<i<<" ";
  }
  cout<<endl;
  cout<<"Size-> "<<v2.size()<<endl;

  // CLEAR or EMPTY
  v2.clear(); // Clears the vector it gives size as 0 but it's capacity doesn't changes.
  v2.empty(); // Gives bool value that vector is empty or not.


  //DELETING DUPLICATES FORM AN VECTOR  
   vector<int> v3 = { 1, 2, 3, 3, 3, 10, 1, 2, 3, 7, 7, 8 };
   sort(v3.begin(),v3.end());
   cout << "Sorted vector " << endl;
   for(int i:v3)
   {
    cout << i << " ";
   }
   cout <<  endl;
   vector<int>::iterator it;
   it = unique(v3.begin(),v3.end());
  // Now v becomes {1 2 3 7 8 10 * * * * * *}
  // * means undefined
   cout << "Before deleting duplictes " << endl;
   for(int i:v3)
   {
    cout << i << " ";
   }
   cout <<  endl;
   v3.erase(it,v3.end());
  //// You can also use resize and distance function
  //// Resizing the vector so as to remove the undefined terms
  //v3.resize(distance(v3.begin(), it));
   cout << "After deleting duplictes " << endl;
   for(int i:v3)
   {
    cout << i << " ";
   }
   cout <<  endl;

   //RESIZE AND DISTANCE FUNCTION
   //RESIZE
    vector<int> vec;
    // 5 elements are inserted
    // in the vector
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    cout << "Contents of vector before resizing:" 
         << endl;
    // displaying the contents of the
    // vector before resizing
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
    // vector is resized
    vec.resize(4);
    cout << "Contents of vector after resizing:"<< endl;
    // displaying the contents of the
    // vector after resizing
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout <<  endl ;

    //DISTANCE
    //Returns: The number of elements between first and last.
    vector<int> v4;
    v4.push_back(0);
    v4.push_back(1);
    v4.push_back(2);
    v4.push_back(3);
    v4.push_back(4);
    v4.push_back(5);
    v4.push_back(6);
    v4.push_back(7);
    v4.push_back(8);
    v4.push_back(9);
 
    /*v contains 0 1 2 3 4 5 6 7 8 9*/
 
    vector<int>::iterator firstv4;
    vector<int>::iterator lastv4;
 
    // first pointing to 0
    firstv4 = v4.begin();
 
    // last pointing to 5
    lastv4 = v4.begin() + 5;
 
    // Calculating no. of elements between first and last
    int num = distance(firstv4, lastv4);
 
    // Displaying num
    cout << "Distance:- " << num << endl;

    // OUTPUT: 5
    // Here, total number of elements between first (pointing to 0) and last (pointing to 5) is 5, i.e., 0 1 2 3 4. So element pointed to by last has not been counted by distance(). 

    // LOWER BOUND AND UPPER BOUND
    // Lower bound gives the iterator position which is equal to key if found or greater than key if not found it doesn't give position less than key
    // Upper bound gives the iterator position which is greater to key irrespective if found or not found it doesn't give position less than key
    vector<int>v5 = {1,2,3,4,5,6,7,8,9,10};
    auto lb = lower_bound(v5.begin(),v5.end(),4); // Returns 4
    cout << "Lower Bound is -> " << *lb << endl;
    auto ub = upper_bound(v5.begin(),v5.end(),4); // Returns 5
    cout << "Upper Bound is -> " << *ub << endl;


}