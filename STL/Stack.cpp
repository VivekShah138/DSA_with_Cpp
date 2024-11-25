#include<iostream>
#include<stack>
using namespace std;
int main()
{
    //initializing the stack
    stack<string>s;

    //pushing the elements
    s.push("Rohit");
    s.push("Virat");
    s.push("Dhoni");
    
    //checking the size
    cout<<"size-> "<<s.size() << endl;

    //checking who's on top
    cout<<"Who is on top-> "<<s.top() << endl;

    //poping out
    s.pop();
    cout<<endl;
    
    //checking who's on top
    cout<<"After retirement of Dhoni is on top-> "<<s.top()<<endl;

    //checking whether stack is empty or not
    cout<<"Is future of team dark after retirement-> "<<s.empty()<<endl;

    //checking the size
    cout<<"Size-> "<<s.size() << endl;

    // Printing the stack
    while(!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    // Swap function
    s.push("Rohit");
    s.push("Virat");
    s.push("Dhoni");

    stack<string>s2;

    cout << "s size before swapping --> " << s.size() << " s2 size before swapping --> " << s2.size() << endl;

    s.swap(s2);

    cout << "s size after swapping -->" << s.size() << " s2 size after swapping -->" << s2.size() << endl;
}