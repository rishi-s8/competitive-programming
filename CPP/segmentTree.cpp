#include <bits/stdc++.h>
using namespace std;

vector<int> tree;
vector<int> v;

int build(int start, int end, int index);
void update(int start, int end, int index, int updInd, int val);
int query(int start, int end, int index, int l, int r);

int main()
{
    tree.assign(1000000, INT_MAX);
    int n, q; cin >> n >> q;
    v.assign(n+1, 0);
    for(int i=1; i<=n; ++i)
        cin >> v[i];
    build(1, n, 1);
    for(int i=0; i<q; ++i)
    {
        char ch; int l, r;
        cin >> ch >> l >> r;
        if(ch=='q') cout << query(1, n, 1, l, r) << endl;
        else update(1, n, 1, l, r);
    }
}


int build(int start, int end, int index)
{
    if(start==end) tree[index]= v[start];
    else
    {
        int mid = (start+end)/2;
        tree[index] = min(build(start, mid, 2*index), build(mid+1, end, 2*index+1));
    }
    return tree[index];
}

void update(int start, int end, int index, int updInd, int val)
{
    if(updInd < start ||  updInd > end) return;
    else if(start == end && start==updInd)
    {
        tree[index]=val;
        v[start]=val;
    }
    else
    {
        int mid = (start+end)/2;
        update(start, mid, 2*index, updInd, val);
        update(mid+1, end, 2*index+1, updInd, val);
        tree[index]= min(tree[2*index], tree[2*index+1]);
    }
}


int query(int start, int end, int index, int l, int r)
{
    if(start>=l && end<=r)
        return tree[index];
    else if(end < l || start>r)
        return INT_MAX;
    else
    {
        int mid = (start+end)/2;
        return min(query(start, mid, 2*index, l, r),query(mid+1, end, 2*index+1, l, r));
    }
}

