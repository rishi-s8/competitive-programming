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

vvi dp;
vi a, b;
map<int, pair<int,int> > indices;

Int calculate(int i, int j)
{
    //cout << "i: " << i << "j: " << j << endl;
    if(dp[i][j]!=MOD) return dp[i][j];
    else
    {
        if(i==0)
        {
            if(indices.count(a[j]))
            {
                int index = indices[a[j]].second;
                dp[0][j] = dp[1][index] =  max(calculate(0, j+1) + a[j], calculate(1, index+1) + a[j]);
            }
            else
                dp[0][j] = calculate(0,j+1) + a[j];
        }
        else
        {
            if(indices.count(b[j]))
            {
                int index = indices[b[j]].first;
                dp[1][j] = dp[0][index] = max(calculate(1, j+1) + b[j], calculate(0, index+1) + b[j]);
            }
            else
                dp[1][j] = calculate(1,j+1) + b[j];
        }
    }
    return dp[i][j];
}


int main()
{ _
    int n;
    cin >> n;
    while(n!=0)
    {
        a.clear();
        a.assign(n, 0);
        fl(i,0,n) cin >> a[i];
        int m;
        cin >> m;
        b.clear();
        b.assign(m,0);
        fl(i,0,m) cin >> b[i];
        indices.clear();
        int i=0, j=0;
        for(i; i<n && j<m; ++i)
        {
            while(i<n && a[i]<b[j])
                i++;
            while(i<n && j<m && b[j]<a[i])
                j++;
            if(i<n && j<m && a[i]==b[j]) indices[a[i]] = {i, j};
        }
        
        //for(auto z: indices)
        //{
         //   cout << z.first << " " << z.second.first << " " << z .second.second << endl;
        //}
        Int ans1, ans2;
        dp.clear();
        dp.assign(2, vi(max(n,m)+1, MOD));
        dp[0][n]=0, dp[1][m]=0;
        if(indices.count(a[n-1]) && indices.count(b[m-1]))
        {
          //  cout << "1......" << endl;
            dp[0][n-1] = dp[1][m-1] = a[n-1];
            ans1 = calculate(0,0);
            ans2 = calculate(1,0);
          //  cout << "2......" << endl;
        }
        else if(indices.count(a[n-1])==0 && indices.count(b[m-1]))
        {

          //  cout << "3......" << endl;
            dp[0][n-1] = a[n-1];
            int index = indices[b[m-1]].first;
            Int sum1 = 0;
            while(index<n) sum1+=a[index++];
            dp[1][m-1] = max(b[m-1], sum1);
            ans1 = calculate(0,0);
            ans2 = calculate(1,0);
          //  cout << "4......" << endl;
        }
        else if(indices.count(a[n-1])==0)
        {

          //  cout << "5......" << endl;
            dp[0][n-1] = a[n-1];
            dp[1][m-1] = b[m-1];
            ans1 = calculate(0,0);
          //  cout << "YOLO.." << endl;
            ans2 = calculate(1,0);
          //  cout << "6......" << endl;
        }
        else
        {
          //  cout << "7......" << endl;
            dp[1][m-1] = b[m-1];
            int index = indices[a[n-1]].second;
            Int sum1 = 0;
            while(index<m) sum1+=b[index++];
            dp[0][n-1] = max(a[n-1], sum1);
            ans1 = calculate(0,0);
            ans2 = calculate(1,0);
         //   cout << "8......" << endl;
        }
        
        cout << max(ans1, ans2) << endl;
        cin >> n;
    }
}

bool isPrime(Int a)
{
    for(Int i=2; i*i<=a; ++i) 
        if(a%i==0) return false;
    return true;
}

//Template Credits : Vishal Anand :P For now. ;)
