#include<bits/stdc++.h>
using namespace std;
vector<int>sieveOfErantosthenes(int num)
{
    vector<bool>isPrime(num+1,true);

    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i*i <= num; i++)
    {
        if(isPrime[i])
        {
            for(int j = i*i; j<= num; j = j+i)
            {
                isPrime[j] = false;
            }
        }
    }

    vector<int>allPrimes;
    for(int i = 0; i <= num; i++)
    {
        if(isPrime[i])
        {
            allPrimes.push_back(i);
        }
    }

    return allPrimes;
}
int main()
{
    int n = 1000;
    for(int i : sieveOfErantosthenes(n))
    {
        cout << i << ",";
    }
}
