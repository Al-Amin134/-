#include<bits/stdc++.h>
using namespace std;
#define mx 100001
int arr[mx]= {0};
int tree[mx*3];
void init(int node, int b, int e)
{
    if(b==e)
    {
        tree[node]=arr[b];
        return;
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=tree[left]+tree[right];

}

int query(int node, int b, int e, int i, int j)
{
    if(i>e||j<b)
        return 0;
    if(i<=b&&j>=e)
    {
        return tree[node];
    }
    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    int p1 = query(left, b, mid, i,j);
    int p2 = query(right, mid+1, e, i, j);
    return p1+p2;
}

void update(int node, int b, int e, int i, int new_value)
{
    if(i>e||i<b)
        return ;
    if(i<=b&&i>=e)
    {
        tree[node] = new_value;
        return ;
    }

    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;
    update(left, b, mid, i, new_value);
    update(right,mid+1, e, i, new_value);
    tree[node]=tree[left]+tree[right];

}

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>arr[i];
    }
    init(1,1,n);

    cout<< query(1,1,n,3,7)<<endl;
    update(1,1,n,5,10);
    cout<<query(1,1,n,3,7)<<endl;

    // for(int i=0;i<=n*3;i++){
    //     cout<<tree[i]<<" ";
    // }
    return 0;
}
