#include <bits/stdc++.h>
using namespace std;
bool isPrime(int num)
{
    if (num <= 1) return false;  // 0 and 1 are not prime numbers
    for (int i = 2; i*i <= num; i++) {
        if (num % i == 0) return false;  // Found a factor, not prime
    }
    return true;  // No factors found, it's prime
}
bool isSorted(vector<int>& nums)
{
    for(int i=1;i<nums.size();i++)
    {
        if(nums[i] <= nums[i-1])
        {
            return false;
        }
    }
    return true;
}
bool primeSubOperation(vector<int>& nums) 
{
    if(nums.size() == 1) return true;
    if(isSorted(nums)) return true;

    int maxNum = INT32_MIN;
    vector<int>allPrimes;

    for(int i = nums.size()-2; i >= 0; i--)
    {
        if(nums[i] >= nums[i+1])
        {
            for(int j = 0; j < nums[i]; j++)
            {
                int newVal = nums[i]-j;
                if(isPrime(j) && (newVal) < nums[i+1])
                {
                    nums[i] = newVal;
                    break;
                }
            }
        }
    }
    if(isSorted(nums))
    {
        return true;
    }
    return false;
}
// Another Solution
bool primeSubOperation2(vector<int>& nums) 
{
    
    vector<int>primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997};

    int prev = -1;

    for(int i = 0; i < nums.size(); i++)
    {
        int upper = lower_bound(primes.begin(),primes.end(),nums[i]) - primes.begin() - 1;
        int start = 0;
        int end = upper;
        if(start != end)
        {
            while(start <= end)
            {
                int mid = start + (end - start)/2;
                int diff = nums[i] - primes[mid];
                if(diff > prev)
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
            if(start-1 >= 0)
            {
                start = start-1;
            }
        }
        if(nums[i] - primes[start] <= prev)
        {
            return false;
        }
        prev = nums[i] - primes[start];
    }
    return true;
}
int main()
{
    vector<int>arr = {8,11,16,13};
    if(primeSubOperation(arr))
    {
        cout << "True " << endl;
    }
    else
    {
        cout << "False " << endl;
    }
}
