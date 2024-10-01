#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
// N square Time complexity
int maxProfit(vector<int>&prices)
{
    int profit = 0;
    for(int i = 1; i < prices.size(); i++)
    {
        for(int j = i-1; j >= 0; j--)
        {
            int currentProfit = prices[i] - prices[j];
            profit =  max(currentProfit,profit);
        }
    }
    return profit;
}
// N Time Complexity
int maxProfit2(vector<int>&prices)
{
    int profit = 0;
    int bestBuy = prices[0];
    for(int i = 1; i < prices.size(); i++)
    {
       if(prices[i] > bestBuy)
       {    
            profit = max(profit,prices[i]-bestBuy);
       }
       bestBuy = min(bestBuy,prices[i]);
    }
    return profit;
}
int main()
{
    vector<int>arr = {3,2,6,5,0,3};
    int maxProfitSolution = maxProfit2(arr);
    cout << maxProfitSolution << endl;
}