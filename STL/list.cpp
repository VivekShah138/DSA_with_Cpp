#include<iostream>
#include<list>
using namespace std;
int main()
{

    // All functions are performed like vector just here we can push and pop the element from front as well
    // Implemented as Doubly Linked List and not like dynamic array so here random access is not possible like l[2] will not return any value 

    //intializing list
    list<int>l;
    //pushing elements
    l.push_back(3);
    l.push_front(2);
    l.push_back(4);
    l.push_back(5);
    l.push_front(1);
    //printing the list
    for(int i:l)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    //erasing the elements from list
    l.erase(l.begin());
    //printing the list
    for(int i:l)
    {
        cout<<i<<" ";
    }
    cout << endl;
    //initializing new list with all elements as 500 and size as 10 
    list<int>n(10,500);
    //copying the list n to list a
    list<int>a(n);
    //printing the lists
    for(int i:a)
    {
        cout<<i<<" ";
    }
}