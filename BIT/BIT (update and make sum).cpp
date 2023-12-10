#include <bits/stdc++.h>
using namespace std;
#define TC int t; cin>>t;while(t--)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
#define nl '\n'
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define ff first
#define ss second
#define debug(x) cout<<#x<<" "<<x<<nl;
const ll sz=2e5+7,Inf=1e9+7;
int N = 10;
int b[20005]= {0};

int sum(int i)
{
    int ans=0;
    for( ; i>0; i-=(i&-i))
    {
        ans+=b[i];
    }
    return ans;
}

void update(int i, int x)
{
    for(; i<=N; i+=(i&-i))
    {
        b[i]+=x;
    }
}
void solve()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        update(i,a[i]);
    }

    int q;
    cin>>q;
    string s;
    while(q--)
    {
        cin>>s;
        if(s=="update")
        {
            int i,x;
            cin>>i>>x;
            update(i,x-a[i]);
            a[i]=x;
        }
        else if(s=="sum")
        {
            int l,r;
            cin>>l>>r;
            cout<<sum(r)-sum(l-1)<<endl;
        }

        else
        {
            cout<<"Invalid"<<endl;
        }
    }

}
int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}
