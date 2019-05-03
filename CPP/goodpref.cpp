#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{   _
    int t, k;
    cin >> t;
    while(t--)
    {
        long long count=0, temp;
        string s;
        cin >> s >> k;
        int ar[s.size()+1];
        if(s[0]=='a') ar[0]=1;
        else ar[0]=-1;
        int len = s.size();
        for(int i=1; i<len; ++i)
            if(s[i]=='a') ar[i]=ar[i-1]+1;
            else ar[i]=ar[i-1]-1;
        if(ar[len-1]==0)
        {
            int a=0, b=0;
            for(auto z: s)
            {
                if(z=='a') ++a;
                else ++b;
                if(a>b) ++count;
            }
            count*=k;
        }
        else if(ar[len-1]>0)
        {
            for(int i=0; i<len; ++i)
            {
                if(ar[i]>0) ar[i]=k;
                else 
                {
                    temp=k-1+ar[i]/ar[len-1];
                    if(temp>0) ar[i]=temp;
                    else ar[i]=0;
                }
                count+=ar[i];
            }
        }
        else
        {
            for(int i=0; i<len; ++i)
            {
                if(ar[i]<=0) ar[i]=0;
                else if(ar[i]%ar[len-1]==0) 
                {
                    temp=-ar[i]/ar[len-1];
                    if(temp<k) ar[i]=temp;
                    else ar[i]=k;
                }
                else
                {
                    temp = 1-ar[i]/ar[len-1];
                    if(temp<k) ar[i]=temp;
                    else ar[i]=k;
                }
                count+=ar[i];
            }
        }
        cout << count << endl;
    }
    return 0;
}
