#include<iostream>
#include<set>
using namespace std;
int main()
{
    //initializing set
    set<int>s;

    //inserting value
    s.insert(5);
    s.insert(20);
    s.insert(15);
    s.insert(10);
    s.insert(30);
    s.insert(25);
    s.insert(5);
    s.insert(20);
    s.insert(15);
    s.insert(10);
    s.insert(30);
    s.insert(25);
    s.insert(5);
    s.insert(20);
    s.insert(15);
    s.insert(10);
    s.insert(30);
    s.insert(25);
    int size=s.size();
    cout<<"Size-> "<<size<<endl;

    //printing set
    for(int i:s)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    //erasing value
    s.erase(s.begin());//here we have specified that erase the begining element i.e is 5
    for(int i:s)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    //taking iterator
    set<int>::iterator IT=s.begin();
    IT++;//here we have done IT++ so the value that will be deleted is s.begin()+1 value i.e is 15
    s.erase(IT);
    for(int i:s)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    //count will tell that element is present of not in the set
    cout<<"10 is present hai ki nai-> "<<s.count(10)<<endl;
    cout<<"30 is present hai ki nai-> "<<s.count(30)<<endl;
    cout<<"1 is present hai ki nai-> "<<s.count(1)<<endl;
    cout<<"12 is present hai ki nai-> "<<s.count(12)<<endl;

    //find will find the iterator of the value and then we can print all the values ahead if that iterator value
    auto pos = s.find(20);

    //printng all the values ahead of iterator
    //auto is used for type deduction in cpp so if the value is integer it will be used as integer and if the value if char it will used as character
    for(auto i=pos;i!=s.end();i++)
    {
      cout<<*i<<" ";
    }
    cout<<endl;
}