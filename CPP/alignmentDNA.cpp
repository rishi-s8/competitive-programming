#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > dp;
vector< vector <int> > misMatchPenalty;
int gapPenalty;
string s1, s2;

int getIndex(char ch)
{
    switch(ch)
    {
        case 'A':
            return 0;
        case 'T':
            return 1;
        case 'G': 
            return 2;
        case 'C':
            return 3;
    }
    return 5;
}


void alignmentHelper(int m, int n)
{
    for(int i=1; i<=m; ++i)
    {
        for(int j=1; j<=n; ++j)
        {
            int misMatchCost = misMatchPenalty[getIndex(s1[i])][getIndex(s2[j])];
            dp[i][j] = min(dp[i-1][j-1]+misMatchCost, min(dp[i][j-1]+gapPenalty, dp[i-1][j]+gapPenalty));
        }
    }
}

void alignment(int m, int n)
{
    dp.assign(m+1, vector<int>(n+1, 0));
    dp[0][0] = 0;
    for(int i=1; i<=m; ++i)
        dp[i][0] = gapPenalty*i;
    for(int j=1; j<=n; ++j)
        dp[0][j] = gapPenalty*j;
    alignmentHelper(m, n);
    cout <<"Cost: " <<  dp[m][n] << endl;
    for(auto z: dp)
    {
        for(auto y: z)
            cout << y << " ";
        cout << endl;
    }
    stack<char> s3, s4;
    int i=m, j=n;
    while(i!=0 && j!=0)
    {
        cout << "i: " << i << " j: " << j << " s1[i]: " << s1[i] << " s2[j]: " << s2[j] << endl;
        int misMatchCost = misMatchPenalty[getIndex(s1[i])][getIndex(s2[j])];
        if(dp[i][j] == dp[i-1][j-1] + misMatchCost)
        {
            cout << "diagonal..: penalty: " << misMatchCost << endl;
            s3.push(s1[i--]), s4.push(s2[j--]);
        }
        else if(dp[i][j] == dp[i][j-1] + gapPenalty)
        {
            cout << "from left: penalty: " << gapPenalty << endl; 
            s3.push('-'), s4.push(s2[j]);
            j--;
        }
        else
        {
            cout << "from down: penalty: " << gapPenalty << endl;
            s3.push(s1[i]), s4.push('-');
            i--;
        }
    }
    while(i!=0)
    {
        s3.push(s1[i]);
        s4.push('-');
        i--;
    }
    while(j!=0)
    {
        s4.push(s2[j]);
        s3.push('-');
        j--;
    }
    while(!s3.empty())
    {
        cout << s3.top();
        s3.pop();
    }
    cout << endl;
    while(!s4.empty())
    {
        cout << s4.top();
        s4.pop();
    }
    cout << endl;

}



int main(int argc, char *argv[])
{
    misMatchPenalty.assign(5, vector<int>(5));
    int argument = atoi(argv[1]);
    for(int i=0; i<5; ++i)
        for(int j=0; j<5; ++j)
            if(i==j) misMatchPenalty[i][j]=0;
            else misMatchPenalty[i][j] = (argument==1) ? 4 : 6;
    cin >> s1 >> s2;
    int m = s1.size(), n = s2.size();
    s1 = " " + s1;
    s2 = " " + s2;
    gapPenalty = (argument == 1) ? 6 : 4;
    alignment(m, n);
}
