#include <iostream>
#include<cstring>
#include <algorithm>
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define pb push_back
#define mk make_pair
using namespace std;
pair<int, pair<int,int> > edges[100100];
int n,m,par[10010];
int root(int v) {return par[v]<0 ? v : (par[v]=root(par[v]));}
void merge (int x,int y)
{
	if((x=root(x)) == (y=root(y))) return;
	if(par[y]<par[x])
		swap(x,y);
	par[x]+=par[y];
	par[y] = x;
}
int main()
{
	long long ans=0;
	memset(par,-1,sizeof(par));
	cin>>n>>m;
	FOR(i,0,m)
	{
		int a,b,w;
		cin>>a>>b>>w;
		edges[i] = mk(w,mk(a,b));
	}
	sort(edges,edges+m);
	FOR(i,0,m)
	{
		int a = edges[i].second.first;
		int b = edges[i].second.second;
		int w = edges[i].first;
		if(root(a) != root(b))
		{
			merge(a,b);
			ans+= w;
		}
	}
	cout<<ans<<endl;
}
