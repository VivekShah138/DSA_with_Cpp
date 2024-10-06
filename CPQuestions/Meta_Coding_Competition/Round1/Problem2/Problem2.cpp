#include<bits/stdc++.h>
using namespace std;
bool isPrime(int num) 
{
    if (num <= 1) return false;  // 0 and 1 are not prime numbers
    for (int i = 2; i*i <= num; i++) {
        if (num % i == 0) return false;  // Found a factor, not prime
    }
    return true;  // No factors found, it's prime
}
int sieve_of_eratosthenes(int max_n) 
{
    vector<int> primes;
    for (int num = 2; num <= max_n; num++) {
        if (isPrime(num)){
            primes.push_back(num);
        }
    }
    
    unordered_set<int>primes_set;
    sort(primes.begin(),primes.end());

    for(int i = primes.size()-1; i >= 1; i--)
    {
        for(int j = i - 1; j >= 0; j--)
        {
            int sub = primes[i] - primes[j];
            if(isPrime(sub))
            {
                primes_set.insert(sub);
            } 
        }
    }
    return primes_set.size();
}
int main() {

    ifstream inputfile("prime_subtractorization_sample_input.txt");
    if (!inputfile) {
        cout << "Unable to open the input file" << endl;
        return 1;
    }

    ofstream outputfile("prime_subtractorization_validation_output.txt");
    if (!outputfile) {
        cout << "Unable to open the output file" << endl;
        return 1;
    }

    int T;
    inputfile >> T;

    // Process each test case and write to output file
    for (int t = 1; t <= T; t++) {
        int N;
        inputfile >> N ;
        // int sol = count_subtractorizations(N, primes);
        // int sol = sieve_of_eratosthenes(N);
        bool sol = isPrime(N);
        outputfile << "Case #" << (t) << ": " << fixed << setprecision(6) << sol << endl;
    }

    inputfile.close();
    outputfile.close();
    return 0;
}