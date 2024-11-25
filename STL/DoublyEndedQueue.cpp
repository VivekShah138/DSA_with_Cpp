#include<iostream>
#include<deque>
using namespace std;
int main()
{

    // All functions are performed like list just internally it is implemented as dynamic array so the random access is possible

    //Initialising Deque
    deque<int>d;
    //Entering elements form start and end
    d.push_back(4);
    d.push_back(5);
    d.push_back(6);
    d.push_back(7);
    d.push_front(3);
    d.push_front(2);
    d.push_front(1);
    //printing deque
    for(int i:d)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    //Removing elements from front and end
    d.pop_back();
    d.pop_back();
    d.pop_front();
    //printing deque
    for(int i:d)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    //Checking element at particular position
    cout<<"Element at 1 position-> "<<d.at(1)<<endl;
    //Checking deque empty or not
    cout<<"Empty or Not-> "<<d.empty()<<endl;
    //Checking the first element
    cout<<"Front Element-> " <<d.front()<<endl;
    //Checking the last element
    cout<<"Back Element-> " <<d.back()<<endl;
    //checking size of an deque and erasing element from it from end
    cout<<"size before erasing-> "<<d.size()<<endl;
    cout<<"Erasing from end"<<endl;
    d.erase(d.end(),d.end()+1);//d.end(),d.end()+1 -> This defiens the range of erasing.(d.end(),d.end()+1) range deletes only one element if it was d.end(),d.end()+2 it will delete last two elements
    for(int i:d)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    //Erasing element from it from end
    cout<<"Erasing from front"<<endl;
    d.erase(d.begin(),d.begin()+1);
    for(int i:d)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    //Checking size
    cout<<"size after erasing-> "<<d.size()<<endl;
}