#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;
    int ans = a-b;
    if(ans%10!=2) ans=(ans/10)*10+2;
    else ans=(ans/10)*10+1;
    cout << ans << endl;
} 
