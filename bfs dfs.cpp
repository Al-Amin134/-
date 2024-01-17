
/*
 بسم الله الرحمن الرحيم

 ♥♥♥♥♥  ♥♥           ♥♥♥♥♥  ♥♥♥    ♥♥♥ ♥♥ ♥♥♥    ♥♥
♥♥   ♥♥ ♥♥          ♥♥   ♥♥ ♥♥♥♥  ♥♥♥♥ ♥♥ ♥♥♥♥   ♥♥
♥♥♥♥♥♥♥ ♥♥   ♥♥♥♥   ♥♥♥♥♥♥♥ ♥♥ ♥♥♥♥ ♥♥ ♥♥ ♥♥ ♥♥  ♥♥
♥♥   ♥♥ ♥♥          ♥♥   ♥♥ ♥♥  ♥♥  ♥♥ ♥♥ ♥♥  ♥♥ ♥♥
♥♥   ♥♥ ♥♥♥♥♥♥♥     ♥♥   ♥♥ ♥♥      ♥♥ ♥♥ ♥♥   ♥♥♥♥
*/
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
const int N= 1e5+11;
vector<int>g[N];
vector<int>vis(N,0);
vector<int>level(N);

void bfs(int source){
   queue<int>q;
   q.push(source);
   vis[source]=1;
   while(!q.empty())
   {
    int cur_v = q.front();
    q.pop();
    for(int child: g[cur_v])
    {
        if(vis[child]==0)
        {
            q.push(child);
            vis[child]=1;
            level[child] = level[cur_v]+1;
        }
    }
   }

}
void dfs(int source)
{
     vis[source] = 1;
    cout<<source<<" ";
   for(int i:g[source])
   {
    //cout<<"parent "<<source<<" child"<<i<<endl;
    if(vis[i]==0)
    dfs(i);
   }
}
int main() {
 int n,m;
 cin>>n;
 for(int i=0;i<n-1;i++)
 {
    int x,y;
    cin>>x>>y;
    g[x].push_back(y);
    g[y].push_back(x);
}
    //bfs(1);
    // cout<<endl;
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<i<<" "<<level[i]<<endl;
    // }

    dfs(1);

}
