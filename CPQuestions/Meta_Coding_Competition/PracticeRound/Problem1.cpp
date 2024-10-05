#include<bits/stdc++.h>
using namespace std;
// Time Complexity O(N * LogN)
// Space COmplexity O(1)
bool canTravellerCross(int N,long long K,vector<long long>&travelTime)
{
    sort(travelTime.begin(),travelTime.end());
    long long time = 0;
    if(N == 2)
    {
        time = time + travelTime[0];
        if(time <= K)
        {
            return true;
        }
    }
    while(N >= 3)
    {
        time = time + 2 * travelTime[0];
        travelTime.pop_back();
        N--;
    }
    time = time + travelTime[0];
    if(time <= K)
    {
        return true;
    }
    return false;
}
// Time Compleity O(N)
// Space Complexity O(1)
// Explaination
// As long as there are 2 travelers needing to cross, it's optimal to have them go together and incur the lower time between them. Bringing back the wheelbarrow and flashlight should also be done by the fastest person who already crossed so this process can be repeated.
// We might as well designate the fastest of the whole group to be the chauffeur for everyone else, carrying the flashlight and wheelbarrow at all times. They will need N−1.N−1 forward trips to bring the other travelers and N−2 return trips to bring back the flashlight/wheelbarrow, for a total of 2N−3 trips. Thus the answer is YES if and only if the total trip time min(S1..N)∗(2N−3) does not exceed K seconds.
// Note the edge case of N=1, in which case we just check if S1≤K.
bool canTravellerCross2(int N,long long K,vector<long long>&travelTime)
{
    long long minVal = LONG_LONG_MAX;
    long long time = 0;
    if(N == 1)
    {
        return travelTime[0] <= K;
    }
    for(long long i = 0; i < N; i++)
    {
        minVal = min(minVal,travelTime[i]);
    }
    time = minVal * ((2*N) - 3);
    return time <= K;
}
int main()
{
    // Open the Input file
    ifstream inputfile("walk_the_line_input.txt");
    if(!inputfile)
    {
        cout << "Unable to open the input file" << endl;
        return 1;
    }

    ofstream outputfile("walk_the_line_outout.txt");
    if(!outputfile)
    {
        cout << "Unable to open the output file" << endl;
        return 1;
    }

    int T;
    inputfile >> T;

    for(int t = 1; t <= T; t++)
    {
        int N;
        long long K;
        inputfile >> N >> K;

        vector<long long> travelTime(N);

        // for(long long i : travelTime)
        // {
        //     inputfile >> i;
        // }
        for(int i = 0; i < N; i++)
        {
            inputfile >> travelTime[i];
        }

        bool canTravellerCrossSolution = canTravellerCross2(N,K,travelTime);

        outputfile << "Case " << "#" << t << ": " << (canTravellerCrossSolution ? "YES" : "NO") << endl;
        // outputfile << "Case " << "#" << t <<  " "<< canTravellerCrossSolution << endl;
    }

    inputfile.close();
    outputfile.close();
}