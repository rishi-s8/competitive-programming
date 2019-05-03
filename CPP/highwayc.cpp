#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        long double s,y;
        cin >> n >> s >> y;
        vector<long double> v(n), d(n), p(n), c(n);
        for(int i=0; i<n; ++i)
            cin >> v[i];

        for(int i=0; i<n; ++i)
            cin >> d[i];

        for(int i=0; i<n; ++i)
            cin >> p[i];
    
        for(int i=0; i<n; ++i)
            cin >> c[i];

        long double time = 0;
        for(int i=0; i<n; ++i)
        {
            long double timePrev=time;
            if(d[i]==0 && p[i]+c[i]+10E-6<0.0 || d[i]==1 && p[i]-c[i]-10E-6>0) time+=y/s;
            else if(d[i]==1 && p[i]<0)
                if(p[i]+y/s*v[i]<-10E-6) time+=y/s;
                else time += (-p[i] + c[i] + 10E-6)/v[i] + y/s; 
            else if(d[i]==0 && p[i]>0)
                if(p[i]-y/s*v[i]>10E-6) time+=y/s;
                else time +=  y/s + (p[i] + c[i] + 10E-6)/v[i]; 
            else if(d[i]==1 && p[i]>=0 && p[i]-c[i]-10E-6<=0) time += -(p[i]-c[i]-10E-6)/v[i] + y/s; 
            else if(d[i]==0 && p[i]<=0 && p[i]+c[i]+10E-6>=0) time += (p[i]+c[i]+10E-6)/v[i] + y/s; 
            for(int j=i+1; j<n; ++j)
                if(d[j]==0) p[j]+=-v[j]*(time-timePrev);
                else p[j]+=v[j]*(time-timePrev);
        }
        cout << fixed << setprecision(6) << time << endl;
    }
}
