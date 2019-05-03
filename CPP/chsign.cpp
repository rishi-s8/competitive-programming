#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<long long> v(n);
        for(int i=0; i<n; ++i)
            cin >> v[i];
        
        if(v[1]>v[0])
            v[0]*=-1;
        if(v[n-1]<v[n-2])
            v[n-1]*=-1;
        for(int i=1; i<n-1; ++i)
            if((v[i] < v[i-1]) && (v[i] < v[i+1]))
                v[i]*=-1;

        //for(auto z: v)
          //  cout << z << " " ;
        //cout << endl;
        int k=-1;
        for(int i=0; i<n; ++i)
        {
            if(v[i]<0 && i>k)
            {
                unordered_map<int,long long> dp;
                dp[i-2]=0;
                dp[i]=v[i];
                int j;
                for(j=i+2; j<n; j+=2)
                {
              //      cout << v[j] << " ";
                    if(v[j-2]+v[j-1]+v[j]>0)
                        break;
                    long long val = v[j]+dp[j-4];
                    if(val<dp[j-2]) dp[j]=val;
                    else dp[j]=dp[j-2];
                }
            //    cout << endl;
                j-=2;
                k=j;
                while(j>=i)
                {
                    //cout << dp[j] << " ";
                    if(v[j]<0)
                        if(dp[j]==v[j]+dp[j-4] && j-2>=i) v[j-2]*=-1;
                        else if(j-2>=i) v[j] *= -1;
                    j-=2;
                }
                //cout << endl;
                //for(auto z: v)
                    //cout << z << " " ;
                //cout << endl;
            }
        }
        for(auto z: v)
            cout << z << " " ;
        cout << endl;
    }
        
        
}
