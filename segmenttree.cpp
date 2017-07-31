#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll lazy[4*100000], tree[4*100000];
void updateRange(ll node, ll start, ll end, ll l, ll r, ll val)
{
    if(lazy[node] != 0)
    {

        tree[node] += (end - start + 1) * lazy[node];
        if(start != end)
        {
            lazy[node*2+1] += lazy[node];
            lazy[node*2+2] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start > end or start > r or end < l)
        return;
    if(start >= l and end <= r)
    {

        tree[node] += (end - start + 1) * val;
        if(start != end)
        {

            lazy[node*2+1] += val;
            lazy[node*2+2] += val;
        }
        return;
    }
    ll mid = (start + end) / 2;
    updateRange(node*2+1, start, mid, l, r, val);
    updateRange(node*2 + 2, mid + 1, end, l, r, val);
    tree[node] = tree[node*2+1] + tree[node*2+2];
}

ll queryRange(ll node, ll start, ll end, ll l, ll r)
{
    if(start > end or start > r or end < l)
        return 0;
    if(lazy[node] != 0)
    {

        tree[node] += (end - start + 1) * lazy[node];
        if(start != end)
        {
            lazy[node*2+1] += lazy[node];
            lazy[node*2+2] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(start >= l and end <= r)
        return tree[node];
    ll mid = (start + end) / 2;
    ll p1 = queryRange(node*2+1, start, mid, l, r);
    ll p2 = queryRange(node*2 + 2, mid + 1, end, l, r);
    return (p1 + p2);
}
int main()
{
    int t;
    cin>>t;

    while(t--)
    { ll n,m;
        cin>>n>>m;
        memset(tree,0,sizeof(tree));
        memset(lazy,0,sizeof(lazy));
        while(m--){

            ll p,q,c,d;
            ll r;
            int a;
            cin>>a;
            if(a==0)
            {

                cin>>p>>q>>r;
                updateRange(0,0,n-1,p-1,q-1,r);
            }
            else
            {
                cin>>c>>d;
                cout<<queryRange(0,0,n-1,c-1,d-1)<<endl;

            }}


    }
    return 0;
}
