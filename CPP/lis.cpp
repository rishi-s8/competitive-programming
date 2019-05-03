/*
 * RISHI SHARMA
 * silentEagle
 * rishi_kamand
 * rishi-s8
 * rishi_s8
 */

#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef long long Int;
#define fl(i,x,y) for(int i=x; i<y; i++)
#define vi vector<int>
#define vvi vector< vi >
#define vl vector<Int>
#define vvl vector< vl >
#define si_d set<int, greater<int> >
#define sl_d set<Int, greater<Int> >
#define mii map<int,int>
#define mll map<Int,Int>
#define pb push_back
#define sortAsc(v) sort(v.begin(),v.end())
#define sortDesc(v) sort(v.rbegin(),v.rend())
#define F first
#define S second
#define foreach(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define getMax(v) *(max_element(v.begin(), v.end()))
#define getMin(v) *(min_element(v.begin(), v.end()))
Int MOD = 1000000007;
Int min(Int a, Int b){return (a<b?a:b);}
Int max(Int a, Int b){return (a>b?a:b);}
bool isPrime(Int a);

vi dp;
vi a;
vi parent;

int lis(int i)
{
    if(i==0) return 1;
    else if(dp[i]!=-1) return dp[i];
    else
    {
        int Max = 1;
        for(int j = 0; j<i; ++j)
        {
            if(a[j] < a[i])
            {
                int cur = lis(j) + 1;
                if(cur > Max)
                {
                    Max = cur;
                    parent[i]=j;
                }
            }
            else
                lis(j);
        }
        dp[i] = max(Max, dp[i]);
        return dp[i];
    }
}

void printSol()
{
    int q = max_element(dp.begin(), dp.end()) - dp.begin();
    stack<int> s;
    while(q!=-1)
    {
        s.push(q);
        q=parent[q];
    }
    while(!s.empty())
    {
        cout << a[s.top()] << " ";
        s.pop();
    }
    cout << endl;

}


int main()
{ _
    int n;
    cin >> n;
    a.assign(n, 0);
    fl(i,0,n) cin >> a[i];
    dp.assign(n, -1);
    parent.assign(n, -1);
    dp[0] = 1;
    lis(n-1);
    cout << getMax(dp) << endl;
    //printSol();
}

bool isPrime(Int a)
{
    for(Int i=2; i*i<=a; ++i) 
        if(a%i==0) return false;
    return true;
}

//Template Credits : Vishal Anand :P For now. ;)
