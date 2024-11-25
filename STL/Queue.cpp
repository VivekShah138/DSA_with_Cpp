#include<iostream>
#include<queue>
using namespace std;
int main()
{
    //initializing Queue
    queue<int>q;

    //Pushing Elements
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    //Printing the size
    cout<<"Size-> "<<q.size()<<endl;

    //Printing the queue
    int size=q.size();
    for(int i=0;i<size;i++)
    {
     cout<<q.front()<<" ";
     q.pop();
    }
    cout<<endl;

    cout<<"New Queue:"<<endl;
    //Pushing Elements
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    //Printing the size
    cout<<"Size-> "<<q.size()<<endl;

    //Printing the front element
    cout<<"On Front-> "<<q.front()<<endl;

    //Printing the back element
    cout<<"On Back-> "<<q.back()<<endl;

    //pushing back the element
    q.pop();
    q.pop();

    //Printing the size
    cout<<"Size-> "<<q.size()<<endl;

    //Printing the front element
    cout<<"On Front-> "<<q.front()<<endl;

    //Printing the back element
    cout<<"On Back-> "<<q.back()<<endl;
    int size2=q.size();
    for(int i=0;i<size2;i++)
    {
        cout<<q.front()<<" ";
        q.pop();
    }
}