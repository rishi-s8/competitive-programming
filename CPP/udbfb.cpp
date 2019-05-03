#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n;
    cin >> m >> n;
    vector<int> a(m), b(m);
    for(int i=0; i<m; ++i)
        cin >> a[i];

    for(int i=0; i<m; ++i)
        cin >> b[i];

    int result = 0;
    for(auto x:a)
    {
        for(auto y:b)
        {
            vector<int> fib(100);
            fib[1]=x;
            fib[2]=y;
            for(int k=3; k<=n; ++k)
                fib[k]=fib[k-1]+fib[k-2];
            result+=fib[n];
        }
    }

    cout << result << endl;
}

