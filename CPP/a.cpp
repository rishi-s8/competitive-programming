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

int main()
{ _
    Int n, k;
    cin >> n >> k;
    map<Int, Int> m;
    fl(i,0,n)
    {
        Int temp;
        cin >> temp;
        m[temp]++;
    }
    vl v(m.size(),0);
    int z = m.size()-2;
    for(auto i = m.rbegin(); z>=0; ++i, z--)
    {
        v[z] = v[z+1] + (i->second) * (i->first);
    }
    int i=0;
    for(i; v[i]>k; ++i);
    cout << i << endl;
    
    return 0;
}

bool isPrime(Int a)
{
    for(Int i=2; i*i<=a; ++i) 
        if(a%i==0) return false;
    return true;
}

//Template Credits : Vishal Anand :P For now. ;)
