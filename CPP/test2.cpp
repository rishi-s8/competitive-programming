#include <bits/stdc++.h>
 
using namespace std;
 
// Driver program to test above
int main()
{
    int t,t1;
    cin >> t;
    t1=t;
    while(t--)
    {
        string s;
        cin >> s;
        int n;
        n = stoi(s);
        vector<long long> arr(n);
        for(int i=0; i<n; ++i)
        {
            cin >> s;
            arr[i]=stoi(s);
        }
        long long Min=10000000000000000;
        for(int i=0; i<n-1; ++i)
        {
            int ans=arr[i];
            for(int j=i+1; j<n; ++j)
            {
                ans+=arr[j];
                if(ans<Min) Min=ans;
            }
        }
        if(Min<=0)
        //{
        
            cout << "t: " << t1-t << " Smallest sum: " << Min << endl;
        //for(auto z:arr)
           // cout << z << " ";
        //cout << endl;
        //}
    }     
} 
