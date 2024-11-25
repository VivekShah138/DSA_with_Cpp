#include<iostream>
#include<map>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    //initializing map
    map<int,string>m;

    //entering elements
    m[13]="Vivek";
    m[7]="MS Dhoni";
    m[18]="Virat";
    m[45]="Rohit";

    //printing elements
    for(auto i:m)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;

    //another way of entering elements
    m.insert({12,"Yuvraj"});

    //printing elements
    for(auto i:m)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;

    //checking whether element is present or not
    cout<<"13 Present hai kya-> "<<m.count(13)<<endl;
    cout<<"Raina Present hai kya-> "<<m.count(3)<<endl;

    //inserting more elements
    m.insert({3,"Raina"});
    m.insert({10,"Sachin"});
    m.insert({44,"Sehwag"});
    m.insert({8,"Jadeja"});

    //printing elements
    for(auto i:m)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;

    //Erasing 
    m.erase(44);
    m.erase(10);

    //printing elements
    for(auto i:m)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;

    //using find command
    auto pos=m.find(13);
    
    //printing all elements ahead of the iterator
    for(auto i=pos;i!=m.end();i++)
    {
      cout<<(*i).first<<" "<<(*i).second<<endl;
    }
    cout<<endl;

    // Storing the count of array in maps
    int arr[10] = {1,1,2,3,4,4,4,5,5,5};

    map<int,int>count;

    for(int i = 0;i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        auto it = count.find(arr[i]);
        if(it == count.end())
        {
            count.insert({arr[i],1});
        }
        else
        {
            it->second++;
        }
    }

    cout << "Print the counts stored in maps of values in arrays " << endl;
    for(auto it : count)
    {
        cout << it.first << " " << it.second << endl;
    }



}