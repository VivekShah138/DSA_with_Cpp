#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Custom Comparator or Functor for comparing and sorting based on second value of pair
bool comparator(pair<int,int>p1,pair<int,int>p2)
{
    if(p2.second > p1.second) return true;
    else return false;
}

// Custom Comparator or Functor for comparing and sorting based on first value of pair if second value of pair is same
bool comparator2(pair<int,int>p1,pair<int,int>p2)
{
    if(p2.second > p1.second) return true;
    if(p2.second < p1.second) return false;
    if(p1.first < p2.first) return true;
    else return false;
}

int main()
{
    // Creating a vector of pairs
    vector<pair<int,int>>v = {{1,2},{3,4},{5,6},{3,1},{1,1},{2,1}};

    // Printing the values of vector
    for(pair<int,int>p : v) // You can also use for(auto p : v){}
    {
        cout << p.first << " " << p.second << endl;
    }

    // SORTING

    // sort(v.begin(),v.end());

    // cout << "vector after sorting " << endl;

    // // Printing the values of vector
    // for(pair<int,int>p : v) // You can also use for(auto p : v){}
    // {
    //     cout << p.first << " " << p.second << endl;
    // }
    
    // Here the pairs are sorted based on first element in the pair by default
    // If you want to sort it based on second element you have to write a custom comparator
    sort(v.begin(),v.end(),comparator);

    cout << "vector after sorting based on second value " << endl;

    // Printing the values of vector
    for(pair<int,int>p : v) // You can also use for(auto p : v){}
    {
        cout << p.first << " " << p.second << endl;
    }

    // If you want to sort it based on second element but if the second element is same so you have to sort according to first element so you have to write a custom comparator 
    sort(v.begin(),v.end(),comparator2);

    cout << "vector after sorting based based on first value of pair if second value of pair is same " << endl;

    // Printing the values of vector
    for(pair<int,int>p : v) // You can also use for(auto p : v){}
    {
        cout << p.first << " " << p.second << endl;
    }
}