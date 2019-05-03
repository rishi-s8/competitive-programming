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

vvi circles;
int k = 1000001;
vi prefix(k, 0);

int getMaxDistance(vi &a, vi &b)
{
    Int xDist = a[0] - b[0], yDist = a[1]-b[1];
    int d = sqrtl(xDist*xDist+yDist*yDist);
    return (int)d + a[2] + b[2];
}

int getMinDistance(vi &a, vi &b)
{
    Int xDist = a[0] - b[0], yDist = a[1]-b[1];
    Int d = sqrtl(xDist*xDist+yDist*yDist);
    int finalDistance = (d*d<xDist*xDist + yDist*yDist) ? (int)d+1 : (int)d;
    if(d>=a[2]+b[2])
        return finalDistance - (a[2] + b[2]);
    else if(a[2]>=d+b[2])
        return a[2]-b[2] - (int)d;
    else if(b[2] >= d + a[2])
        return b[2]-a[2] - (int)d;
    else return 0;
}

void calculateDistances()
{
    int n = circles.size();
    fl(i,0,n)
    {
        fl(j, i+1, n)
        {
            int m = getMinDistance(circles[i], circles[j]), M = getMaxDistance(circles[i], circles[j]);
            prefix[m]++, prefix[M+1]--;
        }
    }
    fl(i,1, k)
        prefix[i] = prefix[i-1] + prefix[i];
}

int main()
{ _
    int n, q;
    cin >> n >> q;
    circles.assign(n, vi());
    vi temp(3);
    fl(i,0,n)
    {
        cin >> temp[0] >> temp[1] >> temp[2];
        circles[i]=(temp);
    }
    calculateDistances();
    int t;
    while(q--)
    {
        cin >> t;
        cout << prefix[t] << endl;
    }

}

bool isPrime(Int a)
{
    for(Int i=2; i*i<=a; ++i) 
        if(a%i==0) return false;
    return true;
}

//Template Credits : Vishal Anand :P For now. ;)
