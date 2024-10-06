#include<bits/stdc++.h>
using namespace std;
double speedRequired(int N,vector<pair<int,int>>&deliveryWindow)
{

    double maxRequiredSpeed = INT32_MIN;
    double minRequiredSpeed = INT32_MAX;
    for(int i = 1; i <= N; i++)
    {
        int A = deliveryWindow[i-1].first;
        int B = deliveryWindow[i-1].second;

        double maxSpeedForStation = (double)i / A ; 
        double minSpeedForStation = (double)i / B;

        maxRequiredSpeed = max(maxRequiredSpeed,minSpeedForStation);
        minRequiredSpeed = min(minRequiredSpeed,maxSpeedForStation);
    }
    if(maxRequiredSpeed <= minRequiredSpeed) 
    {
        return maxRequiredSpeed;
    }
    else
    {
        return -1;
    }
}
int main()
{
    ifstream inputfile("subsonic_subway_final_input.txt");
    if(!inputfile)
    {
        cout << "Unable to open the input file" << endl;
        return 1;
    }

    ofstream outputfile("subsonic_subway_final_output.txt");
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
        inputfile >> N;

        vector<pair<int,int>>deliveryWindow(N);
        for(int i = 0; i < N; i++)
        {
            inputfile >> deliveryWindow[i].first >> deliveryWindow[i].second;
        }
        double sol = speedRequired(N,deliveryWindow);

        outputfile << "Case " << "#" << t << ": " << fixed << setprecision(6) << (sol) << endl;
    }
    inputfile.close();
    outputfile.close();
}