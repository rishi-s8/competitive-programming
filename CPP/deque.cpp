#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long long temp;
    cin >> n;
    multiset<long long> v;
    for(int i=0; i<n; ++i)
    {
        cin >> temp;
        v.insert(temp);
    }
    deque<long long> d;
    d.push_back(*v.begin());
    v.erase(*v.begin());
    while(!v.empty())
    {
        if(v.find((*d.rbegin())*2)!=v.end())
        {
            d.push_back((*d.rbegin())*2);
            v.erase(*d.rbegin());
        }
        if(v.find((*d.begin())*3) != v.end())
        {
            d.push_front((*d.begin())*3);
            v.erase(*d.begin());
        }
        if((*d.begin())%2 == 0)
        {
            
            if(v.find((*d.begin())/2)!=v.end())
            {
                d.push_front((*d.begin())/2);
                v.erase(*d.begin());
            }
        }
        if((*d.rbegin())%2==0)
        {
            
            if(v.find((*d.rbegin())/3)!=v.end())
            {
                d.push_back((*d.rbegin())/3);
                v.erase(*d.rbegin());
            }
        }
    }
    for(auto z:d)
        cout << z << " ";
    cout << endl;
}
