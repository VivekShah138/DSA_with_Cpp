#include<iostream>
#include<vector>
using namespace std;
int main()
{
    // It is used for keeping the two values in group. Both values could be of same type or different type as well. Pairs are the part of c++ utility
    
    // Creating a pairs
    pair<int,int>p1 = {1,2};
    pair<char,int>p2 = {'v',23};

    // Accessing the values of pairs
    cout << "First Value of p1 " << p1.first << " Second value of p1 " << p1.second << endl;
    cout << "First Value of p2 " << p2.first << " Second value of p2 " << p2.second << endl;

    // Creating a pair with pair
    pair<int,pair<char,int>>p3 = {1,{'m',22}};
    // Accessing the values of pairs
    cout << "First Value of p3 " << p3.first << endl;
    cout << "First Value of Second value of p3 " << p3.second.first << " Second value of Second value of p3 " << p3.second.second << endl;

    // Creating a vector of pairs
    vector<pair<int,int>>v = {{1,2},{3,4},{5,6}};

    // Printing the values of vector
    for(pair<int,int>p : v) // You can also use for(auto p : v){}
    {
        cout << p.first << " " << p.second << endl;
    }

    // Pushing back value in vector
    v.push_back({4,4});
    cout << "After pushing back value " << endl;
    for(auto p : v) // You can also use for(auto p : v){}
    {
        cout << p.first << " " << p.second << endl;
    }

    v.emplace_back(4,4); // You don't need to create the pair it creates the inplace objects and then inserts but push_back just inserts it assumes that you have created a pair
}