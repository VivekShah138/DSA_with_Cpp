#include<bits/stdc++.h>
using namespace std;
long double newProbablity(int N,int P)
{
    long double a = (long double)(N-1) / N;
    long double b = (P/100.0);
    long double newProb = pow(b,a) * 100;
    return newProb - P;
}
int main()
{
    ifstream inputfile("line_by_line_sample_input.txt");
    if(!inputfile)
    {
        cout << "Unable to open the input file" << endl;
        return 1;
    }

    ofstream outputfile("line_by_line_output.txt");
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
        int P;
        inputfile >> N;
        inputfile >> P;
        long double sol = newProbablity(N,P);

        outputfile << "Case " << "#" << t << ": " << (sol) << endl;
    }
    inputfile.close();
    outputfile.close();
}