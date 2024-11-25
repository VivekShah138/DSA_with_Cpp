#include<iostream>
#include<queue>
using namespace std;
int main()
{
    //Max_heap initialization
    priority_queue<int>maxi;

    //Min_heap initialization
    priority_queue<int,vector<int>,greater<int>>mini;


    cout<<"Max_Heap "<<endl;

    //Pushing the Element
    maxi.push(10);
    maxi.push(100);
    maxi.push(50);
    maxi.push(500);
    maxi.push(1000);
    maxi.push(1);

    //Priniting the Size
    cout<<"Size of queue-> "<<maxi.size()<<endl;
    int size=maxi.size();

    //printing the Priority Queue
    for(int i=0;i<size;i++)
    {
        cout<<maxi.top()<<" ";
        maxi.pop();
    }
    cout<<endl;
    //checking whether it is empty or not
    cout<<"Khali hai kya bhai-> "<<maxi.empty()<<endl;
    cout<<endl;


    //Min_Heap
    cout<<"Min_Heap "<<endl;
    //Pushing the Element
    mini.push(11);
    mini.push(101);
    mini.push(51);
    mini.push(501);
    mini.push(1001);
    mini.push(1);

    //Priniting the Size
    cout<<"Size of queue-> "<<mini.size()<<endl;
    int size2=mini.size();

    //printing the Priority Queue
    for(int i=0;i<size2;i++)
    {
        cout<<mini.top()<<" ";
        mini.pop();
    }
    cout<<endl;

    //checking whether it is empty or not
    cout<<"Khali hai kya bhai-> "<<maxi.empty()<<endl;

    //Another Method Of initializing and priting min_heap
    int arr[]={10,20,30,40,25,35,45,15,50,55};//initializing array
    int n=sizeof(arr)/sizeof(arr[0]);//taking out size of an array
    priority_queue<int>mini2;//Initalizing the queue which has default returning of max_heap
    for(int i=0;i<n;i++)
    {
        mini2.push((-1)*arr[i]);
    }
    //so we have pushed it multiply by -1 to each elements of array.So max value will become min value e.g- element1=50 ->(-1)*50 ->-50;element1=5 ->(-1)*5 ->-5.So greatest value has become smallest ans smallest has now become greatest
    for(int i=0;i<n;i++)
    {
        cout<<mini2.top()*(-1)<<" ";
        mini2.pop();
    }
    //here we are poping by multiplying again with (-1).So 5 will be returned as it is 
    //Logic Again
    //Element-> 5,50
    //Entered in queue by multiply by (-1)
    //So -5,-50 is stored in queue now default priority queue will return max_heap so here greatest is -5 so first -5 is poped and in return we are multiply by(-1) so it becomes 5

    //checking whether it is empty or not
    cout<<"Khali hai kya bhai-> "<<maxi.empty()<<endl;
}